# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/bro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/bro/my_build_dir

# Utility rule file for sphinxdoc.

# Include the progress variables for this target.
include doc/CMakeFiles/sphinxdoc.dir/progress.make

doc/CMakeFiles/sphinxdoc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[Sphinx] Generate HTML documentation in /home/ubuntu/bro/my_build_dir/html"
	cd /home/ubuntu/bro/my_build_dir/doc && rsync -q -r --copy-links --times --delete --filter='protect scripts/*' /home/ubuntu/bro/doc/ /home/ubuntu/bro/my_build_dir/doc/sphinx_input
	cd /home/ubuntu/bro/my_build_dir/doc && BROPATH=.:/home/ubuntu/bro/scripts:/home/ubuntu/bro/scripts/policy:/home/ubuntu/bro/scripts/site:/home/ubuntu/bro/my_build_dir/scripts /home/ubuntu/bro/my_build_dir/src/bro -X /home/ubuntu/bro/my_build_dir/doc/broxygen.conf broxygen >/dev/null
	cd /home/ubuntu/bro/my_build_dir/doc && rsync -q -r --copy-links --times --delete --filter='protect *.bro' /home/ubuntu/bro/my_build_dir/doc/broxygen_script_output/ /home/ubuntu/bro/my_build_dir/doc/sphinx_input/scripts
	cd /home/ubuntu/bro/my_build_dir/doc && rsync -q -r --copy-links --times --delete --filter='protect /base/bif/*' --filter='protect *.rst' --filter='include */' --filter='include *.bro' --filter='exclude *' /home/ubuntu/bro/scripts/ /home/ubuntu/bro/my_build_dir/doc/sphinx_input/scripts
	cd /home/ubuntu/bro/my_build_dir/doc && rsync -q -r --copy-links --times --delete --filter='protect *.rst' --filter='include */' --filter='include *.bro' --filter='exclude *' /home/ubuntu/bro/my_build_dir/scripts/base/bif/ /home/ubuntu/bro/my_build_dir/doc/sphinx_input/scripts/base/bif
	cd /home/ubuntu/bro/my_build_dir/doc && sphinx-build -b html -c /home/ubuntu/bro/my_build_dir/doc -d /home/ubuntu/bro/my_build_dir/doc/sphinx_output/doctrees /home/ubuntu/bro/my_build_dir/doc/sphinx_input /home/ubuntu/bro/my_build_dir/doc/sphinx_output/html
	cd /home/ubuntu/bro/my_build_dir/doc && /usr/bin/cmake -E create_symlink /home/ubuntu/bro/my_build_dir/doc/sphinx_output/html /home/ubuntu/bro/my_build_dir/html
	cd /home/ubuntu/bro/my_build_dir/doc && test -d /home/ubuntu/bro/my_build_dir/aux/broccoli/doc/html && ( rm -rf /home/ubuntu/bro/my_build_dir/html/broccoli-api && cp -r /home/ubuntu/bro/my_build_dir/aux/broccoli/doc/html /home/ubuntu/bro/my_build_dir/html/broccoli-api ) || true

sphinxdoc: doc/CMakeFiles/sphinxdoc
sphinxdoc: doc/CMakeFiles/sphinxdoc.dir/build.make

.PHONY : sphinxdoc

# Rule to build all files generated by this target.
doc/CMakeFiles/sphinxdoc.dir/build: sphinxdoc

.PHONY : doc/CMakeFiles/sphinxdoc.dir/build

doc/CMakeFiles/sphinxdoc.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/doc && $(CMAKE_COMMAND) -P CMakeFiles/sphinxdoc.dir/cmake_clean.cmake
.PHONY : doc/CMakeFiles/sphinxdoc.dir/clean

doc/CMakeFiles/sphinxdoc.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/doc /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/doc /home/ubuntu/bro/my_build_dir/doc/CMakeFiles/sphinxdoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : doc/CMakeFiles/sphinxdoc.dir/depend
