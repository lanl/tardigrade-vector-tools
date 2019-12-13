#!/usr/bin/env bash

# Source the Intel compilers
source /apps/intel2016/bin/ifortvars.sh -arch intel64 -platform linux

# Make bash script more like high-level languages.
# https://vaneyckt.io/posts/safer_bash_scripts_with_set_euxo_pipefail/
# Have to do this after sourcing ifortvars.sh becuase the shell script has unbound variables
set -Eeuxo pipefail

# Source common shell script variables
source set_vars.sh

# Clone and update dependencies
source update_dependencies.sh

# Build repo tests
cd ${workdir}/src/cpp/tests/${repo}/
if [ -f ${repo}.o ] || [ -f test_${repo}.o ]; then
    make clean
fi
make

# Perform repo tests
./test_${repo}
