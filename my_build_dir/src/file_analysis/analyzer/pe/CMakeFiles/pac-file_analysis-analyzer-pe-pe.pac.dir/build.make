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

# Utility rule file for pac-file_analysis-analyzer-pe-pe.pac.

# Include the progress variables for this target.
include src/file_analysis/analyzer/pe/CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac.dir/progress.make

src/file_analysis/analyzer/pe/CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac: src/file_analysis/analyzer/pe/pe_pac.h
src/file_analysis/analyzer/pe/CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac: src/file_analysis/analyzer/pe/pe_pac.cc


src/file_analysis/analyzer/pe/pe_pac.h: ../src/file_analysis/analyzer/pe/binpac
src/file_analysis/analyzer/pe/pe_pac.h: ../src/file_analysis/analyzer/pe/pe.pac
src/file_analysis/analyzer/pe/pe_pac.h: ../src/binpac.pac
src/file_analysis/analyzer/pe/pe_pac.h: ../src/bro.pac
src/file_analysis/analyzer/pe/pe_pac.h: ../src/binpac_bro.h
src/file_analysis/analyzer/pe/pe_pac.h: ../src/file_analysis/analyzer/pe/pe-file.pac
src/file_analysis/analyzer/pe/pe_pac.h: ../src/file_analysis/analyzer/pe/pe-analyzer.pac
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BINPAC] Processing pe.pac"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/pe && binpac -q -d /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/pe -I /home/ubuntu/bro/src/file_analysis/analyzer/pe -I /home/ubuntu/bro/src /home/ubuntu/bro/src/file_analysis/analyzer/pe/pe.pac

src/file_analysis/analyzer/pe/pe_pac.cc: src/file_analysis/analyzer/pe/pe_pac.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/file_analysis/analyzer/pe/pe_pac.cc

pac-file_analysis-analyzer-pe-pe.pac: src/file_analysis/analyzer/pe/CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac
pac-file_analysis-analyzer-pe-pe.pac: src/file_analysis/analyzer/pe/pe_pac.h
pac-file_analysis-analyzer-pe-pe.pac: src/file_analysis/analyzer/pe/pe_pac.cc
pac-file_analysis-analyzer-pe-pe.pac: src/file_analysis/analyzer/pe/CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac.dir/build.make

.PHONY : pac-file_analysis-analyzer-pe-pe.pac

# Rule to build all files generated by this target.
src/file_analysis/analyzer/pe/CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac.dir/build: pac-file_analysis-analyzer-pe-pe.pac

.PHONY : src/file_analysis/analyzer/pe/CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac.dir/build

src/file_analysis/analyzer/pe/CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/pe && $(CMAKE_COMMAND) -P CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac.dir/cmake_clean.cmake
.PHONY : src/file_analysis/analyzer/pe/CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac.dir/clean

src/file_analysis/analyzer/pe/CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/file_analysis/analyzer/pe /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/pe /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/pe/CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/file_analysis/analyzer/pe/CMakeFiles/pac-file_analysis-analyzer-pe-pe.pac.dir/depend
