#!/bin/bash

while getopts ":s:" ARG; do
    case $ARG in
    s)
        TIMESTAMP=$OPTARG;
        ;;
    :)
        TIMESTAMP=0;
        ;;
    \?)
        echo "sysd.sh usage:";
        echo -e "\t-s\ttimestamp seconds (default or zero for inf)";
        exit 1;
        ;;
    esac
done

PATH_SHELL=`dirname \`readlink -f $0\``;

function sys_daemon() {
    $PATH_SHELL/comm.sh -m auto -o;
}

if [[ $TIMESTAMP ]]; then
    while [[ $TIMESTAMP ]]; do
        sys_daemon;
        sleep $TIMESTAMP;
    done
else
    sys_daemon;
fi
