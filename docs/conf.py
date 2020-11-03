# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import sys
# sys.path.insert(0, os.path.abspath('.'))
import os
import re


# -- Project information -----------------------------------------------------
# Scrape some meta data from a single source (e.g. root CMakeLists.txt)
git_describe = os.popen('git describe --always --dirty --tags').read().strip()
meta_file = "../CMakeLists.txt"
with open(meta_file) as config:
    contents = config.read()
project_regex = f"project[\s]*\(([\S]*) VERSION [0-9]+\.[0-9]+\.[0-9]\)"
project_search = re.search(project_regex, contents)
version_regex = f"project[\s]*\([\S]* VERSION ([0-9]+\.[0-9]+\.[0-9])\)"
version_search = re.search(version_regex, contents)

# Hardcoded project information
copyright = '2020, Nathan A. Miller and Kyle A. Brindley'
author = 'Nathan A. Miller and Kyle A. Brindley'

# Scrape meta_file for project name or fail
if project_search:
    project = project_search.group(1)
else:
    raise RuntimeError(f'Could not find project name in {meta_file} with "{project_regex}" regex pattern')

# Scrape meta_file for version or fall back to git info
if version_search:
    release = version_search.group(1)
else:
    release = git_describe
if release != git_describe:
    release = release + f"+{git_describe}"
version = release

# -- Project Variables -------------------------------------------------------
rst_prolog = f'.. |project| replace:: {project}\n.. include:: targets.txt'

# -- General configuration ---------------------------------------------------
# Add custom style sheet to make the html docs wider
def setup(app):
    app.add_css_file('custom.css')

# Add any Sphinx extension module names here, as strings.
extensions = ["breathe", 'sphinxcontrib.bibtex']

# Breathe Configuration
breathe_projects = {project: "../build/docs/doxygen/xml"}
breathe_default_project = project

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

# -- Options for HTML output -------------------------------------------------
# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']
