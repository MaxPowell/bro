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
include src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/depend.make

# Include the progress variables for this target.
include src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/progress.make

# Include the compile flags for this target's objects.
include src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/flags.make

src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o: src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/flags.make
src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o: ../src/iosource/dpdk/Source.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/iosource/dpdk && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o -c /home/ubuntu/bro/src/iosource/dpdk/Source.cc

src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/iosource/dpdk && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/iosource/dpdk/Source.cc > CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.i

src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/iosource/dpdk && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/iosource/dpdk/Source.cc -o CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.s

src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o.requires:

.PHONY : src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o.requires

src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o.provides: src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o.requires
	$(MAKE) -f src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/build.make src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o.provides.build
.PHONY : src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o.provides

src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o.provides.build: src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o


# Object files for target plugin-Bro-Dpdk
plugin__Bro__Dpdk_OBJECTS = \
"CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o"

# External object files for target plugin-Bro-Dpdk
plugin__Bro__Dpdk_EXTERNAL_OBJECTS =

src/iosource/dpdk/libplugin-Bro-Dpdk.a: src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o
src/iosource/dpdk/libplugin-Bro-Dpdk.a: src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/build.make
src/iosource/dpdk/libplugin-Bro-Dpdk.a: src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libplugin-Bro-Dpdk.a"
	cd /home/ubuntu/bro/my_build_dir/src/iosource/dpdk && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-Dpdk.dir/cmake_clean_target.cmake
	cd /home/ubuntu/bro/my_build_dir/src/iosource/dpdk && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plugin-Bro-Dpdk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/build: src/iosource/dpdk/libplugin-Bro-Dpdk.a

.PHONY : src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/build

src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/requires: src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/Source.cc.o.requires

.PHONY : src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/requires

src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/iosource/dpdk && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-Dpdk.dir/cmake_clean.cmake
.PHONY : src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/clean

src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/iosource/dpdk /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/iosource/dpdk /home/ubuntu/bro/my_build_dir/src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/iosource/dpdk/CMakeFiles/plugin-Bro-Dpdk.dir/depend

