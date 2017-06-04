#!/bin/bash

source ./scripts/comfun.sh

OLD_DIR=./old
NEW_DIR=./new

function bak_old()
{
    if [ -n "$(ls ${OLD_DIR})" ]; then
        cp -r ${OLD_DIR} "${OLD_DIR}-$(date +%y%m%d%H%M%S)"
    fi
    rm -rf ${OLD_DIR}/*
    bak_file ${OLD_DIR}
}

function bak_new()
{
    rm -rf ${NEW_DIR}/*
    bak_file ${NEW_DIR}
}

function diff_file()
{
    diff -r ${OLD_DIR} ${NEW_DIR} 2>/dev/null
}

function showhelp()
{
    echo "-----------------------------"
    echo "./ostest.sh bak"
    echo "./ostest.sh diff"
}

OPER="$1"
if [ "${OPER}" = "bak" ]; then
    bak_old
elif [ "${OPER}" = "diff" ]; then
    bak_new
    echo "=============================="
    echo "begin to diff"
    diff_file
else
    showhelp
fi