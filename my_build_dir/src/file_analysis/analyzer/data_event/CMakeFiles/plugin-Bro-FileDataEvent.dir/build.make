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
include src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/depend.make

# Include the progress variables for this target.
include src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/progress.make

# Include the compile flags for this target's objects.
include src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/flags.make

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/flags.make
src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o: ../src/file_analysis/analyzer/data_event/DataEvent.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o -c /home/ubuntu/bro/src/file_analysis/analyzer/data_event/DataEvent.cc

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/file_analysis/analyzer/data_event/DataEvent.cc > CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.i

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/file_analysis/analyzer/data_event/DataEvent.cc -o CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.s

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o.requires:

.PHONY : src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o.requires

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o.provides: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o.requires
	$(MAKE) -f src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/build.make src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o.provides.build
.PHONY : src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o.provides

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o.provides.build: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o


src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/flags.make
src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o: ../src/file_analysis/analyzer/data_event/Plugin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o -c /home/ubuntu/bro/src/file_analysis/analyzer/data_event/Plugin.cc

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/file_analysis/analyzer/data_event/Plugin.cc > CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.i

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/file_analysis/analyzer/data_event/Plugin.cc -o CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.s

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o.requires:

.PHONY : src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o.requires

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o.provides: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o.requires
	$(MAKE) -f src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/build.make src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o.provides.build
.PHONY : src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o.provides

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o.provides.build: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o


src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/flags.make
src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o: ../src/file_analysis/Analyzer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o -c /home/ubuntu/bro/src/file_analysis/Analyzer.cc

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/file_analysis/Analyzer.cc > CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.i

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/file_analysis/Analyzer.cc -o CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.s

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o.requires:

.PHONY : src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o.requires

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o.provides: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o.requires
	$(MAKE) -f src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/build.make src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o.provides.build
.PHONY : src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o.provides

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o.provides.build: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o


# Object files for target plugin-Bro-FileDataEvent
plugin__Bro__FileDataEvent_OBJECTS = \
"CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o" \
"CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o" \
"CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o"

# External object files for target plugin-Bro-FileDataEvent
plugin__Bro__FileDataEvent_EXTERNAL_OBJECTS =

src/file_analysis/analyzer/data_event/libplugin-Bro-FileDataEvent.a: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o
src/file_analysis/analyzer/data_event/libplugin-Bro-FileDataEvent.a: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o
src/file_analysis/analyzer/data_event/libplugin-Bro-FileDataEvent.a: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o
src/file_analysis/analyzer/data_event/libplugin-Bro-FileDataEvent.a: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/build.make
src/file_analysis/analyzer/data_event/libplugin-Bro-FileDataEvent.a: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libplugin-Bro-FileDataEvent.a"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-FileDataEvent.dir/cmake_clean_target.cmake
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plugin-Bro-FileDataEvent.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/build: src/file_analysis/analyzer/data_event/libplugin-Bro-FileDataEvent.a

.PHONY : src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/build

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/requires: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DataEvent.cc.o.requires
src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/requires: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/Plugin.cc.o.requires
src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/requires: src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/__/__/Analyzer.cc.o.requires

.PHONY : src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/requires

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event && $(CMAKE_COMMAND) -P CMakeFiles/plugin-Bro-FileDataEvent.dir/cmake_clean.cmake
.PHONY : src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/clean

src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/file_analysis/analyzer/data_event /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event /home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/file_analysis/analyzer/data_event/CMakeFiles/plugin-Bro-FileDataEvent.dir/depend

