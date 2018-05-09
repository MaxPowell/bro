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

# Utility rule file for bif-plugin-Bro_Login-events.bif.

# Include the progress variables for this target.
include src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif.dir/progress.make

src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif: src/analyzer/protocol/login/events.bif.h
src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif: src/analyzer/protocol/login/events.bif.cc
src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif: src/analyzer/protocol/login/events.bif.init.cc


src/analyzer/protocol/login/events.bif.h: ../src/analyzer/protocol/login/events.bif
src/analyzer/protocol/login/events.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing events.bif"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/login && ../../../bifcl -p Bro::Login /home/ubuntu/bro/src/analyzer/protocol/login/events.bif || ( rm -f events.bif.h events.bif.cc events.bif.init.cc events.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/login && /usr/bin/cmake -E copy events.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_Login.events.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/login && /usr/bin/cmake -E remove -f events.bif.bro

src/analyzer/protocol/login/events.bif.cc: src/analyzer/protocol/login/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/login/events.bif.cc

src/analyzer/protocol/login/events.bif.init.cc: src/analyzer/protocol/login/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/login/events.bif.init.cc

src/analyzer/protocol/login/events.bif.register.cc: src/analyzer/protocol/login/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/login/events.bif.register.cc

scripts/base/bif/plugins/Bro_Login.events.bif.bro: src/analyzer/protocol/login/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_Login.events.bif.bro

bif-plugin-Bro_Login-events.bif: src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif
bif-plugin-Bro_Login-events.bif: src/analyzer/protocol/login/events.bif.h
bif-plugin-Bro_Login-events.bif: src/analyzer/protocol/login/events.bif.cc
bif-plugin-Bro_Login-events.bif: src/analyzer/protocol/login/events.bif.init.cc
bif-plugin-Bro_Login-events.bif: src/analyzer/protocol/login/events.bif.register.cc
bif-plugin-Bro_Login-events.bif: scripts/base/bif/plugins/Bro_Login.events.bif.bro
bif-plugin-Bro_Login-events.bif: src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif.dir/build.make

.PHONY : bif-plugin-Bro_Login-events.bif

# Rule to build all files generated by this target.
src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif.dir/build: bif-plugin-Bro_Login-events.bif

.PHONY : src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif.dir/build

src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/login && $(CMAKE_COMMAND) -P CMakeFiles/bif-plugin-Bro_Login-events.bif.dir/cmake_clean.cmake
.PHONY : src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif.dir/clean

src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/analyzer/protocol/login /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/login /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/protocol/login/CMakeFiles/bif-plugin-Bro_Login-events.bif.dir/depend

