#!/usr/bin/env bash

# Make bash script more like high-level languages.
set -Eeuxo pipefail

# report conda environment
conda info

# Set some common shell variables
source set_vars.sh

# Clean and build repo tests
case $OSTYPE in
    darwin*)
        compiler='c++'
        ;;
    linux-gnu*)
        compiler='g++'
        ;;
esac
./new_build.sh ${compiler}

# Perform repo tests
cd "build"
ctest --verbose --output-log results.tex
