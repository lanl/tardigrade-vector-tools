# Micromorphic filter, a variationally based filter for DNS
#
# Author: Nathan A. Miller (LANL / CU Boulder)
# Email:  nathanm@lanl.gov
# Date:   July 13, 2018
#
# This is the common configuration file for all of the included makefiles

# C++ compiler
CXX=/opt/moose/gcc-7.3.0/bin/g++

# Flags for the C++ compiler
CFLAGS=-std=gnu++11 -Wall -ansi -pedantic -O3 -I. -fmax-errors=5

# Location of the Eigen library
EIGEN=-I/projects/nathanm/usr/local/include/eigen-git-mirror

# The python command
PYTHON=/apps/anaconda3/bin/python

# Location of the quickhull source code
QHULL=/projects/nathanm/micromorphic/micromorphic_library/external_repositories/quickhull/

# Additional includes
ROOTDIR=/projects/nathanm/micromorphic/micromorphic_library
INCDIR=$(ROOTDIR)/include
LIBDIR=$(ROOTDIR)/lib
INC=-I$(INCDIR)
INC+=-I$(INCDIR)/voro++
INC+=-I$(INCDIR)/overlap
LIB=-L$(LIBDIR)
LIB+=-L$(LIBDIR)/voro++
LIB+=-L$(LIBDIR)/overlap
