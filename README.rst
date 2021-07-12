#############
vector\_tools
#############

*******************
Project Description 
*******************

A collection of tools for C++ that make interfacing with vectors easier and
less prone to error. These tools also allow the user access to the powerful
Eigen library which provides matrix utilities in such a way that Eigen does
not need to be used explicitly in the user's code.

Information
===========

* Documentation: https://aea.re-pages.lanl.gov/material-models/vector_tools
* Wiki: https://re-git.lanl.gov/aea/material-models/vector_tools/-/wikis/home

Developers
==========

* Nathan Miller nathanm@lanl.gov
* Kyle Brindley kbrindley@lanl.gov

************
Dependencies
************

Compilers
=========

* c++11 compiler (listed version number has been tested at some point)

  * g++ >= GNU 4.8.5

Executables
===========

* [CMake](https://cmake.org/cmake/help/v3.14/) >= 3.14
* [Doxygen](https://www.doxygen.nl/manual/docblocks.html) >= 1.8.5
* [LaTeX](https://www.latex-project.org/help/documentation/) >= 2017

Python Modules (for documentation)
==================================

For convenience, the minimal Python environment requirements for the
documentation build are included in ``configuration_files/environment.yaml``.
This file was created from the [pipreqs](https://github.com/bndr/pipreqs)
command line tool and Sphinx configuration inspection, e.g. the extension
packages.

.. code-block:: bash

   $ pwd
   path/to/vector_tools/
   $ pipreqs --use-local --print --no-pin .

A minimal anaconda environment for building the documentation can be created
from an existing anaconda installation with the following commands.

.. code-block:: bash

   $ conda env create --file environment.yaml

You can learn more about Anaconda Python environment creation and management in
the [Anaconda
Documentation](https://docs.conda.io/projects/conda/en/latest/user-guide/tasks/manage-environments.html)

C++ Libraries
=============

> **NOTE: Non-admin installations for Eigen and Boost are no longer required.** This project is built and deployed
> against C++ libraries managed in Conda. See the Conda environment file and README discussion for non-admin environment
> management.

* [Eigen](https://eigen.tuxfamily.org/dox/) >= 3.3.7
* [BOOST](https://www.boost.org/doc/libs/1_53_0/) >= 1.53.0

**************************
Building the documentation
**************************

.. warning::

   **API Health Note**: The Sphinx API docs are a work-in-progress. The doxygen
   API is much more useful

A build script has been created for convenience, ``new_build.sh``. It will build
everything including the library binary, the test binary, and the documentation.
This is the same build script used by ``jenkins_build.sh`` for CI builds and
testing.

sstelmo
=======

1) Activate a [W-13 Python Environment](https://xcp-confluence.lanl.gov/display/PYT/The+W-13+Python+3+environment)

   .. code-block:: bash

     $ module load python/2020.07-python-3.8
     $ sv3r

2) Create the build directory and move there

   .. code-block:: bash

     $ pwd
     /path/to/vector_tools/
     $ mkdir build/
     $ cd build/

3) Run cmake3 configuration

   .. code-block:: bash

      $ pwd
      /path/to/vector_tools/build/
      $ cmake3 ..

4) Build the docs

   .. code-block:: bash

       $ cmake3 --build docs

5) Sphinx HTML Documentation builds to:

   .. code-block:: bash

      vector_tools/build/docs/sphinx/html/index.html

6) Display docs

   .. code-block:: bash

      $ pwd
      /path/to/vector_tools/build/
      $ firefox docs/sphinx/html/index.html &

7) While the Sphinx API is still a WIP, try the doxygen API

   .. code-block:: bash

     $ pwd
     /path/to/vector_tools/build/
     $ firefox docs/doxygen/html/index.html &

---

## Build the library

Follow the steps for building the documentation and pick up below.

4) Build just the library

   .. code-block:: bash

       $ pwd
       /path/to/vector_tools/build
       $ cmake3 --build src/cpp

---

## Install the library

Build the entire before performing the installation.

4) Build the entire project

   .. code-block:: bash

      $ pwd
      /path/to/vector_tools/build
      $ cmake3 --build .

5) Install the library

   .. code-block:: bash

      $ pwd
      /path/to/vector_tools/build
      $ cmake --install . --prefix path/to/root/install

      # Example local user (non-admin) Linux install
      $ cmake --install . --prefix /home/$USER/.local

      # Example install to conda environment
      $ cmake --install . --prefix path/to/conda/environment/

      # Example install to W-13 CI/CD conda environment performed by CI/CD institutional account
      $ cmake --install . --prefix /projects/python/release

---

***********************
Contribution Guidelines
***********************

Git Commit Message
==================

Begin Git commit messages with one of the following headings:

* BUG: bug fix
* DOC: documentation
* FEAT: feature
* MAINT: maintenance
* TST: tests
* REL: release
* WIP: work-in-progress

For example:

.. code-block:: bash

   git commit -m "DOC: adds documentation for feature"

Git Branch Names
================

When creating branches use one of the following naming conventions. When in
doubt use ``feature/<description>``.

* ``bugfix/\<description>``
* ``feature/\<description>``
* ``release/\<description>``

reStructured Text
=================

[Sphinx](https://www.sphinx-doc.org/en/master/) reads in docstrings and other special portions of the code as
reStructured text. Developers should follow styles in this [Sphinx style
guide](https://documentation-style-guide-sphinx.readthedocs.io/en/latest/style-guide.html#).

Style Guide
===========

This project does not yet have a full style guide. Generally, wherever a style can't be
inferred from surrounding code this project falls back to
[PEP-8](https://www.python.org/dev/peps/pep-0008/)-like styles. There are two
notable exceptions to the notional PEP-8 fall back:

1. [Doxygen](https://www.doxygen.nl/manual/docblocks.html) style docstrings are
   required for automated, API from source documentation.
2. This project prefers expansive whitespace surrounding parentheses, braces, and
   brackets.
   * No leading space between a function and the argument list.
   * One space following an open paranthesis ``(``, brace ``{``, or bracket
     ``[``
   * One space leading a close paranthesis ``)``, brace ``}``, or bracket ``]``

An example of the whitespace style:

.. code-block:: bash

   my_function( arg1, { arg2, arg3 }, arg4 );

The following ``sed`` commands may be useful for updating white space, but must
be used with care. The developer is recommended to use a unique git commit
between each command with a corresponding review of the changes and a unit test
run.

* Trailing space for open paren/brace/bracket

  .. code-block:: bash

     sed -i 's/\([({[]\)\([^ ]\)/\1 \2/g' <list of files to update>

* Leading space for close paren/brace/bracket

  .. code-block:: bash

     sed -i 's/\([^ ]\)\([)}\]]\)/\1 \2/g' <list of files to update>

* White space between adjacent paren/brace/bracket

  .. code-block:: bash

     sed -i 's/\([)}\]]\)\([)}\]]\)/\1 \2/g' <list of files to update>
