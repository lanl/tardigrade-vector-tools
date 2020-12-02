# vector\_tools

A collection of tools for C++ that make interfacing with vectors easier and
less prone to error. These tools also allow the user access to the powerful
Eigen library which provides matrix utilities in such a way that Eigen does
not need to be used explicitly in the user's code.


---

---

## Dependencies:

### Executables

* CMake >= 3.14
* Doxygen >= 1.8.5

### Python Modules

For convenience, the minimal Python environment requirements for the
documentation and python interface build are included in ``environment.yaml``
and ``requirements.txt``. A minimal anaconda environment for building the
documentation and the python interface can be created from an existing
anaconda installation with the following commands.

```
$ conda env create --file environment.yaml
```

### Libraries

* eigen >= 3.3.7
* BOOST >= 1.53.0

#### Eigen

https://gitlab.com/libeigen/eigen

Eigen must be "installed" following the ``eigen/INSTALL`` instructions. The
Eigen dependence is easiest to resolve if eigen is installed in the default
install directory.  However, if you don't have admin privileges, you can also
insall Eigen to your home directory in ``~/include`` (or possibly in
``~/.local/include``, but this is untested by this project).

#### Non-admin Eigen install
[Reference](https://unix.stackexchange.com/questions/36871/where-should-a-local-executable-be-placed)

```
# Create personal include file directory
$ pwd
/home/$USER
$ mkdir .local/include
# Move to repository directory
$ cd /preferred/path/to/repos
# Example
$ pwd
# Clone eigen
$ git clone https://gitlab.com/libeigen/eigen.git
$ cd eigen
$ git checkout 3.3.7
# Build eigen
$ mkdir build
$ cd build
$ cmake3 .. -DCMAKE_INSTALL_PREFIX=$HOME/.local
$ make install
```

---

---

## Building the documentation

> **API Health Note**: The sphinx API docs are a work-in-progress. The doxygen
> API is much more useful

A build script has been created for convenience, ``new_build.sh``. It will build
everything including the library binary, the test binary, and the documentation.
This is the same build script used by ``jenkins_build.sh`` for CI builds and
testing.

### build process

1) Activate a python environment

```
$ conda activate environment
```

2) Create the build directory and move there

```
$ pwd
/path/to/vector_tools/
$ mkdir build/
$ cd build/
```

3) Run cmake3 configuration

```
$ pwd
/path/to/vector_tools/build/
$ cmake3 ..
```

4) Build the docs

```
$ cmake3 --build docs
```

5) Documentation builds to:

```
vector_tools/build/docs/sphinx/index.html
```

6) Display docs

```
$ pwd
/path/to/vector_tools/build/
$ firefox docs/sphinx/index.html &
```

7) While the Sphinx API is still a WIP, try the doxygen API

```
$ pwd
/path/to/vector_tools/build/
$ firefox docs/doxygen/html/index.html &
```
