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

# Utility rule file for bif-alt-broxygen-broxygen.bif.

# Include the progress variables for this target.
include src/broxygen/CMakeFiles/bif-alt-broxygen-broxygen.bif.dir/progress.make

src/broxygen/CMakeFiles/bif-alt-broxygen-broxygen.bif: src/broxygen/broxygen.bif.h
src/broxygen/CMakeFiles/bif-alt-broxygen-broxygen.bif: src/broxygen/broxygen.bif.cc


src/broxygen/broxygen.bif.h: ../src/broxygen/broxygen.bif
src/broxygen/broxygen.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing broxygen.bif"
	cd /home/ubuntu/bro/my_build_dir/src/broxygen && ../bifcl -s /home/ubuntu/bro/src/broxygen/broxygen.bif || ( rm -f broxygen.bif.h broxygen.bif.cc broxygen.bif.init.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/broxygen && /usr/bin/cmake -E copy broxygen.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/broxygen.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/broxygen && /usr/bin/cmake -E remove -f broxygen.bif.bro

src/broxygen/broxygen.bif.cc: src/broxygen/broxygen.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/broxygen/broxygen.bif.cc

src/broxygen/broxygen.bif.init.cc: src/broxygen/broxygen.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/broxygen/broxygen.bif.init.cc

scripts/base/bif/broxygen.bif.bro: src/broxygen/broxygen.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/broxygen.bif.bro

bif-alt-broxygen-broxygen.bif: src/broxygen/CMakeFiles/bif-alt-broxygen-broxygen.bif
bif-alt-broxygen-broxygen.bif: src/broxygen/broxygen.bif.h
bif-alt-broxygen-broxygen.bif: src/broxygen/broxygen.bif.cc
bif-alt-broxygen-broxygen.bif: src/broxygen/broxygen.bif.init.cc
bif-alt-broxygen-broxygen.bif: scripts/base/bif/broxygen.bif.bro
bif-alt-broxygen-broxygen.bif: src/broxygen/CMakeFiles/bif-alt-broxygen-broxygen.bif.dir/build.make

.PHONY : bif-alt-broxygen-broxygen.bif

# Rule to build all files generated by this target.
src/broxygen/CMakeFiles/bif-alt-broxygen-broxygen.bif.dir/build: bif-alt-broxygen-broxygen.bif

.PHONY : src/broxygen/CMakeFiles/bif-alt-broxygen-broxygen.bif.dir/build

src/broxygen/CMakeFiles/bif-alt-broxygen-broxygen.bif.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/broxygen && $(CMAKE_COMMAND) -P CMakeFiles/bif-alt-broxygen-broxygen.bif.dir/cmake_clean.cmake
.PHONY : src/broxygen/CMakeFiles/bif-alt-broxygen-broxygen.bif.dir/clean

src/broxygen/CMakeFiles/bif-alt-broxygen-broxygen.bif.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/broxygen /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/broxygen /home/ubuntu/bro/my_build_dir/src/broxygen/CMakeFiles/bif-alt-broxygen-broxygen.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/broxygen/CMakeFiles/bif-alt-broxygen-broxygen.bif.dir/depend
