#!/bin/bash
if [ "$1" == "pc" ]; then
    meson setup build_pc
    meson compile -C build_pc
elif [ "$1" == "kindle" ]; then
    meson setup --cross-file $KSDK build_kindle
    meson compile -C build_kindle
else
    echo "Usage: $0 (pc | kindle)"
fi
