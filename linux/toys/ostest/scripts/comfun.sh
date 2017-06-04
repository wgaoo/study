#! /bin/bash

function bak_file()
{
    local DISTDIR=$1

    if [ -n ${DISTDIR} ]; then
        echo "$(date): bak etc to ${DISTDIR}"
        cp -r /etc ${DISTDIR}

        echo "$(date): bak env to ${DISTDIR}"
        env > ${DISTDIR}/env.lst

        echo "$(date): bak grub to ${DISTDIR}"
        cp -r /boot/grub* ${DISTDIR}

        echo "$(date): bak rpm list to ${DISTDIR}"
        rpm -qa | sort > ${DISTDIR}/rpm.lst

        echo "$(date): bak kernel info to ${DISTDIR}"
        echo "uname -a" > ${DISTDIR}/unameinfo.lst

        echo "bak date: $(date)" > ${DISTDIR}/readme.txt
    fi
}