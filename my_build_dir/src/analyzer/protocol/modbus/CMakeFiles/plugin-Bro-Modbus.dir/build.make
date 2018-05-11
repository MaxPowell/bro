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
include src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/depend.make

# Include the progress variables for this target.
include src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/progress.make

# Include the compile flags for this target's objects.
include src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/flags.make

src/analyzer/protocol/modbus/events.bif.h: ../src/analyzer/protocol/modbus/events.bif
src/analyzer/protocol/modbus/events.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing events.bif"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && ../../../bifcl -p Bro::Modbus /home/ubuntu/bro/src/analyzer/protocol/modbus/events.bif || ( rm -f events.bif.h events.bif.cc events.bif.init.cc events.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/cmake -E copy events.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_Modbus.events.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/cmake -E remove -f events.bif.bro

src/analyzer/protocol/modbus/events.bif.cc: src/analyzer/protocol/modbus/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/modbus/events.bif.cc

src/analyzer/protocol/modbus/events.bif.init.cc: src/analyzer/protocol/modbus/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/modbus/events.bif.init.cc

src/analyzer/protocol/modbus/events.bif.register.cc: src/analyzer/protocol/modbus/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/modbus/events.bif.register.cc

scripts/base/bif/plugins/Bro_Modbus.events.bif.bro: src/analyzer/protocol/modbus/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_Modbus.events.bif.bro

src/analyzer/protocol/modbus/modbus_pac.h: ../src/analyzer/protocol/modbus/binpac
src/analyzer/protocol/modbus/modbus_pac.h: ../src/analyzer/protocol/modbus/modbus.pac
src/analyzer/protocol/modbus/modbus_pac.h: ../src/binpac.pac
src/analyzer/protocol/modbus/modbus_pac.h: ../src/bro.pac
src/analyzer/protocol/modbus/modbus_pac.h: ../src/binpac_bro.h
src/analyzer/protocol/modbus/modbus_pac.h: ../src/analyzer/protocol/modbus/modbus-analyzer.pac
src/analyzer/protocol/modbus/modbus_pac.h: ../src/analyzer/protocol/modbus/modbus-protocol.pac
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[BINPAC] Processing modbus.pac"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && binpac -q -d /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus -I /home/ubuntu/bro/src/analyzer/protocol/modbus -I /home/ubuntu/bro/src /home/ubuntu/bro/src/analyzer/protocol/modbus/modbus.pac

src/analyzer/protocol/modbus/modbus_pac.cc: src/analyzer/protocol/modbus/modbus_pac.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/modbus/modbus_pac.cc

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/flags.make
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o: ../src/analyzer/protocol/modbus/Modbus.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/modbus/Modbus.cc

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/modbus/Modbus.cc > CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.i

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/modbus/Modbus.cc -o CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.s

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o.requires:

.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o.requires

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o.provides: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/build.make src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o.provides.build
.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o.provides

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o.provides.build: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o


src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/flags.make
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o: ../src/analyzer/protocol/modbus/Plugin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/modbus/Plugin.cc

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/modbus/Plugin.cc > CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.i

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/modbus/Plugin.cc -o CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.s

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o.requires:

.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o.requires

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o.provides: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/build.make src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o.provides.build
.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o.provides

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o.provides.build: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o


src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/flags.make
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o: src/analyzer/protocol/modbus/events.bif.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus/events.bif.cc

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus/events.bif.cc > CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.i

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus/events.bif.cc -o CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.s

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o.requires:

.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o.requires

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o.provides: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/build.make src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o.provides.build
.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o.provides

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o.provides.build: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o


src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/flags.make
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o: src/analyzer/protocol/modbus/events.bif.init.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus/events.bif.init.cc

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus/events.bif.init.cc > CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.i

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus/events.bif.init.cc -o CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.s

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o.requires:

.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o.requires

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o.provides: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/build.make src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o.provides.build
.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o.provides

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o.provides.build: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o


src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/flags.make
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o: src/analyzer/protocol/modbus/modbus_pac.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus/modbus_pac.cc

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus/modbus_pac.cc > CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.i

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus/modbus_pac.cc -o CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.s

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o.requires:

.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o.requires

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o.provides: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/build.make src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o.provides.build
.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o.provides

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o.provides.build: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o


# Object files for target plugin-Bro-Modbus
plugin__Bro__Modbus_OBJECTS = \
"CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o" \
"CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o" \
"CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o" \
"CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o" \
"CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o"

# External object files for target plugin-Bro-Modbus
plugin__Bro__Modbus_EXTERNAL_OBJECTS =

src/analyzer/protocol/modbus/libplugin-Bro-Modbus.a: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o
src/analyzer/protocol/modbus/libplugin-Bro-Modbus.a: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o
src/analyzer/protocol/modbus/libplugin-Bro-Modbus.a: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o
src/analyzer/protocol/modbus/libplugin-Bro-Modbus.a: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o
src/analyzer/protocol/modbus/libplugin-Bro-Modbus.a: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o
src/analyzer/protocol/modbus/libplugin-Bro-Modbus.a: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/build.make
src/analyzer/protocol/modbus/libplugin-Bro-Modbus.a: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libplugin-Bro-Modbus.a"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-Modbus.dir/cmake_clean_target.cmake
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plugin-Bro-Modbus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/build: src/analyzer/protocol/modbus/libplugin-Bro-Modbus.a

.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/build

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/requires: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Modbus.cc.o.requires
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/requires: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/Plugin.cc.o.requires
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/requires: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.cc.o.requires
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/requires: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/events.bif.init.cc.o.requires
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/requires: src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/modbus_pac.cc.o.requires

.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/requires

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-Modbus.dir/cmake_clean.cmake
.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/clean

src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/depend: src/analyzer/protocol/modbus/events.bif.h
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/depend: src/analyzer/protocol/modbus/events.bif.cc
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/depend: src/analyzer/protocol/modbus/events.bif.init.cc
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/depend: src/analyzer/protocol/modbus/events.bif.register.cc
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/depend: scripts/base/bif/plugins/Bro_Modbus.events.bif.bro
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/depend: src/analyzer/protocol/modbus/modbus_pac.h
src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/depend: src/analyzer/protocol/modbus/modbus_pac.cc
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/analyzer/protocol/modbus /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/protocol/modbus/CMakeFiles/plugin-Bro-Modbus.dir/depend

