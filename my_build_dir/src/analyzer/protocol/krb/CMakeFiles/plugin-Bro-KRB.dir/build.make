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
include src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend.make

# Include the progress variables for this target.
include src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/progress.make

# Include the compile flags for this target's objects.
include src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/flags.make

src/analyzer/protocol/krb/types.bif.h: ../src/analyzer/protocol/krb/types.bif
src/analyzer/protocol/krb/types.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing types.bif"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && ../../../bifcl -p Bro::KRB /home/ubuntu/bro/src/analyzer/protocol/krb/types.bif || ( rm -f types.bif.h types.bif.cc types.bif.init.cc types.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/cmake -E copy types.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_KRB.types.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/cmake -E remove -f types.bif.bro

src/analyzer/protocol/krb/types.bif.cc: src/analyzer/protocol/krb/types.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/krb/types.bif.cc

src/analyzer/protocol/krb/types.bif.init.cc: src/analyzer/protocol/krb/types.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/krb/types.bif.init.cc

src/analyzer/protocol/krb/types.bif.register.cc: src/analyzer/protocol/krb/types.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/krb/types.bif.register.cc

scripts/base/bif/plugins/Bro_KRB.types.bif.bro: src/analyzer/protocol/krb/types.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_KRB.types.bif.bro

src/analyzer/protocol/krb/events.bif.h: ../src/analyzer/protocol/krb/events.bif
src/analyzer/protocol/krb/events.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[BIFCL] Processing events.bif"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && ../../../bifcl -p Bro::KRB /home/ubuntu/bro/src/analyzer/protocol/krb/events.bif || ( rm -f events.bif.h events.bif.cc events.bif.init.cc events.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/cmake -E copy events.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_KRB.events.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/cmake -E remove -f events.bif.bro

src/analyzer/protocol/krb/events.bif.cc: src/analyzer/protocol/krb/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/krb/events.bif.cc

src/analyzer/protocol/krb/events.bif.init.cc: src/analyzer/protocol/krb/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/krb/events.bif.init.cc

src/analyzer/protocol/krb/events.bif.register.cc: src/analyzer/protocol/krb/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/krb/events.bif.register.cc

scripts/base/bif/plugins/Bro_KRB.events.bif.bro: src/analyzer/protocol/krb/events.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_KRB.events.bif.bro

src/analyzer/protocol/krb/krb_pac.h: ../src/analyzer/protocol/krb/binpac
src/analyzer/protocol/krb/krb_pac.h: ../src/analyzer/protocol/krb/krb.pac
src/analyzer/protocol/krb/krb_pac.h: ../src/binpac.pac
src/analyzer/protocol/krb/krb_pac.h: ../src/bro.pac
src/analyzer/protocol/krb/krb_pac.h: ../src/binpac_bro.h
src/analyzer/protocol/krb/krb_pac.h: ../src/analyzer/protocol/krb/krb-protocol.pac
src/analyzer/protocol/krb/krb_pac.h: ../src/analyzer/protocol/krb/krb-analyzer.pac
src/analyzer/protocol/krb/krb_pac.h: ../src/analyzer/protocol/krb/krb-asn1.pac
src/analyzer/protocol/krb/krb_pac.h: ../src/analyzer/protocol/krb/krb-defs.pac
src/analyzer/protocol/krb/krb_pac.h: ../src/analyzer/protocol/krb/krb-types.pac
src/analyzer/protocol/krb/krb_pac.h: ../src/analyzer/protocol/krb/krb-padata.pac
src/analyzer/protocol/krb/krb_pac.h: ../src/analyzer/protocol/krb/../asn1/asn1.pac
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "[BINPAC] Processing krb.pac"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && binpac -q -d /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb -I /home/ubuntu/bro/src/analyzer/protocol/krb -I /home/ubuntu/bro/src /home/ubuntu/bro/src/analyzer/protocol/krb/krb.pac

src/analyzer/protocol/krb/krb_pac.cc: src/analyzer/protocol/krb/krb_pac.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/krb/krb_pac.cc

