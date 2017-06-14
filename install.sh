#!/bin/bash

if [ `whoami` != "root" ]
then
    echo "Launch me in Super User"
    exit 1
fi

cp add-apt-repository /usr/bin/
chmod +x /usr/bin/add-apt-repository
