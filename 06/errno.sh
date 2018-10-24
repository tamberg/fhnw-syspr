#!/bin/bash

# $ chmod a+x errno.sh
# $ ./errno.sh

set -x && # show commands, https://serverfault.com/a/16208/3827
echo '#include <errno.h>' | gcc -pthread -E - | grep errno &&
cat /usr/include/arm-linux-gnueabihf/bits/errno.h | grep errno
