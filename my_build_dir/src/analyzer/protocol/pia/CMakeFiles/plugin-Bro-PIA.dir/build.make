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
include src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/depend.make

# Include the progress variables for this target.
include src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/progress.make

# Include the compile flags for this target's objects.
include src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/flags.make

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o: src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/flags.make
src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o: ../src/analyzer/protocol/pia/PIA.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/pia && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/pia/PIA.cc

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/pia && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/pia/PIA.cc > CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.i

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/pia && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/pia/PIA.cc -o CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.s

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o.requires:

.PHONY : src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o.requires

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o.provides: src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/build.make src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o.provides.build
.PHONY : src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o.provides

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o.provides.build: src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o


src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o: src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/flags.make
src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o: ../src/analyzer/protocol/pia/Plugin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/pia && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/pia/Plugin.cc

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/pia && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/pia/Plugin.cc > CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.i

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/pia && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/pia/Plugin.cc -o CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.s

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o.requires:

.PHONY : src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o.requires

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o.provides: src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/build.make src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o.provides.build
.PHONY : src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o.provides

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o.provides.build: src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o


# Object files for target plugin-Bro-PIA
plugin__Bro__PIA_OBJECTS = \
"CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o" \
"CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o"

# External object files for target plugin-Bro-PIA
plugin__Bro__PIA_EXTERNAL_OBJECTS =

src/analyzer/protocol/pia/libplugin-Bro-PIA.a: src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o
src/analyzer/protocol/pia/libplugin-Bro-PIA.a: src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o
src/analyzer/protocol/pia/libplugin-Bro-PIA.a: src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/build.make
src/analyzer/protocol/pia/libplugin-Bro-PIA.a: src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libplugin-Bro-PIA.a"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/pia && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-PIA.dir/cmake_clean_target.cmake
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/pia && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plugin-Bro-PIA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/build: src/analyzer/protocol/pia/libplugin-Bro-PIA.a

.PHONY : src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/build

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/requires: src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/PIA.cc.o.requires
src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/requires: src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/Plugin.cc.o.requires

.PHONY : src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/requires

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/pia && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-PIA.dir/cmake_clean.cmake
.PHONY : src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/clean

src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/analyzer/protocol/pia /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/pia /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/protocol/pia/CMakeFiles/plugin-Bro-PIA.dir/depend

