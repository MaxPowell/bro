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

# Utility rule file for pac-analyzer-protocol-sip-sip_TCP.pac.

# Include the progress variables for this target.
include src/analyzer/protocol/sip/CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac.dir/progress.make

src/analyzer/protocol/sip/CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac: src/analyzer/protocol/sip/sip_TCP_pac.h
src/analyzer/protocol/sip/CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac: src/analyzer/protocol/sip/sip_TCP_pac.cc


src/analyzer/protocol/sip/sip_TCP_pac.h: ../src/analyzer/protocol/sip/binpac
src/analyzer/protocol/sip/sip_TCP_pac.h: ../src/analyzer/protocol/sip/sip_TCP.pac
src/analyzer/protocol/sip/sip_TCP_pac.h: ../src/binpac.pac
src/analyzer/protocol/sip/sip_TCP_pac.h: ../src/bro.pac
src/analyzer/protocol/sip/sip_TCP_pac.h: ../src/binpac_bro.h
src/analyzer/protocol/sip/sip_TCP_pac.h: ../src/analyzer/protocol/sip/sip-protocol.pac
src/analyzer/protocol/sip/sip_TCP_pac.h: ../src/analyzer/protocol/sip/sip-analyzer.pac
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BINPAC] Processing sip_TCP.pac"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/sip && binpac -q -d /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/sip -I /home/ubuntu/bro/src/analyzer/protocol/sip -I /home/ubuntu/bro/src /home/ubuntu/bro/src/analyzer/protocol/sip/sip_TCP.pac

src/analyzer/protocol/sip/sip_TCP_pac.cc: src/analyzer/protocol/sip/sip_TCP_pac.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/sip/sip_TCP_pac.cc

pac-analyzer-protocol-sip-sip_TCP.pac: src/analyzer/protocol/sip/CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac
pac-analyzer-protocol-sip-sip_TCP.pac: src/analyzer/protocol/sip/sip_TCP_pac.h
pac-analyzer-protocol-sip-sip_TCP.pac: src/analyzer/protocol/sip/sip_TCP_pac.cc
pac-analyzer-protocol-sip-sip_TCP.pac: src/analyzer/protocol/sip/CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac.dir/build.make

.PHONY : pac-analyzer-protocol-sip-sip_TCP.pac

# Rule to build all files generated by this target.
src/analyzer/protocol/sip/CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac.dir/build: pac-analyzer-protocol-sip-sip_TCP.pac

.PHONY : src/analyzer/protocol/sip/CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac.dir/build

src/analyzer/protocol/sip/CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/sip && $(CMAKE_COMMAND) -P CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac.dir/cmake_clean.cmake
.PHONY : src/analyzer/protocol/sip/CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac.dir/clean

src/analyzer/protocol/sip/CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/analyzer/protocol/sip /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/sip /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/sip/CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/protocol/sip/CMakeFiles/pac-analyzer-protocol-sip-sip_TCP.pac.dir/depend

