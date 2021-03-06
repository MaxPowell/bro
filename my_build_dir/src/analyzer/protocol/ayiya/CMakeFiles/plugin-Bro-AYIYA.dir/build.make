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
include src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/depend.make

# Include the progress variables for this target.
include src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/progress.make

# Include the compile flags for this target's objects.
include src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/flags.make

src/analyzer/protocol/ayiya/ayiya_pac.h: ../src/analyzer/protocol/ayiya/binpac
src/analyzer/protocol/ayiya/ayiya_pac.h: ../src/analyzer/protocol/ayiya/ayiya.pac
src/analyzer/protocol/ayiya/ayiya_pac.h: ../src/binpac.pac
src/analyzer/protocol/ayiya/ayiya_pac.h: ../src/bro.pac
src/analyzer/protocol/ayiya/ayiya_pac.h: ../src/binpac_bro.h
src/analyzer/protocol/ayiya/ayiya_pac.h: ../src/analyzer/protocol/ayiya/ayiya-protocol.pac
src/analyzer/protocol/ayiya/ayiya_pac.h: ../src/analyzer/protocol/ayiya/ayiya-analyzer.pac
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BINPAC] Processing ayiya.pac"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && binpac -q -d /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya -I /home/ubuntu/bro/src/analyzer/protocol/ayiya -I /home/ubuntu/bro/src /home/ubuntu/bro/src/analyzer/protocol/ayiya/ayiya.pac

src/analyzer/protocol/ayiya/ayiya_pac.cc: src/analyzer/protocol/ayiya/ayiya_pac.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/ayiya/ayiya_pac.cc

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/flags.make
src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o: ../src/analyzer/protocol/ayiya/AYIYA.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/ayiya/AYIYA.cc

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/ayiya/AYIYA.cc > CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.i

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/ayiya/AYIYA.cc -o CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.s

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o.requires:

.PHONY : src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o.requires

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o.provides: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/build.make src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o.provides.build
.PHONY : src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o.provides

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o.provides.build: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o


src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/flags.make
src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o: ../src/analyzer/protocol/ayiya/Plugin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/ayiya/Plugin.cc

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/ayiya/Plugin.cc > CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.i

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/ayiya/Plugin.cc -o CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.s

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o.requires:

.PHONY : src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o.requires

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o.provides: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/build.make src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o.provides.build
.PHONY : src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o.provides

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o.provides.build: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o


src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/flags.make
src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o: src/analyzer/protocol/ayiya/ayiya_pac.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya/ayiya_pac.cc

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya/ayiya_pac.cc > CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.i

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya/ayiya_pac.cc -o CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.s

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o.requires:

.PHONY : src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o.requires

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o.provides: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/build.make src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o.provides.build
.PHONY : src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o.provides

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o.provides.build: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o


# Object files for target plugin-Bro-AYIYA
plugin__Bro__AYIYA_OBJECTS = \
"CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o" \
"CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o" \
"CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o"

# External object files for target plugin-Bro-AYIYA
plugin__Bro__AYIYA_EXTERNAL_OBJECTS =

src/analyzer/protocol/ayiya/libplugin-Bro-AYIYA.a: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o
src/analyzer/protocol/ayiya/libplugin-Bro-AYIYA.a: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o
src/analyzer/protocol/ayiya/libplugin-Bro-AYIYA.a: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o
src/analyzer/protocol/ayiya/libplugin-Bro-AYIYA.a: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/build.make
src/analyzer/protocol/ayiya/libplugin-Bro-AYIYA.a: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libplugin-Bro-AYIYA.a"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-AYIYA.dir/cmake_clean_target.cmake
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plugin-Bro-AYIYA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/build: src/analyzer/protocol/ayiya/libplugin-Bro-AYIYA.a

.PHONY : src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/build

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/requires: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/AYIYA.cc.o.requires
src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/requires: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/Plugin.cc.o.requires
src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/requires: src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/ayiya_pac.cc.o.requires

.PHONY : src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/requires

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-AYIYA.dir/cmake_clean.cmake
.PHONY : src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/clean

src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/depend: src/analyzer/protocol/ayiya/ayiya_pac.h
src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/depend: src/analyzer/protocol/ayiya/ayiya_pac.cc
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/analyzer/protocol/ayiya /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/protocol/ayiya/CMakeFiles/plugin-Bro-AYIYA.dir/depend

