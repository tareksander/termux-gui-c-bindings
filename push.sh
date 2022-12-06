#!/bin/bash

if [ ! -f termux-gui-c.tar.gz ] || [ "$(tar df termux-gui-c.tar.gz)" != "" ]; then
    tar caf termux-gui-c.tar.gz CMakeLists.txt src include tutorial GUIProt0.proto
fi

"$ANDROID_HOME"/platform-tools/adb push --sync termux-gui-c.tar.gz /storage/emulated/0/Download/termux-gui-c.tar.gz

