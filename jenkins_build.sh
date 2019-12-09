#!/usr/bin/env bash

repo='vector_tools'
workdir=${PWD}
declare -A deprepo 
deprepo['eigen']='https://gitlab.com/libeigen/eigen.git'
proxyout='proxyout.lanl.gov:8080'

# Source the Intel compilers
source /apps/intel2016/bin/ifortvars.sh -arch intel64 -platform linux

# Make bash script more like high-level languages.
# https://vaneyckt.io/posts/safer_bash_scripts_with_set_euxo_pipefail/
# Have to do this after sourcing ifortvars.sh becuase the shell script has unbound variables
set -Eeuxo pipefail

# Clone dependencies
cd ..
for deprepodir in "${!deprepo[@]}"; do
    if [ ! -d ${deprepodir} ]; then
        all_proxy=${proxyout} git clone ${deprepo[$deprepodir]}
    else
        cd ${deprepodir} && all_proxy=${proxyout} git pull
        cd ..
    fi
done

# Perform repo tests
cd ${workdir}/src/cpp/tests/${repo}/
if [ -f ${repo}.o ] || [ -f test_${repo}.o ]; then
    make clean
fi
make
