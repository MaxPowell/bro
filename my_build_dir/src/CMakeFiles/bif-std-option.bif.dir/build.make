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

# Utility rule file for bif-std-option.bif.

# Include the progress variables for this target.
include src/CMakeFiles/bif-std-option.bif.dir/progress.make

src/CMakeFiles/bif-std-option.bif: src/option.bif.func_h
src/CMakeFiles/bif-std-option.bif: src/option.bif.netvar_h
src/CMakeFiles/bif-std-option.bif: src/option.bif.func_def
src/CMakeFiles/bif-std-option.bif: src/option.bif.func_init
src/CMakeFiles/bif-std-option.bif: src/option.bif.netvar_def
src/CMakeFiles/bif-std-option.bif: src/option.bif.netvar_init


src/option.bif.func_def: ../src/option.bif
src/option.bif.func_def: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing option.bif"
	cd /home/ubuntu/bro/my_build_dir/src && ./bifcl /home/ubuntu/bro/src/option.bif || ( rm -f /home/ubuntu/bro/my_build_dir/src/option.bif.func_def /home/ubuntu/bro/my_build_dir/src/option.bif.func_h /home/ubuntu/bro/my_build_dir/src/option.bif.func_init /home/ubuntu/bro/my_build_dir/src/option.bif.netvar_def /home/ubuntu/bro/my_build_dir/src/option.bif.netvar_h /home/ubuntu/bro/my_build_dir/src/option.bif.netvar_init && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src && /usr/bin/cmake -E copy option.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/option.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src && /usr/bin/cmake -E remove -f option.bif.bro

src/option.bif.func_h: src/option.bif.func_def
	@$(CMAKE_COMMAND) -E touch_nocreate src/option.bif.func_h

src/option.bif.func_init: src/option.bif.func_def
	@$(CMAKE_COMMAND) -E touch_nocreate src/option.bif.func_init

src/option.bif.netvar_def: src/option.bif.func_def
	@$(CMAKE_COMMAND) -E touch_nocreate src/option.bif.netvar_def

src/option.bif.netvar_h: src/option.bif.func_def
	@$(CMAKE_COMMAND) -E touch_nocreate src/option.bif.netvar_h

src/option.bif.netvar_init: src/option.bif.func_def
	@$(CMAKE_COMMAND) -E touch_nocreate src/option.bif.netvar_init

scripts/base/bif/option.bif.bro: src/option.bif.func_def
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/option.bif.bro

bif-std-option.bif: src/CMakeFiles/bif-std-option.bif
bif-std-option.bif: src/option.bif.func_def
bif-std-option.bif: src/option.bif.func_h
bif-std-option.bif: src/option.bif.func_init
bif-std-option.bif: src/option.bif.netvar_def
bif-std-option.bif: src/option.bif.netvar_h
bif-std-option.bif: src/option.bif.netvar_init
bif-std-option.bif: scripts/base/bif/option.bif.bro
bif-std-option.bif: src/CMakeFiles/bif-std-option.bif.dir/build.make

.PHONY : bif-std-option.bif

# Rule to build all files generated by this target.
src/CMakeFiles/bif-std-option.bif.dir/build: bif-std-option.bif

.PHONY : src/CMakeFiles/bif-std-option.bif.dir/build

src/CMakeFiles/bif-std-option.bif.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src && $(CMAKE_COMMAND) -P CMakeFiles/bif-std-option.bif.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/bif-std-option.bif.dir/clean

src/CMakeFiles/bif-std-option.bif.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src /home/ubuntu/bro/my_build_dir/src/CMakeFiles/bif-std-option.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/bif-std-option.bif.dir/depend

