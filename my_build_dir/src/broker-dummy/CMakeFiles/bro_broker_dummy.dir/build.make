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

# Include any dependencies generated for this target.
include src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/depend.make

# Include the progress variables for this target.
include src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/progress.make

# Include the compile flags for this target's objects.
include src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/flags.make

src/broker-dummy/store.bif.h: ../src/broker-dummy/store.bif
src/broker-dummy/store.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing store.bif"
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && ../bifcl -s /home/ubuntu/bro/src/broker-dummy/store.bif || ( rm -f store.bif.h store.bif.cc store.bif.init.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && /usr/bin/cmake -E copy store.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/store.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && /usr/bin/cmake -E remove -f store.bif.bro

src/broker-dummy/store.bif.cc: src/broker-dummy/store.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/broker-dummy/store.bif.cc

src/broker-dummy/store.bif.init.cc: src/broker-dummy/store.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/broker-dummy/store.bif.init.cc

scripts/base/bif/store.bif.bro: src/broker-dummy/store.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/store.bif.bro

src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o: src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/flags.make
src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o: src/broker-dummy/store.bif.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o -c /home/ubuntu/bro/my_build_dir/src/broker-dummy/store.bif.cc

src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bro_broker_dummy.dir/store.bif.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/broker-dummy/store.bif.cc > CMakeFiles/bro_broker_dummy.dir/store.bif.cc.i

src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bro_broker_dummy.dir/store.bif.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/broker-dummy/store.bif.cc -o CMakeFiles/bro_broker_dummy.dir/store.bif.cc.s

src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o.requires:

.PHONY : src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o.requires

src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o.provides: src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o.requires
	$(MAKE) -f src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/build.make src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o.provides.build
.PHONY : src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o.provides

src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o.provides.build: src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o


# Object files for target bro_broker_dummy
bro_broker_dummy_OBJECTS = \
"CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o"

# External object files for target bro_broker_dummy
bro_broker_dummy_EXTERNAL_OBJECTS =

src/broker-dummy/libbro_broker_dummy.a: src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o
src/broker-dummy/libbro_broker_dummy.a: src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/build.make
src/broker-dummy/libbro_broker_dummy.a: src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libbro_broker_dummy.a"
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && $(CMAKE_COMMAND) -P CMakeFiles/bro_broker_dummy.dir/cmake_clean_target.cmake
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bro_broker_dummy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/build: src/broker-dummy/libbro_broker_dummy.a

.PHONY : src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/build

src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/requires: src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/store.bif.cc.o.requires

.PHONY : src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/requires

src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/broker-dummy && $(CMAKE_COMMAND) -P CMakeFiles/bro_broker_dummy.dir/cmake_clean.cmake
.PHONY : src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/clean

src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/depend: src/broker-dummy/store.bif.h
src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/depend: src/broker-dummy/store.bif.cc
src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/depend: src/broker-dummy/store.bif.init.cc
src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/depend: scripts/base/bif/store.bif.bro
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/broker-dummy /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/broker-dummy /home/ubuntu/bro/my_build_dir/src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/broker-dummy/CMakeFiles/bro_broker_dummy.dir/depend
