# aesgcm_thesis

Repository for the AES-GCM algorithm codes and configuration for Sharmine and Neethu's master thesis project.

_____
## Directory: core

This directory is originally cloned from https://github.com/litex-hub/pythondata-cpu-cv32e40p.git.\
It is to simulate the AES-GCM using CV32E40P RISC-V core and to view the dumped waveform using verilator.

Usage:
```
$ make clean
$ make aesgcm-veri-run                        #for simulating AES-GCM
$ make asmtest-veri-run                       #for simulating the new instructions
$ make aesgcm-veri-run VERI_FLAGS=+vcd        #for simulating AES-GCM and dumping waveform
$ make asmtest-veri-run VERI_FLAGS=+vcd       #for simulating the new instructions and dumping waveforms
```

Make sure to select CFLAGS in the Makefile to identify which test case is needed for simulating the AES-GCM.
____

## Directory: demo

This directory is originally cloned from https://github.com/enjoy-digital/litex.git. \
The LiteX framework creates FPGA Cores/SoCs.\
Used for evaluating the AES-GCM algorithm using PYNQ-Z2 FPGA.

Usage:

For teminal 1:
```
$ dmesg | grep tty
$ # look for: ch341-uart converter now attached to ttyUSBX
$ sudo chmod a+rw /dev/ttyUSBX
$ litex_term --kernel demo.bin /dev/ttyUSBX
```

For
terminal 2:
```
$ source /opt/Xilinx/Vivado/2020.1/settings64.sh
$ python3 -m litex_boards.targets.tul_pynq_z2 --build --load
$ make clean
$ make all
$ python3 -m litex_boards.targets.tul_pynq_z2 --load

```

Make sure to select CFLAG_OPTION in the Makefile to identify which test case is needed for simulating the AES-GCM.

___

   
