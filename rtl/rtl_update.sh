#!/bin/bash

# Created by: Sharmine Catherine Reyes

# This script is for automatically updating my rtl on my local_destination and system_destination rtl (directry related to pythondata-cpu-cv32e40p and system-level directory that is part of python package installation)

# how to run: ./rtl_update.sh



# Source directory
source_dir="/home/sharmine/Documents/git_dir/rtl"

# Local and system-level Destination directory
local_destination_dir="$HOME/Documents/thesis/pythondata-cpu-cv32e40p/pythondata_cpu_cv32e40p/system_verilog"
system_destination_dir="/usr/local/lib/python3.7/dist-packages/pythondata_cpu_cv32e40p-0.0.post152-py3.7.egg/pythondata_cpu_cv32e40p/system_verilog"

# Get current date in YYMMDD format
date_today=$(date +"%y%m%d")

# Find the latest version
latest_version_local=$(ls -1 "$local_destination_dir" | grep -E '^rtl_[0-9]{6}_[0-9]+' | awk -F'_' '{print $3}' | sort -n | tail -n 1)
latest_version_system=$(ls -1 "$system_destination_dir" | grep -E '^rtl_[0-9]{6}_[0-9]+' | awk -F'_' '{print $3}' | sort -n | tail -n 1)
next_version_local=$((latest_version_local + 1))
next_version_system=$((latest_version_system + 1))

# Destination folder for the new version
destination_folder_local="rtl_${date_today}_${next_version_local}"
destination_folder_system="rtl_${date_today}_${next_version_system}"

# Copy files
cp -r "$source_dir" "$local_destination_dir/$destination_folder_local"
sudo cp -r "$source_dir" "$system_destination_dir/$destination_folder_system"

# Create a symbolic link
ln -sfn "$destination_folder_local" "$local_destination_dir/rtl"
sudo ln -sfn "$destination_folder_system" "$system_destination_dir/rtl"

echo "Local-level: RTL files copied to $local_destination_dir/$destination_folder_local, and 'rtl' link updated."
echo "System-level: RTL files copied to $system_destination_dir/$destination_folder_system, and 'rtl' link updated."

