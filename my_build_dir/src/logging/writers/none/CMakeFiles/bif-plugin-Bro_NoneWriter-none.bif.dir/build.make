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

# Utility rule file for bif-plugin-Bro_NoneWriter-none.bif.

# Include the progress variables for this target.
include src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif.dir/progress.make

src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif: src/logging/writers/none/none.bif.h
src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif: src/logging/writers/none/none.bif.cc
src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif: src/logging/writers/none/none.bif.init.cc


src/logging/writers/none/none.bif.h: ../src/logging/writers/none/none.bif
src/logging/writers/none/none.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing none.bif"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && ../../../bifcl -p Bro::NoneWriter /home/ubuntu/bro/src/logging/writers/none/none.bif || ( rm -f none.bif.h none.bif.cc none.bif.init.cc none.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/cmake -E copy none.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_NoneWriter.none.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/cmake -E remove -f none.bif.bro

src/logging/writers/none/none.bif.cc: src/logging/writers/none/none.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/logging/writers/none/none.bif.cc

src/logging/writers/none/none.bif.init.cc: src/logging/writers/none/none.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/logging/writers/none/none.bif.init.cc

src/logging/writers/none/none.bif.register.cc: src/logging/writers/none/none.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/logging/writers/none/none.bif.register.cc

scripts/base/bif/plugins/Bro_NoneWriter.none.bif.bro: src/logging/writers/none/none.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_NoneWriter.none.bif.bro

bif-plugin-Bro_NoneWriter-none.bif: src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif
bif-plugin-Bro_NoneWriter-none.bif: src/logging/writers/none/none.bif.h
bif-plugin-Bro_NoneWriter-none.bif: src/logging/writers/none/none.bif.cc
bif-plugin-Bro_NoneWriter-none.bif: src/logging/writers/none/none.bif.init.cc
bif-plugin-Bro_NoneWriter-none.bif: src/logging/writers/none/none.bif.register.cc
bif-plugin-Bro_NoneWriter-none.bif: scripts/base/bif/plugins/Bro_NoneWriter.none.bif.bro
bif-plugin-Bro_NoneWriter-none.bif: src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif.dir/build.make

.PHONY : bif-plugin-Bro_NoneWriter-none.bif

# Rule to build all files generated by this target.
src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif.dir/build: bif-plugin-Bro_NoneWriter-none.bif

.PHONY : src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif.dir/build

src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && $(CMAKE_COMMAND) -P CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif.dir/cmake_clean.cmake
.PHONY : src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif.dir/clean

src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/logging/writers/none /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/logging/writers/none /home/ubuntu/bro/my_build_dir/src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/logging/writers/none/CMakeFiles/bif-plugin-Bro_NoneWriter-none.bif.dir/depend

