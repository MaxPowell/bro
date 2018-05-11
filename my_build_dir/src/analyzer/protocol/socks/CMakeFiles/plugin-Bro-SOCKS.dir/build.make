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
include src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/depend.make

# Include the progress variables for this target.
include src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/progress.make

# Include the compile flags for this target's objects.
include src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/flags.make

src/analyzer/protocol/socks/events.bif.h: ../src/analyzer/protocol/socks/events.bif
src/analyzer/protocol/socks/events.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing events.bif"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && ../../../bifcl -p Bro::SOCKS /home/ubuntu/bro/src/analyzer/protocol/socks/events.bif || ( rm -f events.bif.h events.bif.cc events.bif.init.cc events.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/cmake -E copy events.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_SOCKS.events.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/cmake -E remove -f events.bif.bro

src/analyzer/protocol/socks/events.bif.cc: src/analyzer/protocol/socks/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/socks/events.bif.cc

src/analyzer/protocol/socks/events.bif.init.cc: src/analyzer/protocol/socks/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/socks/events.bif.init.cc

src/analyzer/protocol/socks/events.bif.register.cc: src/analyzer/protocol/socks/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/socks/events.bif.register.cc

scripts/base/bif/plugins/Bro_SOCKS.events.bif.bro: src/analyzer/protocol/socks/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_SOCKS.events.bif.bro

src/analyzer/protocol/socks/socks_pac.h: ../src/analyzer/protocol/socks/binpac
src/analyzer/protocol/socks/socks_pac.h: ../src/analyzer/protocol/socks/socks.pac
src/analyzer/protocol/socks/socks_pac.h: ../src/binpac.pac
src/analyzer/protocol/socks/socks_pac.h: ../src/bro.pac
src/analyzer/protocol/socks/socks_pac.h: ../src/binpac_bro.h
src/analyzer/protocol/socks/socks_pac.h: ../src/analyzer/protocol/socks/socks-protocol.pac
src/analyzer/protocol/socks/socks_pac.h: ../src/analyzer/protocol/socks/socks-analyzer.pac
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[BINPAC] Processing socks.pac"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && binpac -q -d /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks -I /home/ubuntu/bro/src/analyzer/protocol/socks -I /home/ubuntu/bro/src /home/ubuntu/bro/src/analyzer/protocol/socks/socks.pac

src/analyzer/protocol/socks/socks_pac.cc: src/analyzer/protocol/socks/socks_pac.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/socks/socks_pac.cc

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/flags.make
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o: ../src/analyzer/protocol/socks/SOCKS.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/socks/SOCKS.cc

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/socks/SOCKS.cc > CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.i

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/socks/SOCKS.cc -o CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.s

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o.requires:

.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o.requires

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o.provides: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/build.make src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o.provides.build
.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o.provides

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o.provides.build: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o


src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/flags.make
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o: ../src/analyzer/protocol/socks/Plugin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/socks/Plugin.cc

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/socks/Plugin.cc > CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.i

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/socks/Plugin.cc -o CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.s

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o.requires:

.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o.requires

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o.provides: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/build.make src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o.provides.build
.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o.provides

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o.provides.build: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o


src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/flags.make
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o: src/analyzer/protocol/socks/events.bif.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks/events.bif.cc

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks/events.bif.cc > CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.i

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks/events.bif.cc -o CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.s

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o.requires:

.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o.requires

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o.provides: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/build.make src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o.provides.build
.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o.provides

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o.provides.build: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o


src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/flags.make
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o: src/analyzer/protocol/socks/events.bif.init.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks/events.bif.init.cc

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks/events.bif.init.cc > CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.i

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks/events.bif.init.cc -o CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.s

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o.requires:

.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o.requires

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o.provides: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/build.make src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o.provides.build
.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o.provides

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o.provides.build: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o


src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/flags.make
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o: src/analyzer/protocol/socks/socks_pac.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks/socks_pac.cc

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks/socks_pac.cc > CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.i

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks/socks_pac.cc -o CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.s

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o.requires:

.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o.requires

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o.provides: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/build.make src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o.provides.build
.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o.provides

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o.provides.build: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o


# Object files for target plugin-Bro-SOCKS
plugin__Bro__SOCKS_OBJECTS = \
"CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o" \
"CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o" \
"CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o" \
"CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o" \
"CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o"

# External object files for target plugin-Bro-SOCKS
plugin__Bro__SOCKS_EXTERNAL_OBJECTS =

src/analyzer/protocol/socks/libplugin-Bro-SOCKS.a: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o
src/analyzer/protocol/socks/libplugin-Bro-SOCKS.a: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o
src/analyzer/protocol/socks/libplugin-Bro-SOCKS.a: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o
src/analyzer/protocol/socks/libplugin-Bro-SOCKS.a: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o
src/analyzer/protocol/socks/libplugin-Bro-SOCKS.a: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o
src/analyzer/protocol/socks/libplugin-Bro-SOCKS.a: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/build.make
src/analyzer/protocol/socks/libplugin-Bro-SOCKS.a: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libplugin-Bro-SOCKS.a"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-SOCKS.dir/cmake_clean_target.cmake
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plugin-Bro-SOCKS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/build: src/analyzer/protocol/socks/libplugin-Bro-SOCKS.a

.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/build

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/requires: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/SOCKS.cc.o.requires
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/requires: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/Plugin.cc.o.requires
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/requires: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.cc.o.requires
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/requires: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/events.bif.init.cc.o.requires
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/requires: src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/socks_pac.cc.o.requires

.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/requires

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-SOCKS.dir/cmake_clean.cmake
.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/clean

src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/depend: src/analyzer/protocol/socks/events.bif.h
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/depend: src/analyzer/protocol/socks/events.bif.cc
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/depend: src/analyzer/protocol/socks/events.bif.init.cc
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/depend: src/analyzer/protocol/socks/events.bif.register.cc
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/depend: scripts/base/bif/plugins/Bro_SOCKS.events.bif.bro
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/depend: src/analyzer/protocol/socks/socks_pac.h
src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/depend: src/analyzer/protocol/socks/socks_pac.cc
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/analyzer/protocol/socks /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/protocol/socks/CMakeFiles/plugin-Bro-SOCKS.dir/depend

