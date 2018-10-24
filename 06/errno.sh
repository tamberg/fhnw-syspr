#!/bin/bash

# $ chmod a+x errno.sh
# $ ./errno.sh

echo "> expand, compile and grep errno.h:" &&
echo '#include <errno.h>' | gcc -pthread -E - | grep errno &&
echo "> take a closer look:" &&
cat /usr/include/arm-linux-gnueabihf/bits/errno.h | grep errno
