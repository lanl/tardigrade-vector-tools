#!/usr/bin/env bash

# Source the Intel compilers
source /apps/intel2016/bin/ifortvars.sh -arch intel64 -platform linux

# TODO: update the release environment and source that instead
# NOTE: activation will fail if/when conda is updated to >=4.4
# Activate the release-cpp environment
case $OSTYPE in
    darwin*)
        apps="/Users/apps"
        projects="/Users/projects"
        ;;
    linux-gnu*)
        apps="/apps"
        projects="/projects"
        ;;
    *)
        echo "Detected OS $OSTYPE is not supported. Exiting."
        exit 3
        ;;
esac
source "${apps}/anaconda/5.0.1-python-3.6/bin/activate" 
source activate "${projects}/python/release-cpp"

# Make bash script more like high-level languages.
set -Eeuxo pipefail

# Check conda environment for debugging
conda info | grep default

# Clone and update dependencies
source update_dependencies.sh

# Clean and build repo tests
./new_build.sh

# Perform repo tests
cd "build/${tests}"
./test_${repo}

# Check for failed tests
if grep -i false results.tex; then
    exit 1
fi