src/analyzer/protocol/krb/krb_TCP_pac.h: ../src/analyzer/protocol/krb/binpac
src/analyzer/protocol/krb/krb_TCP_pac.h: ../src/analyzer/protocol/krb/krb_TCP.pac
src/analyzer/protocol/krb/krb_TCP_pac.h: ../src/binpac.pac
src/analyzer/protocol/krb/krb_TCP_pac.h: ../src/bro.pac
src/analyzer/protocol/krb/krb_TCP_pac.h: ../src/binpac_bro.h
src/analyzer/protocol/krb/krb_TCP_pac.h: ../src/analyzer/protocol/krb/krb-protocol.pac
src/analyzer/protocol/krb/krb_TCP_pac.h: ../src/analyzer/protocol/krb/krb-analyzer.pac
src/analyzer/protocol/krb/krb_TCP_pac.h: ../src/analyzer/protocol/krb/krb-asn1.pac
src/analyzer/protocol/krb/krb_TCP_pac.h: ../src/analyzer/protocol/krb/krb-defs.pac
src/analyzer/protocol/krb/krb_TCP_pac.h: ../src/analyzer/protocol/krb/krb-types.pac
src/analyzer/protocol/krb/krb_TCP_pac.h: ../src/analyzer/protocol/krb/krb-padata.pac
src/analyzer/protocol/krb/krb_TCP_pac.h: ../src/analyzer/protocol/krb/../asn1/asn1.pac
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "[BINPAC] Processing krb_TCP.pac"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && binpac -q -d /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb -I /home/ubuntu/bro/src/analyzer/protocol/krb -I /home/ubuntu/bro/src /home/ubuntu/bro/src/analyzer/protocol/krb/krb_TCP.pac

src/analyzer/protocol/krb/krb_TCP_pac.cc: src/analyzer/protocol/krb/krb_TCP_pac.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/krb/krb_TCP_pac.cc

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/flags.make
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o: ../src/analyzer/protocol/krb/Plugin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/krb/Plugin.cc

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/krb/Plugin.cc > CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.i

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/krb/Plugin.cc -o CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.s

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o.requires:

.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o.requires

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o.provides: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/build.make src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o.provides.build
.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o.provides

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o.provides.build: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o


src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/flags.make
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o: ../src/analyzer/protocol/krb/KRB.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/krb/KRB.cc

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/krb/KRB.cc > CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.i

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/krb/KRB.cc -o CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.s

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o.requires:

.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o.requires

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o.provides: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/build.make src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o.provides.build
.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o.provides

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o.provides.build: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o


src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/flags.make
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o: ../src/analyzer/protocol/krb/KRB_TCP.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o -c /home/ubuntu/bro/src/analyzer/protocol/krb/KRB_TCP.cc

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/analyzer/protocol/krb/KRB_TCP.cc > CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.i

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/analyzer/protocol/krb/KRB_TCP.cc -o CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.s

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o.requires:

.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o.requires

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o.provides: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/build.make src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o.provides.build
.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o.provides

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o.provides.build: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o


src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/flags.make
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o: src/analyzer/protocol/krb/types.bif.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/types.bif.cc

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/types.bif.cc > CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.i

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/types.bif.cc -o CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.s

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o.requires:

.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o.requires

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o.provides: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/build.make src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o.provides.build
.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o.provides

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o.provides.build: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o


src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/flags.make
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o: src/analyzer/protocol/krb/types.bif.init.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/types.bif.init.cc

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/types.bif.init.cc > CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.i

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/types.bif.init.cc -o CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.s

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o.requires:

.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o.requires

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o.provides: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/build.make src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o.provides.build
.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o.provides

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o.provides.build: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o


src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/flags.make
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o: src/analyzer/protocol/krb/events.bif.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/events.bif.cc

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/events.bif.cc > CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.i

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/events.bif.cc -o CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.s

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o.requires:

.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o.requires

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o.provides: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/build.make src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o.provides.build
.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o.provides

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o.provides.build: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o


