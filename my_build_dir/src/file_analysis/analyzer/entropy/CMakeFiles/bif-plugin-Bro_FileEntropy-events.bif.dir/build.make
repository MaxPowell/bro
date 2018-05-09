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

# Utility rule file for bif-plugin-Bro_FileEntropy-events.bif.

# Include the progress variables for this target.
include src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif.dir/progress.make

src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif: src/file_analysis/analyzer/entropy/events.bif.h
src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif: src/file_analysis/analyzer/entropy/events.bif.cc
src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif: src/file_analysis/analyzer/entropy/events.bif.init.cc


src/file_analysis/analyzer/entropy/events.bif.h: ../src/file_analysis/analyzer/entropy/events.bif
src/file_analysis/analyzer/entropy/events.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing events.bif"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/entropy && ../../../bifcl -p Bro::FileEntropy /home/ubuntu/bro/src/file_analysis/analyzer/entropy/events.bif || ( rm -f events.bif.h events.bif.cc events.bif.init.cc events.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/entropy && /usr/bin/cmake -E copy events.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_FileEntropy.events.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/entropy && /usr/bin/cmake -E remove -f events.bif.bro

src/file_analysis/analyzer/entropy/events.bif.cc: src/file_analysis/analyzer/entropy/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/file_analysis/analyzer/entropy/events.bif.cc

src/file_analysis/analyzer/entropy/events.bif.init.cc: src/file_analysis/analyzer/entropy/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/file_analysis/analyzer/entropy/events.bif.init.cc

src/file_analysis/analyzer/entropy/events.bif.register.cc: src/file_analysis/analyzer/entropy/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/file_analysis/analyzer/entropy/events.bif.register.cc

scripts/base/bif/plugins/Bro_FileEntropy.events.bif.bro: src/file_analysis/analyzer/entropy/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_FileEntropy.events.bif.bro

bif-plugin-Bro_FileEntropy-events.bif: src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif
bif-plugin-Bro_FileEntropy-events.bif: src/file_analysis/analyzer/entropy/events.bif.h
bif-plugin-Bro_FileEntropy-events.bif: src/file_analysis/analyzer/entropy/events.bif.cc
bif-plugin-Bro_FileEntropy-events.bif: src/file_analysis/analyzer/entropy/events.bif.init.cc
bif-plugin-Bro_FileEntropy-events.bif: src/file_analysis/analyzer/entropy/events.bif.register.cc
bif-plugin-Bro_FileEntropy-events.bif: scripts/base/bif/plugins/Bro_FileEntropy.events.bif.bro
bif-plugin-Bro_FileEntropy-events.bif: src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif.dir/build.make

.PHONY : bif-plugin-Bro_FileEntropy-events.bif

# Rule to build all files generated by this target.
src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif.dir/build: bif-plugin-Bro_FileEntropy-events.bif

.PHONY : src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif.dir/build

src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/entropy && $(CMAKE_COMMAND) -P CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif.dir/cmake_clean.cmake
.PHONY : src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif.dir/clean

src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/file_analysis/analyzer/entropy /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/entropy /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/file_analysis/analyzer/entropy/CMakeFiles/bif-plugin-Bro_FileEntropy-events.bif.dir/depend

