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
include src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/depend.make

# Include the progress variables for this target.
include src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/progress.make

# Include the compile flags for this target's objects.
include src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/flags.make

src/analyzer/protocol/netbios/events.bif.h: ../src/analyzer/protocol/netbios/events.bif
src/analyzer/protocol/netbios/events.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing events.bif"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && ../../../bifcl -p Bro::NetBIOS /home/ubuntu/bro/src/analyzer/protocol/netbios/events.bif || ( rm -f events.bif.h events.bif.cc events.bif.init.cc events.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/cmake -E copy events.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_NetBIOS.events.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/cmake -E remove -f events.bif.bro

src/analyzer/protocol/netbios/events.bif.cc: src/analyzer/protocol/netbios/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/netbios/events.bif.cc

src/analyzer/protocol/netbios/events.bif.init.cc: src/analyzer/protocol/netbios/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/netbios/events.bif.init.cc

src/analyzer/protocol/netbios/events.bif.register.cc: src/analyzer/protocol/netbios/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/netbios/events.bif.register.cc

scripts/base/bif/plugins/Bro_NetBIOS.events.bif.bro: src/analyzer/protocol/netbios/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_NetBIOS.events.bif.bro

src/analyzer/protocol/netbios/functions.bif.h: ../src/analyzer/protocol/netbios/functions.bif
src/analyzer/protocol/netbios/functions.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[BIFCL] Processing functions.bif"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && ../../../bifcl -p Bro::NetBIOS /home/ubuntu/bro/src/analyzer/protocol/netbios/functions.bif || ( rm -f functions.bif.h functions.bif.cc functions.bif.init.cc functions.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/cmake -E copy functions.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_NetBIOS.functions.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/cmake -E remove -f functions.bif.bro

src/analyzer/protocol/netbios/functions.bif.cc: src/analyzer/protocol/netbios/functions.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/netbios/functions.bif.cc

src/analyzer/protocol/netbios/functions.bif.init.cc: src/analyzer/protocol/netbios/functions.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/netbios/functions.bif.init.cc

src/analyzer/protocol/netbios/functions.bif.register.cc: src/analyzer/protocol/netbios/functions.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/netbios/functions.bif.register.cc

scripts/base/bif/plugins/Bro_NetBIOS.functions.bif.bro: src/analyzer/protocol/netbios/functions.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_NetBIOS.functions.bif.bro

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/flags.make
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o: ../src/analyzer/protocol/netbios/NetbiosSSN.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/netbios/NetbiosSSN.cc

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/netbios/NetbiosSSN.cc > CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.i

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/netbios/NetbiosSSN.cc -o CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.s

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o.requires:

.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o.requires

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o.provides: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/build.make src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o.provides.build
.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o.provides

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o.provides.build: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o


src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/flags.make
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o: ../src/analyzer/protocol/netbios/Plugin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/netbios/Plugin.cc

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/netbios/Plugin.cc > CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.i

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/netbios/Plugin.cc -o CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.s

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o.requires:

.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o.requires

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o.provides: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/build.make src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o.provides.build
.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o.provides

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o.provides.build: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o


src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/flags.make
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o: src/analyzer/protocol/netbios/events.bif.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/events.bif.cc

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/events.bif.cc > CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.i

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/events.bif.cc -o CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.s

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o.requires:

.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o.requires

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o.provides: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/build.make src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o.provides.build
.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o.provides

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o.provides.build: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o


src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/flags.make
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o: src/analyzer/protocol/netbios/events.bif.init.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/events.bif.init.cc

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/events.bif.init.cc > CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.i

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/events.bif.init.cc -o CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.s

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o.requires:

.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o.requires

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o.provides: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/build.make src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o.provides.build
.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o.provides

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o.provides.build: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o


src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/flags.make
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o: src/analyzer/protocol/netbios/functions.bif.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/functions.bif.cc

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/functions.bif.cc > CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.i

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/functions.bif.cc -o CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.s

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o.requires:

.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o.requires

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o.provides: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/build.make src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o.provides.build
.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o.provides

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o.provides.build: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o


src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/flags.make
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o: src/analyzer/protocol/netbios/functions.bif.init.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/functions.bif.init.cc

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/functions.bif.init.cc > CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.i

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/functions.bif.init.cc -o CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.s

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o.requires:

.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o.requires

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o.provides: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/build.make src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o.provides.build
.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o.provides

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o.provides.build: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o


# Object files for target plugin-Bro-NetBIOS
plugin__Bro__NetBIOS_OBJECTS = \
"CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o" \
"CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o" \
"CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o" \
"CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o" \
"CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o" \
"CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o"

# External object files for target plugin-Bro-NetBIOS
plugin__Bro__NetBIOS_EXTERNAL_OBJECTS =

src/analyzer/protocol/netbios/libplugin-Bro-NetBIOS.a: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o
src/analyzer/protocol/netbios/libplugin-Bro-NetBIOS.a: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o
src/analyzer/protocol/netbios/libplugin-Bro-NetBIOS.a: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o
src/analyzer/protocol/netbios/libplugin-Bro-NetBIOS.a: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o
src/analyzer/protocol/netbios/libplugin-Bro-NetBIOS.a: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o
src/analyzer/protocol/netbios/libplugin-Bro-NetBIOS.a: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o
src/analyzer/protocol/netbios/libplugin-Bro-NetBIOS.a: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/build.make
src/analyzer/protocol/netbios/libplugin-Bro-NetBIOS.a: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library libplugin-Bro-NetBIOS.a"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-NetBIOS.dir/cmake_clean_target.cmake
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plugin-Bro-NetBIOS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/build: src/analyzer/protocol/netbios/libplugin-Bro-NetBIOS.a

.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/build

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/requires: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/NetbiosSSN.cc.o.requires
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/requires: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/Plugin.cc.o.requires
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/requires: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.cc.o.requires
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/requires: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/events.bif.init.cc.o.requires
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/requires: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.cc.o.requires
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/requires: src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/functions.bif.init.cc.o.requires

.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/requires

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-NetBIOS.dir/cmake_clean.cmake
.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/clean

src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/depend: src/analyzer/protocol/netbios/events.bif.h
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/depend: src/analyzer/protocol/netbios/events.bif.cc
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/depend: src/analyzer/protocol/netbios/events.bif.init.cc
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/depend: src/analyzer/protocol/netbios/events.bif.register.cc
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/depend: scripts/base/bif/plugins/Bro_NetBIOS.events.bif.bro
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/depend: src/analyzer/protocol/netbios/functions.bif.h
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/depend: src/analyzer/protocol/netbios/functions.bif.cc
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/depend: src/analyzer/protocol/netbios/functions.bif.init.cc
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/depend: src/analyzer/protocol/netbios/functions.bif.register.cc
src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/depend: scripts/base/bif/plugins/Bro_NetBIOS.functions.bif.bro
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/analyzer/protocol/netbios /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/protocol/netbios/CMakeFiles/plugin-Bro-NetBIOS.dir/depend
