#!/usr/bin/env bash

workdir=${PWD}
eigendir='eigen'
eigenrepo='https://gitlab.com/libeigen/eigen.git'
proxyout='proxyout.lanl.gov:8080'

# Make bash script more like high-level languages.
# https://vaneyckt.io/posts/safer_bash_scripts_with_set_euxo_pipefail/
set -Eeuxo pipefail

# Source the Intel compilers
source /apps/intel2016/bin/ifortvars.sh -arch intel64 -platform linux

# Clone dependencies
cd ..
if [ ! -d ${eigendir} ]; then
    all_proxy=${proxyout} git clone ${eigenrepo}
else
    cd ${eigendir} && all_proxy=${proxyout} git pull
fi

# Perform repo tests
cd ${workdir}/src/cpp/test/vector_tools/
make
