#!/bin/bash

[ "$UID" -eq 0 ] || exec sudo "$0" "$@"

apt update;
apt-get install cmake;
add-apt-repository ppa:ubuntu-toolchain-r/test;
apt-get update;
apt-get install gcc-11 g++-11;
# update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 60 --slave /usr/bin/g++ g++ /usr/bin/g++-11