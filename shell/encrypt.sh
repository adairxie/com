#!/bin/bash

function encrypt(){ 
    flist=`ls $1`
    cd $1
    for f in $flist
    do
        if test -d $f
        then
            encrypt $f
        else
            if [ "${f##*.}" = "lua" ]; then
                `luajit-2.1.0-beta2 -b $f $f`
            fi
        fi

    done
    cd ../ 
}

dir=./
encrypt $dir
