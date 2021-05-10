# Make bash script more like high-level languages.
set -Eeuxo pipefail
cd "build"
conda_env_path=$(conda info | grep "active env location" | cut -f 2 -d :)
cmake --install src/cpp --prefix ${conda_env_path}
