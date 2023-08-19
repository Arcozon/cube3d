#!/bin/env bash

usage()
{
    cat <<EOF 1>&2
Usage: $(basename $0) [SRC_PATH] [MAKEFILE] [VAR] [FORMAT]
VAR defaults to SRC
FORMAT defaults to *.c
SRC_PATH defaults to the current directory
MAKEFILE is Makefile and is in the current directory if not provided
EOF
}
if (( $# == 0 ))
then
    usage
fi
SRC_PATH="$1"
SRC_PATH="${SRC_PATH:=.}"
MAKEFILE="$2"
VAR="$3"
VAR="${VAR:=SRC}"
FORMAT="$4"
FORMAT="${FORMAT:=*.c}"

SRC="$(find "${SRC_PATH}" -type f -name ${FORMAT} | sed "s|^${SRC_PATH}/\(.*\)$|\1|")"
SRC="${SRC//$'\n'/ }"
sed -i -e "0,/^\(\s*${VAR}\s*=\s*\).*$/ s|^\(\s*${VAR}\s*=\s*\).*$|\1${SRC}|" "${MAKEFILE:=Makefile}"
