# Source the Intel compilers
case $(hostname) in
    hamming.lanl.gov|sstelmo.lanl.gov)
        source /apps/intel2016/bin/ifortvars.sh -arch intel64 -platform linux
        export CXX=$(which icc)
        ;;
esac

set -Eeuxo pipefail

# Find cmake3 executable
if [ -x "$(command -v cmake3)" ]; then
    cmake_exec=$(command -v cmake3)
elif [ -x "$(command -v cmake)" ]; then
    cmake_exec=$(command -v cmake)
else
    echo "Could not find cmake executable"
    exit 1
fi

# Clean and build repo tests
rm -rf build/
mkdir build
cd build
${cmake_exec} ..
${cmake_exec} --build .
