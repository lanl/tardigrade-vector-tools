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

Dependencies: 

These tools have several dependencies that must be available in the same parent
directory as this repo. 

* eigen: https://gitlab.com/libeigen/eigen

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
