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

# Utility rule file for bif-std-strings.bif.

# Include the progress variables for this target.
include src/CMakeFiles/bif-std-strings.bif.dir/progress.make

src/CMakeFiles/bif-std-strings.bif: src/strings.bif.func_h
src/CMakeFiles/bif-std-strings.bif: src/strings.bif.netvar_h
src/CMakeFiles/bif-std-strings.bif: src/strings.bif.func_def
src/CMakeFiles/bif-std-strings.bif: src/strings.bif.func_init
src/CMakeFiles/bif-std-strings.bif: src/strings.bif.netvar_def
src/CMakeFiles/bif-std-strings.bif: src/strings.bif.netvar_init


src/strings.bif.func_def: ../src/strings.bif
src/strings.bif.func_def: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing strings.bif"
	cd /home/ubuntu/bro/my_build_dir/src && ./bifcl /home/ubuntu/bro/src/strings.bif || ( rm -f /home/ubuntu/bro/my_build_dir/src/strings.bif.func_def /home/ubuntu/bro/my_build_dir/src/strings.bif.func_h /home/ubuntu/bro/my_build_dir/src/strings.bif.func_init /home/ubuntu/bro/my_build_dir/src/strings.bif.netvar_def /home/ubuntu/bro/my_build_dir/src/strings.bif.netvar_h /home/ubuntu/bro/my_build_dir/src/strings.bif.netvar_init && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src && /usr/bin/cmake -E copy strings.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/strings.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src && /usr/bin/cmake -E remove -f strings.bif.bro

src/strings.bif.func_h: src/strings.bif.func_def
	@$(CMAKE_COMMAND) -E touch_nocreate src/strings.bif.func_h

src/strings.bif.func_init: src/strings.bif.func_def
	@$(CMAKE_COMMAND) -E touch_nocreate src/strings.bif.func_init

src/strings.bif.netvar_def: src/strings.bif.func_def
	@$(CMAKE_COMMAND) -E touch_nocreate src/strings.bif.netvar_def

src/strings.bif.netvar_h: src/strings.bif.func_def
	@$(CMAKE_COMMAND) -E touch_nocreate src/strings.bif.netvar_h

src/strings.bif.netvar_init: src/strings.bif.func_def
	@$(CMAKE_COMMAND) -E touch_nocreate src/strings.bif.netvar_init

scripts/base/bif/strings.bif.bro: src/strings.bif.func_def
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/strings.bif.bro

bif-std-strings.bif: src/CMakeFiles/bif-std-strings.bif
bif-std-strings.bif: src/strings.bif.func_def
bif-std-strings.bif: src/strings.bif.func_h
bif-std-strings.bif: src/strings.bif.func_init
bif-std-strings.bif: src/strings.bif.netvar_def
bif-std-strings.bif: src/strings.bif.netvar_h
bif-std-strings.bif: src/strings.bif.netvar_init
bif-std-strings.bif: scripts/base/bif/strings.bif.bro
bif-std-strings.bif: src/CMakeFiles/bif-std-strings.bif.dir/build.make

.PHONY : bif-std-strings.bif

# Rule to build all files generated by this target.
src/CMakeFiles/bif-std-strings.bif.dir/build: bif-std-strings.bif

.PHONY : src/CMakeFiles/bif-std-strings.bif.dir/build

src/CMakeFiles/bif-std-strings.bif.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src && $(CMAKE_COMMAND) -P CMakeFiles/bif-std-strings.bif.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/bif-std-strings.bif.dir/clean

src/CMakeFiles/bif-std-strings.bif.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src /home/ubuntu/bro/my_build_dir/src/CMakeFiles/bif-std-strings.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/bif-std-strings.bif.dir/depend

