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
include src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/depend.make

# Include the progress variables for this target.
include src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/progress.make

# Include the compile flags for this target's objects.
include src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/flags.make

src/analyzer/protocol/rpc/events.bif.h: ../src/analyzer/protocol/rpc/events.bif
src/analyzer/protocol/rpc/events.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing events.bif"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && ../../../bifcl -p Bro::RPC /home/ubuntu/bro/src/analyzer/protocol/rpc/events.bif || ( rm -f events.bif.h events.bif.cc events.bif.init.cc events.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/cmake -E copy events.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_RPC.events.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/cmake -E remove -f events.bif.bro

src/analyzer/protocol/rpc/events.bif.cc: src/analyzer/protocol/rpc/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/rpc/events.bif.cc

src/analyzer/protocol/rpc/events.bif.init.cc: src/analyzer/protocol/rpc/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/rpc/events.bif.init.cc

src/analyzer/protocol/rpc/events.bif.register.cc: src/analyzer/protocol/rpc/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/rpc/events.bif.register.cc

scripts/base/bif/plugins/Bro_RPC.events.bif.bro: src/analyzer/protocol/rpc/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_RPC.events.bif.bro

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/flags.make
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o: ../src/analyzer/protocol/rpc/RPC.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/rpc/RPC.cc

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/rpc/RPC.cc > CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.i

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/rpc/RPC.cc -o CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.s

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o.requires:

.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o.requires

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o.provides: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/build.make src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o.provides.build
.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o.provides

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o.provides.build: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o


src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/flags.make
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o: ../src/analyzer/protocol/rpc/NFS.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/rpc/NFS.cc

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/rpc/NFS.cc > CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.i

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/rpc/NFS.cc -o CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.s

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o.requires:

.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o.requires

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o.provides: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/build.make src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o.provides.build
.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o.provides

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o.provides.build: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o


src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/flags.make
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o: ../src/analyzer/protocol/rpc/MOUNT.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/rpc/MOUNT.cc

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/rpc/MOUNT.cc > CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.i

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/rpc/MOUNT.cc -o CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.s

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o.requires:

.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o.requires

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o.provides: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/build.make src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o.provides.build
.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o.provides

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o.provides.build: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o


src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/flags.make
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o: ../src/analyzer/protocol/rpc/Portmap.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/rpc/Portmap.cc

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/rpc/Portmap.cc > CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.i

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/rpc/Portmap.cc -o CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.s

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o.requires:

.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o.requires

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o.provides: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/build.make src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o.provides.build
.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o.provides

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o.provides.build: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o


src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/flags.make
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o: ../src/analyzer/protocol/rpc/XDR.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/rpc/XDR.cc

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/rpc/XDR.cc > CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.i

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/rpc/XDR.cc -o CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.s

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o.requires:

.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o.requires

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o.provides: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/build.make src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o.provides.build
.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o.provides

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o.provides.build: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o


src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/flags.make
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o: ../src/analyzer/protocol/rpc/Plugin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/rpc/Plugin.cc

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/rpc/Plugin.cc > CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.i

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/rpc/Plugin.cc -o CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.s

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o.requires:

.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o.requires

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o.provides: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/build.make src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o.provides.build
.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o.provides

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o.provides.build: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o


src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/flags.make
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o: src/analyzer/protocol/rpc/events.bif.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc/events.bif.cc

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc/events.bif.cc > CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.i

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc/events.bif.cc -o CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.s

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o.requires:

.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o.requires

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o.provides: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/build.make src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o.provides.build
.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o.provides

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o.provides.build: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o


src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/flags.make
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o: src/analyzer/protocol/rpc/events.bif.init.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc/events.bif.init.cc

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc/events.bif.init.cc > CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.i

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc/events.bif.init.cc -o CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.s

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o.requires:

.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o.requires

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o.provides: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/build.make src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o.provides.build
.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o.provides

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o.provides.build: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o


# Object files for target plugin-Bro-RPC
plugin__Bro__RPC_OBJECTS = \
"CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o" \
"CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o" \
"CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o" \
"CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o" \
"CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o" \
"CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o" \
"CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o" \
"CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o"

# External object files for target plugin-Bro-RPC
plugin__Bro__RPC_EXTERNAL_OBJECTS =

src/analyzer/protocol/rpc/libplugin-Bro-RPC.a: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o
src/analyzer/protocol/rpc/libplugin-Bro-RPC.a: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o
src/analyzer/protocol/rpc/libplugin-Bro-RPC.a: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o
src/analyzer/protocol/rpc/libplugin-Bro-RPC.a: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o
src/analyzer/protocol/rpc/libplugin-Bro-RPC.a: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o
src/analyzer/protocol/rpc/libplugin-Bro-RPC.a: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o
src/analyzer/protocol/rpc/libplugin-Bro-RPC.a: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o
src/analyzer/protocol/rpc/libplugin-Bro-RPC.a: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o
src/analyzer/protocol/rpc/libplugin-Bro-RPC.a: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/build.make
src/analyzer/protocol/rpc/libplugin-Bro-RPC.a: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libplugin-Bro-RPC.a"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-RPC.dir/cmake_clean_target.cmake
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plugin-Bro-RPC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/build: src/analyzer/protocol/rpc/libplugin-Bro-RPC.a

.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/build

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/requires: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/RPC.cc.o.requires
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/requires: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/NFS.cc.o.requires
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/requires: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/MOUNT.cc.o.requires
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/requires: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Portmap.cc.o.requires
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/requires: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/XDR.cc.o.requires
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/requires: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/Plugin.cc.o.requires
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/requires: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.cc.o.requires
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/requires: src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/events.bif.init.cc.o.requires

.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/requires

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-RPC.dir/cmake_clean.cmake
.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/clean

src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/depend: src/analyzer/protocol/rpc/events.bif.h
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/depend: src/analyzer/protocol/rpc/events.bif.cc
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/depend: src/analyzer/protocol/rpc/events.bif.init.cc
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/depend: src/analyzer/protocol/rpc/events.bif.register.cc
src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/depend: scripts/base/bif/plugins/Bro_RPC.events.bif.bro
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/analyzer/protocol/rpc /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/protocol/rpc/CMakeFiles/plugin-Bro-RPC.dir/depend

