#!/bin/sh

if [ $# -ne 2 ]; then
    echo "Error: Invalid number of arguments"
    exit 1
fi

writefile="$1"
writestr="$2"

mkdir -p "$(dirname "$writefile")"

if ! echo "$writestr" > "$writefile"; 
then
    echo "Error: Could not create file"
    exit 1
fi

exit 