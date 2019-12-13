#!/usr/bin/env bash

# Set common shell script variables
repo='vector_tools'
workdir=${PWD}
declare -A deprepo 
deprepo['eigen']='https://gitlab.com/libeigen/eigen.git'
proxyout='proxyout.lanl.gov:8080'
