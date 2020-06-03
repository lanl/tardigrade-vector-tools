#!/usr/bin/env bash

# Set common shell script variables
repo='vector_tools'
tests="src/cpp/tests/${repo}"
eigen_version='3.3.7'
workdir=${PWD}
declare -A deprepo 
proxyout='proxyout.lanl.gov:8080'
