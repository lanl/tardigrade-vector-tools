# vector\_tools

A collection of tools for C++ that make interfacing with vectors easier and
less prone to error. These tools also allow the user access to the powerful
Eigen library which provides matrix utilities in such a way that Eigen does
not need to be used explicitly in the user's code.

Note: In order to use the Intel compiler one must run the following command
in a bash prompt:
source /apps/intel2016/bin/ifortvars.sh -arch intel64 -platform linux

This is the same command that the abaqus command issues. It may be that
this command will change on different platforms.

---

---

## Dependencies:

### Make

These tools have several dependencies that must be available in the same parent
directory as this repo.

* eigen: https://gitlab.com/libeigen/eigen

### CMake

The project is transitioning from Make to Cmake. For cmake builds, Eigen must be
"installed" following the ``eigen/INSTALL`` instructions. The Eigen dependence
is easiest to resolve if eigen is installed in the default install directory.
However, if you don't have admin privileges, you can also insall Eigen to your
home directory in ``~/include`` (or possibly in ``~/.local/include``, but this
is untested by this project).

#### Non-admin Eigen install for vector_tools
[Reference](https://unix.stackexchange.com/questions/36871/where-should-a-local-executable-be-placed)

```
# sstelmo
ssh -X sstelmo.lanl.gov
# source Intel compilers
source /apps/intel2016/bin/ifortvars.sh -arch intel64 -platform linux
# Create personal include file directory
$ pwd
/home/<moniker>
$ mkdir include
# Move to repository directory
$ cd /preferred/path/to/repos
# Example
$ pwd
/projects/<moniker>/e13repos
# Clone eigen
$ git clone https://gitlab.com/libeigen/eigen.git
$ cd eigen
# Build eigen
$ mkdir build
$ cd build
$ export CXX=$(which icc)
$ cmake3 .. -DCMAKE_INSTALL_PREFIX=/home/<moniker>
$ make install
```

---

---

## Documentation

The documentation for this project is built with cmake, sphinx, doxygen, and
breathe.

The documentation was built with these [microsoft developer blog
instructions](https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/)
for c++ projects. The one caveat is the ``vector_tools`` project is used as a
header only project, so no libraries are built.

To build the documentation run the following from the project root directory,
``vector_tools``:

```
$ pwd
path/to/vector_tools
$ mkdir build
$ cd build
$ cmake3 ..
$ cmake --build docs
```
