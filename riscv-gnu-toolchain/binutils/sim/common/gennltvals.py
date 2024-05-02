#!/usr/bin/env python3
# Copyright (C) 1996-2023 Free Software Foundation, Inc.
#
# This file is part of the GNU simulators.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

"""Helper to generate target-newlib-* files.

target-newlib-* are files that describe various newlib/libgloss values used
by the host/target interface.  This needs to be rerun whenever the newlib source
changes.  Developers manually run it.

If the path to newlib is not specified, it will be searched for in:
- the root of this source tree
- alongside this source tree
"""

import argparse
from pathlib import Path
import re
import subprocess
import sys
from typing import Iterable, List, TextIO


PROG = Path(__file__).name

# Unfortunately, many newlib/libgloss ports have seen fit to define their own
# syscall.h file.  This means that system call numbers can vary for each port.
# Support for all this crud is kept here, rather than trying to get too fancy.
# If you want to try to improve this, please do, but don't break anything.
#
# If a target isn't listed here, it gets the standard syscall.h file (see
# libgloss/syscall.h) which hopefully new targets will use.
#
# NB: New ports should use libgloss, not newlib.
TARGET_DIRS = {
    'cr16': 'libgloss/cr16/sys',
    'd10v': 'newlib/libc/sys/d10v/sys',
    # Port removed from the tree years ago.
    #'i960': 'libgloss/i960',
    'mcore': 'libgloss/mcore',
    'riscv': 'libgloss/riscv/machine',
    'sh': 'newlib/libc/sys/sh/sys',
    'v850': 'libgloss/v850/sys',
}


# The header for the generated def file.
FILE_HEADER = f"""\
/* Newlib/libgloss macro values needed by remote target support.  */
/* This file is machine generated by {PROG}.  */\
"""

# Used to update sections of files.
START_MARKER = 'gennltvals: START'
END_MARKER = 'gennltvals: END'


def extract_syms(cpp: str, srcdir: Path,
                 headers: Iterable[str],
                 pattern: str,
                 filter: str = r'^$') -> dict:
    """Extract all the symbols from |headers| matching |pattern| using |cpp|."""
    srcfile = ''.join(f'#include <{x}>\n' for x in headers)
    syms = set()
    define_pattern = re.compile(r'^#\s*define\s+(' + pattern + ')')
    filter_pattern = re.compile(filter)
    for header in headers:
        with open(srcdir / header, 'r', encoding='utf-8') as fp:
            data = fp.read()
        for line in data.splitlines():
            m = define_pattern.match(line)
            if m and not filter_pattern.search(line):
                syms.add(m.group(1))
    for sym in syms:
        srcfile += f'#ifdef {sym}\nDEFVAL "{sym}" {sym}\n#endif\n'

    result = subprocess.run(
        f'{cpp} -E -I"{srcdir}" -', shell=True, check=True, encoding='utf-8',
        input=srcfile, capture_output=True)
    ret = {}
    for line in result.stdout.splitlines():
        if line.startswith('DEFVAL '):
            _, sym, val = line.split()
            ret[sym.strip('"')] = val
    return ret


def gentvals(output_dir: Path,
             cpp: str, srctype: str, srcdir: Path,
             headers: Iterable[str],
             pattern: str,
             filter: str = r'^$',
             target: str = None):
    """Extract constants from the specified files using a regular expression.

    We'll run things through the preprocessor.
    """
    headers = tuple(headers)

    # Require all files exist in order to regenerate properly.
    for header in headers:
        fullpath = srcdir / header
        assert fullpath.exists(), f'{fullpath} does not exist'

    syms = extract_syms(cpp, srcdir, headers, pattern, filter)

    target_map = output_dir / f'target-newlib-{srctype}.c'
    assert target_map.exists(), f'{target_map}: Missing skeleton'
    old_lines = target_map.read_text().splitlines()
    start_i = end_i = None
    for i, line in enumerate(old_lines):
        if START_MARKER in line:
            start_i = i
        if END_MARKER in line:
            end_i = i
    assert start_i and end_i
    new_lines = old_lines[0:start_i + 1]
    new_lines.extend(
        f'#ifdef {sym}\n'
        f'  {{ "{sym}", {sym}, {val} }},\n'
        f'#endif' for sym, val in sorted(syms.items()))
    new_lines.extend(old_lines[end_i:])
    target_map.write_text('\n'.join(new_lines) + '\n')


def gen_common(output_dir: Path, newlib: Path, cpp: str):
    """Generate the common C library constants.

    No arch should override these.
    """
    gentvals(output_dir, cpp, 'errno', newlib / 'newlib/libc/include',
             ('errno.h', 'sys/errno.h'), 'E[A-Z0-9]*')

    gentvals(output_dir, cpp, 'signal', newlib / 'newlib/libc/include',
             ('signal.h', 'sys/signal.h'), r'SIG[A-Z0-9]*', filter=r'SIGSTKSZ')

    gentvals(output_dir, cpp, 'open', newlib / 'newlib/libc/include',
             ('fcntl.h', 'sys/fcntl.h', 'sys/_default_fcntl.h'), r'O_[A-Z0-9]*')


