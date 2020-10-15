# Make bash script more like high-level languages.
set -Eeuxo pipefail

# Debugging
whoami
groups
ls -l ~/include || true
ls -l ~/include/eigen3 || true
ls -l ~/include/eigen3/Eigen || true
ls -l ~/include/eigen3/Eigen/Dense || true

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
${cmake_exec} --build . --verbose
