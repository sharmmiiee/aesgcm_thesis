#!/bin/bash


if [ "$#" -ne 1 ] || [ "$1" = "-h" ] || [ "$1" = "--help" ]; then
    echo "Usage: $0 <header_file_name>"
    echo "  Unlinks data.h (if it exists) and links to the specified header file."
    echo " "
    echo "./link.sh gcmEncryptExtIV128_1block"
    echo "./link.sh gcmEncryptExtIV192_1block"
    echo "./link.sh gcmEncryptExtIV256_1block"
    echo "./link.sh gcmDecrypt128_1block"
    echo "./link.sh gcmDecrypt192_1block"
    echo "./link.sh gcmDecrypt256_1block"
    exit 0
fi

header_file="$1"

# Unlink data.h (if it exists)
if [ -e "data.h" ]; then
    unlink data.h
fi

# Link to the specified header file
if [ -e "$header_file.h" ]; then
    ln -s "$header_file.h" data.h
    echo "Linked to $header_file.h"
else
    echo "$header_file.h does not exist."
fi

