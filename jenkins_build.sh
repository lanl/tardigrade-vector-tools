#!/usr/bin/env bash

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
if [ -f "${apps}/anaconda/2019.10-python-3.7/etc/profile.d/conda.sh" ]; then
    . "${apps}/anaconda/2019.10-python-3.7/etc/profile.d/conda.sh"
    conda activate
    conda activate "${projects}/python/develop"
else
    export PATH="${apps}/anaconda/5.0.1-python-3.6/bin:$PATH"
    source activate
    source activate "${projects}/python/develop"
fi

# Make bash script more like high-level languages.
set -Eeuxo pipefail

# Debugging
whoami
groups
ls -l ~/include || true
ls -l ~/include/eigen3 || true
ls -l ~/include/eigen3/Eigen || true
ls -l ~/include/eigen3/Eigen/Dense || true

# Source common shell script variables
source set_vars.sh

# Check conda environment for debugging
conda info | grep default

# Clone and update dependencies
./update_dependencies.sh

# Clean and build repo tests
./new_build.sh

# Perform repo tests
cd "build/${tests}"
./test_${repo}

# Check for failed tests
if grep -i false results.tex; then
    exit 1
fi
