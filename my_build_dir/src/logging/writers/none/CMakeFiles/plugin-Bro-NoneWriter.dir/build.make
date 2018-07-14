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
include src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/depend.make

# Include the progress variables for this target.
include src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/progress.make

# Include the compile flags for this target's objects.
include src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/flags.make

src/logging/writers/none/none.bif.h: ../src/logging/writers/none/none.bif
src/logging/writers/none/none.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing none.bif"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && ../../../bifcl -p Bro::NoneWriter /home/ubuntu/bro/src/logging/writers/none/none.bif || ( rm -f none.bif.h none.bif.cc none.bif.init.cc none.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/cmake -E copy none.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_NoneWriter.none.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/cmake -E remove -f none.bif.bro

src/logging/writers/none/none.bif.cc: src/logging/writers/none/none.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/logging/writers/none/none.bif.cc

src/logging/writers/none/none.bif.init.cc: src/logging/writers/none/none.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/logging/writers/none/none.bif.init.cc

src/logging/writers/none/none.bif.register.cc: src/logging/writers/none/none.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/logging/writers/none/none.bif.register.cc

scripts/base/bif/plugins/Bro_NoneWriter.none.bif.bro: src/logging/writers/none/none.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_NoneWriter.none.bif.bro

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/flags.make
src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o: ../src/logging/writers/none/None.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o -c /home/ubuntu/bro/src/logging/writers/none/None.cc

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/logging/writers/none/None.cc > CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.i

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/logging/writers/none/None.cc -o CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.s

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o.requires:

.PHONY : src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o.requires

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o.provides: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o.requires
	$(MAKE) -f src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/build.make src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o.provides.build
.PHONY : src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o.provides

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o.provides.build: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o


src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/flags.make
src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o: ../src/logging/writers/none/Plugin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o -c /home/ubuntu/bro/src/logging/writers/none/Plugin.cc

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/logging/writers/none/Plugin.cc > CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.i

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/logging/writers/none/Plugin.cc -o CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.s

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o.requires:

.PHONY : src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o.requires

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o.provides: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o.requires
	$(MAKE) -f src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/build.make src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o.provides.build
.PHONY : src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o.provides

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o.provides.build: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o


src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/flags.make
src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o: src/logging/writers/none/none.bif.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o -c /home/ubuntu/bro/my_build_dir/src/logging/writers/none/none.bif.cc

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/logging/writers/none/none.bif.cc > CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.i

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/logging/writers/none/none.bif.cc -o CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.s

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o.requires:

.PHONY : src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o.requires

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o.provides: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o.requires
	$(MAKE) -f src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/build.make src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o.provides.build
.PHONY : src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o.provides

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o.provides.build: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o


src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/flags.make
src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o: src/logging/writers/none/none.bif.init.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o -c /home/ubuntu/bro/my_build_dir/src/logging/writers/none/none.bif.init.cc

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/logging/writers/none/none.bif.init.cc > CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.i

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/logging/writers/none/none.bif.init.cc -o CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.s

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o.requires:

.PHONY : src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o.requires

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o.provides: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o.requires
	$(MAKE) -f src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/build.make src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o.provides.build
.PHONY : src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o.provides

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o.provides.build: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o


# Object files for target plugin-Bro-NoneWriter
plugin__Bro__NoneWriter_OBJECTS = \
"CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o" \
"CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o" \
"CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o" \
"CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o"

# External object files for target plugin-Bro-NoneWriter
plugin__Bro__NoneWriter_EXTERNAL_OBJECTS =

src/logging/writers/none/libplugin-Bro-NoneWriter.a: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o
src/logging/writers/none/libplugin-Bro-NoneWriter.a: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o
src/logging/writers/none/libplugin-Bro-NoneWriter.a: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o
src/logging/writers/none/libplugin-Bro-NoneWriter.a: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o
src/logging/writers/none/libplugin-Bro-NoneWriter.a: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/build.make
src/logging/writers/none/libplugin-Bro-NoneWriter.a: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libplugin-Bro-NoneWriter.a"
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-NoneWriter.dir/cmake_clean_target.cmake
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plugin-Bro-NoneWriter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/build: src/logging/writers/none/libplugin-Bro-NoneWriter.a

.PHONY : src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/build

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/requires: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/None.cc.o.requires
src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/requires: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/Plugin.cc.o.requires
src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/requires: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.cc.o.requires
src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/requires: src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/none.bif.init.cc.o.requires

.PHONY : src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/requires

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/logging/writers/none && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-NoneWriter.dir/cmake_clean.cmake
.PHONY : src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/clean

src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/depend: src/logging/writers/none/none.bif.h
src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/depend: src/logging/writers/none/none.bif.cc
src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/depend: src/logging/writers/none/none.bif.init.cc
src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/depend: src/logging/writers/none/none.bif.register.cc
src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/depend: scripts/base/bif/plugins/Bro_NoneWriter.none.bif.bro
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/logging/writers/none /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/logging/writers/none /home/ubuntu/bro/my_build_dir/src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/logging/writers/none/CMakeFiles/plugin-Bro-NoneWriter.dir/depend
