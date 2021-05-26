# USAGE:
#
# ./new_build.sh

# Make bash script more like high-level languages.
set -Eeuxo pipefail

# Get this scripts file name
script=`basename "$0"`

# Debugging
whoami
groups
ls -l $HOME/include || true
ls -l $HOME/.local/include || true

# Find cmake3 executable
if [ -x "$(command -v cmake3)" ]; then
    cmake_exec=$(command -v cmake3)
elif [ -x "$(command -v cmake)" ]; then
    cmake_exec=$(command -v cmake)
else
    echo "Could not find cmake executable"
    exit 3
fi

# Clean and build repo tests
rm -rf build/
mkdir build
cd build
${cmake_exec} ..
${cmake_exec} --build . --verbose