src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/flags.make
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o: src/analyzer/protocol/krb/events.bif.init.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/events.bif.init.cc

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/events.bif.init.cc > CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.i

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/events.bif.init.cc -o CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.s

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o.requires:

.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o.requires

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o.provides: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/build.make src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o.provides.build
.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o.provides

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o.provides.build: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o


src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/flags.make
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o: src/analyzer/protocol/krb/krb_pac.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/krb_pac.cc

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/krb_pac.cc > CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.i

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/krb_pac.cc -o CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.s

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o.requires:

.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o.requires

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o.provides: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/build.make src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o.provides.build
.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o.provides

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o.provides.build: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o


src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/flags.make
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o: src/analyzer/protocol/krb/krb_TCP_pac.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o -c /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/krb_TCP_pac.cc

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/krb_TCP_pac.cc > CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.i

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/krb_TCP_pac.cc -o CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.s

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o.requires:

.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o.requires

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o.provides: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o.requires
	$(MAKE) -f src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/build.make src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o.provides.build
.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o.provides

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o.provides.build: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o


# Object files for target plugin-Bro-KRB
plugin__Bro__KRB_OBJECTS = \
"CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o" \
"CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o" \
"CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o" \
"CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o" \
"CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o" \
"CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o" \
"CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o" \
"CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o" \
"CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o"

# External object files for target plugin-Bro-KRB
plugin__Bro__KRB_EXTERNAL_OBJECTS =

src/analyzer/protocol/krb/libplugin-Bro-KRB.a: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o
src/analyzer/protocol/krb/libplugin-Bro-KRB.a: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o
src/analyzer/protocol/krb/libplugin-Bro-KRB.a: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o
src/analyzer/protocol/krb/libplugin-Bro-KRB.a: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o
src/analyzer/protocol/krb/libplugin-Bro-KRB.a: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o
src/analyzer/protocol/krb/libplugin-Bro-KRB.a: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o
src/analyzer/protocol/krb/libplugin-Bro-KRB.a: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o
src/analyzer/protocol/krb/libplugin-Bro-KRB.a: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o
src/analyzer/protocol/krb/libplugin-Bro-KRB.a: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o
src/analyzer/protocol/krb/libplugin-Bro-KRB.a: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/build.make
src/analyzer/protocol/krb/libplugin-Bro-KRB.a: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX static library libplugin-Bro-KRB.a"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-KRB.dir/cmake_clean_target.cmake
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plugin-Bro-KRB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/build: src/analyzer/protocol/krb/libplugin-Bro-KRB.a

.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/build

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/requires: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/Plugin.cc.o.requires
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/requires: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB.cc.o.requires
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/requires: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/KRB_TCP.cc.o.requires
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/requires: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.cc.o.requires
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/requires: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/types.bif.init.cc.o.requires
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/requires: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.cc.o.requires
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/requires: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/events.bif.init.cc.o.requires
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/requires: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_pac.cc.o.requires
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/requires: src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/krb_TCP_pac.cc.o.requires

.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/requires

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-KRB.dir/cmake_clean.cmake
.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/clean

src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: src/analyzer/protocol/krb/types.bif.h
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: src/analyzer/protocol/krb/types.bif.cc
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: src/analyzer/protocol/krb/types.bif.init.cc
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: src/analyzer/protocol/krb/types.bif.register.cc
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: scripts/base/bif/plugins/Bro_KRB.types.bif.bro
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: src/analyzer/protocol/krb/events.bif.h
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: src/analyzer/protocol/krb/events.bif.cc
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: src/analyzer/protocol/krb/events.bif.init.cc
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: src/analyzer/protocol/krb/events.bif.register.cc
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: scripts/base/bif/plugins/Bro_KRB.events.bif.bro
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: src/analyzer/protocol/krb/krb_pac.h
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: src/analyzer/protocol/krb/krb_pac.cc
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: src/analyzer/protocol/krb/krb_TCP_pac.h
src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend: src/analyzer/protocol/krb/krb_TCP_pac.cc
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/analyzer/protocol/krb /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/protocol/krb/CMakeFiles/plugin-Bro-KRB.dir/depend

