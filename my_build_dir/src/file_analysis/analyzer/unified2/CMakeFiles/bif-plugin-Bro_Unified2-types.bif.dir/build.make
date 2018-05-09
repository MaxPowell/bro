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

# Utility rule file for bif-plugin-Bro_Unified2-types.bif.

# Include the progress variables for this target.
include src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif.dir/progress.make

src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif: src/file_analysis/analyzer/unified2/types.bif.h
src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif: src/file_analysis/analyzer/unified2/types.bif.cc
src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif: src/file_analysis/analyzer/unified2/types.bif.init.cc


src/file_analysis/analyzer/unified2/types.bif.h: ../src/file_analysis/analyzer/unified2/types.bif
src/file_analysis/analyzer/unified2/types.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing types.bif"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/unified2 && ../../../bifcl -p Bro::Unified2 /home/ubuntu/bro/src/file_analysis/analyzer/unified2/types.bif || ( rm -f types.bif.h types.bif.cc types.bif.init.cc types.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/unified2 && /usr/bin/cmake -E copy types.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_Unified2.types.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/unified2 && /usr/bin/cmake -E remove -f types.bif.bro

src/file_analysis/analyzer/unified2/types.bif.cc: src/file_analysis/analyzer/unified2/types.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/file_analysis/analyzer/unified2/types.bif.cc

src/file_analysis/analyzer/unified2/types.bif.init.cc: src/file_analysis/analyzer/unified2/types.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/file_analysis/analyzer/unified2/types.bif.init.cc

src/file_analysis/analyzer/unified2/types.bif.register.cc: src/file_analysis/analyzer/unified2/types.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/file_analysis/analyzer/unified2/types.bif.register.cc

scripts/base/bif/plugins/Bro_Unified2.types.bif.bro: src/file_analysis/analyzer/unified2/types.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_Unified2.types.bif.bro

bif-plugin-Bro_Unified2-types.bif: src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif
bif-plugin-Bro_Unified2-types.bif: src/file_analysis/analyzer/unified2/types.bif.h
bif-plugin-Bro_Unified2-types.bif: src/file_analysis/analyzer/unified2/types.bif.cc
bif-plugin-Bro_Unified2-types.bif: src/file_analysis/analyzer/unified2/types.bif.init.cc
bif-plugin-Bro_Unified2-types.bif: src/file_analysis/analyzer/unified2/types.bif.register.cc
bif-plugin-Bro_Unified2-types.bif: scripts/base/bif/plugins/Bro_Unified2.types.bif.bro
bif-plugin-Bro_Unified2-types.bif: src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif.dir/build.make

.PHONY : bif-plugin-Bro_Unified2-types.bif

# Rule to build all files generated by this target.
src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif.dir/build: bif-plugin-Bro_Unified2-types.bif

.PHONY : src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif.dir/build

src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/unified2 && $(CMAKE_COMMAND) -P CMakeFiles/bif-plugin-Bro_Unified2-types.bif.dir/cmake_clean.cmake
.PHONY : src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif.dir/clean

src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/file_analysis/analyzer/unified2 /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/unified2 /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/file_analysis/analyzer/unified2/CMakeFiles/bif-plugin-Bro_Unified2-types.bif.dir/depend

