#!/usr/bin/env bash

# Make bash script more like high-level languages.
# https://vaneyckt.io/posts/safer_bash_scripts_with_set_euxo_pipefail/
# Have to do this after sourcing ifortvars.sh becuase the shell script has unbound variables
set -Eeuxo pipefail

# Source common shell script variables
source set_vars.sh

# Clone and update dependencies
cd ..
for deprepodir in "${!deprepo[@]}"; do
    if [ ! -d ${deprepodir} ]; then
        all_proxy=${proxyout} git clone ${deprepo[$deprepodir]}
    else
        cd ${deprepodir} 
        if [ ${deprepodir} == "eigen" ]; then
            all_proxy=${proxyout} git checkout ${eigen_version} 
        else
            all_proxy=${proxyout} git checkout dev
            all_proxy=${proxyout} git pull --ff-only
        fi
        cd ..
    fi
done
