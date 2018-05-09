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

# Utility rule file for bif-alt-logging-logging.bif.

# Include the progress variables for this target.
include src/logging/CMakeFiles/bif-alt-logging-logging.bif.dir/progress.make

src/logging/CMakeFiles/bif-alt-logging-logging.bif: src/logging/logging.bif.h
src/logging/CMakeFiles/bif-alt-logging-logging.bif: src/logging/logging.bif.cc


src/logging/logging.bif.h: ../src/logging/logging.bif
src/logging/logging.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing logging.bif"
	cd /home/ubuntu/bro/my_build_dir/src/logging && ../bifcl -s /home/ubuntu/bro/src/logging/logging.bif || ( rm -f logging.bif.h logging.bif.cc logging.bif.init.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/logging && /usr/bin/cmake -E copy logging.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/logging.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/logging && /usr/bin/cmake -E remove -f logging.bif.bro

src/logging/logging.bif.cc: src/logging/logging.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/logging/logging.bif.cc

src/logging/logging.bif.init.cc: src/logging/logging.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/logging/logging.bif.init.cc

scripts/base/bif/logging.bif.bro: src/logging/logging.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/logging.bif.bro

bif-alt-logging-logging.bif: src/logging/CMakeFiles/bif-alt-logging-logging.bif
bif-alt-logging-logging.bif: src/logging/logging.bif.h
bif-alt-logging-logging.bif: src/logging/logging.bif.cc
bif-alt-logging-logging.bif: src/logging/logging.bif.init.cc
bif-alt-logging-logging.bif: scripts/base/bif/logging.bif.bro
bif-alt-logging-logging.bif: src/logging/CMakeFiles/bif-alt-logging-logging.bif.dir/build.make

.PHONY : bif-alt-logging-logging.bif

# Rule to build all files generated by this target.
src/logging/CMakeFiles/bif-alt-logging-logging.bif.dir/build: bif-alt-logging-logging.bif

.PHONY : src/logging/CMakeFiles/bif-alt-logging-logging.bif.dir/build

src/logging/CMakeFiles/bif-alt-logging-logging.bif.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/logging && $(CMAKE_COMMAND) -P CMakeFiles/bif-alt-logging-logging.bif.dir/cmake_clean.cmake
.PHONY : src/logging/CMakeFiles/bif-alt-logging-logging.bif.dir/clean

src/logging/CMakeFiles/bif-alt-logging-logging.bif.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/logging /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/logging /home/ubuntu/bro/my_build_dir/src/logging/CMakeFiles/bif-alt-logging-logging.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/logging/CMakeFiles/bif-alt-logging-logging.bif.dir/depend

