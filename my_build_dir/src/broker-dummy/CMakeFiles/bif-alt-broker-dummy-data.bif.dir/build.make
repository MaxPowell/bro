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

# Utility rule file for bif-alt-broker-dummy-data.bif.

# Include the progress variables for this target.
include src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-data.bif.dir/progress.make

src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-data.bif: src/broker-dummy/data.bif.h
src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-data.bif: src/broker-dummy/data.bif.cc


src/broker-dummy/data.bif.h: ../src/broker-dummy/data.bif
src/broker-dummy/data.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing data.bif"
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && ../bifcl -s /home/ubuntu/bro/src/broker-dummy/data.bif || ( rm -f data.bif.h data.bif.cc data.bif.init.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && /usr/bin/cmake -E copy data.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/data.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && /usr/bin/cmake -E remove -f data.bif.bro

src/broker-dummy/data.bif.cc: src/broker-dummy/data.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/broker-dummy/data.bif.cc

src/broker-dummy/data.bif.init.cc: src/broker-dummy/data.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/broker-dummy/data.bif.init.cc

scripts/base/bif/data.bif.bro: src/broker-dummy/data.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/data.bif.bro

bif-alt-broker-dummy-data.bif: src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-data.bif
bif-alt-broker-dummy-data.bif: src/broker-dummy/data.bif.h
bif-alt-broker-dummy-data.bif: src/broker-dummy/data.bif.cc
bif-alt-broker-dummy-data.bif: src/broker-dummy/data.bif.init.cc
bif-alt-broker-dummy-data.bif: scripts/base/bif/data.bif.bro
bif-alt-broker-dummy-data.bif: src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-data.bif.dir/build.make

.PHONY : bif-alt-broker-dummy-data.bif

# Rule to build all files generated by this target.
src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-data.bif.dir/build: bif-alt-broker-dummy-data.bif

.PHONY : src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-data.bif.dir/build

src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-data.bif.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && $(CMAKE_COMMAND) -P CMakeFiles/bif-alt-broker-dummy-data.bif.dir/cmake_clean.cmake
.PHONY : src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-data.bif.dir/clean

src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-data.bif.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/broker-dummy /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/broker-dummy /home/ubuntu/bro/my_build_dir/src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-data.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/broker-dummy/CMakeFiles/bif-alt-broker-dummy-data.bif.dir/depend