def gen_target_syscall(output_dir: Path, newlib: Path, cpp: str):
    """Generate the target-specific syscall lists."""
    target_map_c = output_dir / 'target-newlib-syscall.c'
    old_lines_c = target_map_c.read_text().splitlines()
    start_i = end_i = None
    for i, line in enumerate(old_lines_c):
        if START_MARKER in line:
            start_i = i
        if END_MARKER in line:
            end_i = i
    assert start_i and end_i, f'{target_map_c}: Unable to find markers'
    new_lines_c = old_lines_c[0:start_i + 1]
    new_lines_c_end = old_lines_c[end_i:]

    target_map_h = output_dir / 'target-newlib-syscall.h'
    old_lines_h = target_map_h.read_text().splitlines()
    start_i = end_i = None
    for i, line in enumerate(old_lines_h):
        if START_MARKER in line:
            start_i = i
        if END_MARKER in line:
            end_i = i
    assert start_i and end_i, f'{target_map_h}: Unable to find markers'
    new_lines_h = old_lines_h[0:start_i + 1]
    new_lines_h_end = old_lines_h[end_i:]

    headers = ('syscall.h',)
    pattern = r'SYS_[_a-zA-Z0-9]*'

    # Output the target-specific syscalls.
    for target, subdir in sorted(TARGET_DIRS.items()):
        syms = extract_syms(cpp, newlib / subdir, headers, pattern)
        new_lines_c.append(f'CB_TARGET_DEFS_MAP cb_{target}_syscall_map[] = {{')
        new_lines_c.extend(
            f'#ifdef CB_{sym}\n'
            '  { '
            f'"{sym[4:]}", CB_{sym}, TARGET_NEWLIB_{target.upper()}_{sym}'
            ' },\n'
            '#endif' for sym in sorted(syms))
        new_lines_c.append('  {NULL, -1, -1},')
        new_lines_c.append('};\n')

        new_lines_h.append(
            f'extern CB_TARGET_DEFS_MAP cb_{target}_syscall_map[];')
        new_lines_h.extend(
            f'#define TARGET_NEWLIB_{target.upper()}_{sym} {val}'
            for sym, val in sorted(syms.items()))
        new_lines_h.append('')

    # Then output the common syscall targets.
    syms = extract_syms(cpp, newlib / 'libgloss', headers, pattern)
    new_lines_c.append(f'CB_TARGET_DEFS_MAP cb_init_syscall_map[] = {{')
    new_lines_c.extend(
        f'#ifdef CB_{sym}\n'
        f'  {{ "{sym[4:]}", CB_{sym}, TARGET_NEWLIB_{sym} }},\n'
        f'#endif' for sym in sorted(syms))
    new_lines_c.append('  {NULL, -1, -1},')
    new_lines_c.append('};')

    new_lines_h.append('extern CB_TARGET_DEFS_MAP cb_init_syscall_map[];')
    new_lines_h.extend(
        f'#define TARGET_NEWLIB_{sym} {val}'
        for sym, val in sorted(syms.items()))

    new_lines_c.extend(new_lines_c_end)
    target_map_c.write_text('\n'.join(new_lines_c) + '\n')

    new_lines_h.extend(new_lines_h_end)
    target_map_h.write_text('\n'.join(new_lines_h) + '\n')


def gen_targets(output_dir: Path, newlib: Path, cpp: str):
    """Generate the target-specific lists."""
    gen_target_syscall(output_dir, newlib, cpp)


def gen(output_dir: Path, newlib: Path, cpp: str):
    """Generate all the things!"""
    gen_common(output_dir, newlib, cpp)
    gen_targets(output_dir, newlib, cpp)


def get_parser() -> argparse.ArgumentParser:
    """Get CLI parser."""
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument(
        '-o', '--output', type=Path,
        help='write to the specified directory')
    parser.add_argument(
        '--cpp', type=str, default='cpp',
        help='the preprocessor to use')
    parser.add_argument(
        '--srcroot', type=Path,
        help='the root of this source tree')
    parser.add_argument(
        'newlib', nargs='?', type=Path,
        help='path to the newlib+libgloss source tree')
    return parser


def parse_args(argv: List[str]) -> argparse.Namespace:
    """Process the command line & default options."""
    parser = get_parser()
    opts = parser.parse_args(argv)

    if opts.output is None:
        # Default to where the script lives.
        opts.output = Path(__file__).resolve().parent

    if opts.srcroot is None:
        opts.srcroot = Path(__file__).resolve().parent.parent.parent
    else:
        opts.srcroot = opts.srcroot.resolve()

    if opts.newlib is None:
        # Try to find newlib relative to our source tree.
        if (opts.srcroot / 'newlib').is_dir():
            # If newlib is manually in the same source tree, use it.
            if (opts.srcroot / 'libgloss').is_dir():
                opts.newlib = opts.srcroot
            else:
                opts.newlib = opts.srcroot / 'newlib'
        elif (opts.srcroot.parent / 'newlib').is_dir():
            # Or see if it's alongside the gdb/binutils repo.
            opts.newlib = opts.srcroot.parent / 'newlib'
    if opts.newlib is None or not opts.newlib.is_dir():
        parser.error('unable to find newlib')

    return opts


def main(argv: List[str]) -> int:
    """The main entry point for scripts."""
    opts = parse_args(argv)

    gen(opts.output, opts.newlib, opts.cpp)
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
