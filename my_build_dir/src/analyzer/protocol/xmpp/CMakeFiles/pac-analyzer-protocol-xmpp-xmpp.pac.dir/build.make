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

# Utility rule file for pac-analyzer-protocol-xmpp-xmpp.pac.

# Include the progress variables for this target.
include src/analyzer/protocol/xmpp/CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac.dir/progress.make

src/analyzer/protocol/xmpp/CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac: src/analyzer/protocol/xmpp/xmpp_pac.h
src/analyzer/protocol/xmpp/CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac: src/analyzer/protocol/xmpp/xmpp_pac.cc


src/analyzer/protocol/xmpp/xmpp_pac.h: aux/binpac/src/binpac
src/analyzer/protocol/xmpp/xmpp_pac.h: ../src/analyzer/protocol/xmpp/xmpp.pac
src/analyzer/protocol/xmpp/xmpp_pac.h: ../src/binpac.pac
src/analyzer/protocol/xmpp/xmpp_pac.h: ../src/bro.pac
src/analyzer/protocol/xmpp/xmpp_pac.h: ../src/binpac_bro.h
src/analyzer/protocol/xmpp/xmpp_pac.h: ../src/analyzer/protocol/xmpp/xmpp-analyzer.pac
src/analyzer/protocol/xmpp/xmpp_pac.h: ../src/analyzer/protocol/xmpp/xmpp-protocol.pac
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BINPAC] Processing xmpp.pac"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/xmpp && ../../../../aux/binpac/src/binpac -q -d /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/xmpp -I /home/ubuntu/bro/src/analyzer/protocol/xmpp -I /home/ubuntu/bro/src /home/ubuntu/bro/src/analyzer/protocol/xmpp/xmpp.pac

src/analyzer/protocol/xmpp/xmpp_pac.cc: src/analyzer/protocol/xmpp/xmpp_pac.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/xmpp/xmpp_pac.cc

pac-analyzer-protocol-xmpp-xmpp.pac: src/analyzer/protocol/xmpp/CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac
pac-analyzer-protocol-xmpp-xmpp.pac: src/analyzer/protocol/xmpp/xmpp_pac.h
pac-analyzer-protocol-xmpp-xmpp.pac: src/analyzer/protocol/xmpp/xmpp_pac.cc
pac-analyzer-protocol-xmpp-xmpp.pac: src/analyzer/protocol/xmpp/CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac.dir/build.make

.PHONY : pac-analyzer-protocol-xmpp-xmpp.pac

# Rule to build all files generated by this target.
src/analyzer/protocol/xmpp/CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac.dir/build: pac-analyzer-protocol-xmpp-xmpp.pac

.PHONY : src/analyzer/protocol/xmpp/CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac.dir/build

src/analyzer/protocol/xmpp/CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/xmpp && $(CMAKE_COMMAND) -P CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac.dir/cmake_clean.cmake
.PHONY : src/analyzer/protocol/xmpp/CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac.dir/clean

src/analyzer/protocol/xmpp/CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/analyzer/protocol/xmpp /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/xmpp /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/xmpp/CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/protocol/xmpp/CMakeFiles/pac-analyzer-protocol-xmpp-xmpp.pac.dir/depend

