#!/usr/bin/env bash

workdir=${PWD}
eigendir='eigen'
eigenrepo='https://gitlab.com/libeigen/eigen.git'

# Make bash script more like high-level languages.
# https://vaneyckt.io/posts/safer_bash_scripts_with_set_euxo_pipefail/
set -Eeuxo pipefail

cd ..
if [ ! -d ${eigendir} ]; then
    all_proxy=proxyout.lanl.gov:8080 git clone ${eigenrepo}
else
    cd ${eigendir} && git pull
fi
cd ${workdir}
cd src/cpp/test/vector_tools/
make
