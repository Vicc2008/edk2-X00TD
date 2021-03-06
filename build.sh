#!/bin/bash
# based on the instructions from edk2-platform
set -e
. build_common.sh
# not actually GCC5; it's GCC7 on Ubuntu 18.04.
GCC5_AARCH64_PREFIX=aarch64-linux-gnu- build -s -n 0 -a AARCH64 -t GCC5 -p AsusMaxProM1Pkg/AsusMaxProM1Pkg.dsc
gzip -c < workspace/Build/AsusMaxProM1Pkg/DEBUG_GCC5/FV/ASUSMAXPROM1PKG_UEFI.fd >uefi_image
cat X00TD.dtb >>uefi_image
abootimg --create uefi.img -k uefi_image -r ramdisk-null -f bootimg.cfg
