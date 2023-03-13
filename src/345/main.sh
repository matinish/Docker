#!/bin/bash


if [ "$1" == "stop" ]; then
    kill SIGKILL `ps aux | grep server | awk '{print $2}'` 2>/dev/null
else
    service nginx start

    spawn-fcgi -p 8080 ./server
    if [ "$1" == "chtoto" ]; then
        while true ; do
            e=1
        done
    fi
fi

/bin/bash
