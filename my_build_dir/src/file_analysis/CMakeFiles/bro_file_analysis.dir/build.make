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
include src/file_analysis/CMakeFiles/bro_file_analysis.dir/depend.make

# Include the progress variables for this target.
include src/file_analysis/CMakeFiles/bro_file_analysis.dir/progress.make

# Include the compile flags for this target's objects.
include src/file_analysis/CMakeFiles/bro_file_analysis.dir/flags.make

src/file_analysis/file_analysis.bif.h: ../src/file_analysis/file_analysis.bif
src/file_analysis/file_analysis.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing file_analysis.bif"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && ../bifcl -s /home/ubuntu/bro/src/file_analysis/file_analysis.bif || ( rm -f file_analysis.bif.h file_analysis.bif.cc file_analysis.bif.init.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/cmake -E copy file_analysis.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/file_analysis.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/cmake -E remove -f file_analysis.bif.bro

src/file_analysis/file_analysis.bif.cc: src/file_analysis/file_analysis.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/file_analysis/file_analysis.bif.cc

src/file_analysis/file_analysis.bif.init.cc: src/file_analysis/file_analysis.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/file_analysis/file_analysis.bif.init.cc

scripts/base/bif/file_analysis.bif.bro: src/file_analysis/file_analysis.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/file_analysis.bif.bro

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o: src/file_analysis/CMakeFiles/bro_file_analysis.dir/flags.make
src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o: ../src/file_analysis/Manager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bro_file_analysis.dir/Manager.cc.o -c /home/ubuntu/bro/src/file_analysis/Manager.cc

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bro_file_analysis.dir/Manager.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/file_analysis/Manager.cc > CMakeFiles/bro_file_analysis.dir/Manager.cc.i

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bro_file_analysis.dir/Manager.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/file_analysis/Manager.cc -o CMakeFiles/bro_file_analysis.dir/Manager.cc.s

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o.requires:

.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o.requires

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o.provides: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o.requires
	$(MAKE) -f src/file_analysis/CMakeFiles/bro_file_analysis.dir/build.make src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o.provides.build
.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o.provides

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o.provides.build: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o


src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o: src/file_analysis/CMakeFiles/bro_file_analysis.dir/flags.make
src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o: ../src/file_analysis/File.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bro_file_analysis.dir/File.cc.o -c /home/ubuntu/bro/src/file_analysis/File.cc

src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bro_file_analysis.dir/File.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/file_analysis/File.cc > CMakeFiles/bro_file_analysis.dir/File.cc.i

src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bro_file_analysis.dir/File.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/file_analysis/File.cc -o CMakeFiles/bro_file_analysis.dir/File.cc.s

src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o.requires:

.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o.requires

src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o.provides: src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o.requires
	$(MAKE) -f src/file_analysis/CMakeFiles/bro_file_analysis.dir/build.make src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o.provides.build
.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o.provides

src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o.provides.build: src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o


src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o: src/file_analysis/CMakeFiles/bro_file_analysis.dir/flags.make
src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o: ../src/file_analysis/FileTimer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o -c /home/ubuntu/bro/src/file_analysis/FileTimer.cc

src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bro_file_analysis.dir/FileTimer.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/file_analysis/FileTimer.cc > CMakeFiles/bro_file_analysis.dir/FileTimer.cc.i

src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bro_file_analysis.dir/FileTimer.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/file_analysis/FileTimer.cc -o CMakeFiles/bro_file_analysis.dir/FileTimer.cc.s

src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o.requires:

.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o.requires

src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o.provides: src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o.requires
	$(MAKE) -f src/file_analysis/CMakeFiles/bro_file_analysis.dir/build.make src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o.provides.build
.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o.provides

src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o.provides.build: src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o


src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o: src/file_analysis/CMakeFiles/bro_file_analysis.dir/flags.make
src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o: ../src/file_analysis/FileReassembler.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o -c /home/ubuntu/bro/src/file_analysis/FileReassembler.cc

src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/file_analysis/FileReassembler.cc > CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.i

src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/file_analysis/FileReassembler.cc -o CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.s

src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o.requires:

.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o.requires

src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o.provides: src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o.requires
	$(MAKE) -f src/file_analysis/CMakeFiles/bro_file_analysis.dir/build.make src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o.provides.build
.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o.provides

src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o.provides.build: src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o


src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o: src/file_analysis/CMakeFiles/bro_file_analysis.dir/flags.make
src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o: ../src/file_analysis/Analyzer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o -c /home/ubuntu/bro/src/file_analysis/Analyzer.cc

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bro_file_analysis.dir/Analyzer.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/file_analysis/Analyzer.cc > CMakeFiles/bro_file_analysis.dir/Analyzer.cc.i

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bro_file_analysis.dir/Analyzer.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/file_analysis/Analyzer.cc -o CMakeFiles/bro_file_analysis.dir/Analyzer.cc.s

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o.requires:

.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o.requires

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o.provides: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o.requires
	$(MAKE) -f src/file_analysis/CMakeFiles/bro_file_analysis.dir/build.make src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o.provides.build
.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o.provides

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o.provides.build: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o


src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o: src/file_analysis/CMakeFiles/bro_file_analysis.dir/flags.make
src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o: ../src/file_analysis/AnalyzerSet.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o -c /home/ubuntu/bro/src/file_analysis/AnalyzerSet.cc

src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/file_analysis/AnalyzerSet.cc > CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.i

src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/file_analysis/AnalyzerSet.cc -o CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.s

src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o.requires:

.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o.requires

src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o.provides: src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o.requires
	$(MAKE) -f src/file_analysis/CMakeFiles/bro_file_analysis.dir/build.make src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o.provides.build
.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o.provides

src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o.provides.build: src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o


src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o: src/file_analysis/CMakeFiles/bro_file_analysis.dir/flags.make
src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o: ../src/file_analysis/Component.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bro_file_analysis.dir/Component.cc.o -c /home/ubuntu/bro/src/file_analysis/Component.cc

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bro_file_analysis.dir/Component.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/file_analysis/Component.cc > CMakeFiles/bro_file_analysis.dir/Component.cc.i

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bro_file_analysis.dir/Component.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/file_analysis/Component.cc -o CMakeFiles/bro_file_analysis.dir/Component.cc.s

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o.requires:

.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o.requires

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o.provides: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o.requires
	$(MAKE) -f src/file_analysis/CMakeFiles/bro_file_analysis.dir/build.make src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o.provides.build
.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o.provides

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o.provides.build: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o


src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o: src/file_analysis/CMakeFiles/bro_file_analysis.dir/flags.make
src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o: ../src/file_analysis/Tag.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bro_file_analysis.dir/Tag.cc.o -c /home/ubuntu/bro/src/file_analysis/Tag.cc

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bro_file_analysis.dir/Tag.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/src/file_analysis/Tag.cc > CMakeFiles/bro_file_analysis.dir/Tag.cc.i

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bro_file_analysis.dir/Tag.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/src/file_analysis/Tag.cc -o CMakeFiles/bro_file_analysis.dir/Tag.cc.s

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o.requires:

.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o.requires

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o.provides: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o.requires
	$(MAKE) -f src/file_analysis/CMakeFiles/bro_file_analysis.dir/build.make src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o.provides.build
.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o.provides

src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o.provides.build: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o


src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o: src/file_analysis/CMakeFiles/bro_file_analysis.dir/flags.make
src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o: src/file_analysis/file_analysis.bif.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o -c /home/ubuntu/bro/my_build_dir/src/file_analysis/file_analysis.bif.cc

src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.i"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/bro/my_build_dir/src/file_analysis/file_analysis.bif.cc > CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.i

src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.s"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/bro/my_build_dir/src/file_analysis/file_analysis.bif.cc -o CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.s

src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o.requires:

.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o.requires

src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o.provides: src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o.requires
	$(MAKE) -f src/file_analysis/CMakeFiles/bro_file_analysis.dir/build.make src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o.provides.build
.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o.provides

src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o.provides.build: src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o


# Object files for target bro_file_analysis
bro_file_analysis_OBJECTS = \
"CMakeFiles/bro_file_analysis.dir/Manager.cc.o" \
"CMakeFiles/bro_file_analysis.dir/File.cc.o" \
"CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o" \
"CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o" \
"CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o" \
"CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o" \
"CMakeFiles/bro_file_analysis.dir/Component.cc.o" \
"CMakeFiles/bro_file_analysis.dir/Tag.cc.o" \
"CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o"

# External object files for target bro_file_analysis
bro_file_analysis_EXTERNAL_OBJECTS =

src/file_analysis/libbro_file_analysis.a: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o
src/file_analysis/libbro_file_analysis.a: src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o
src/file_analysis/libbro_file_analysis.a: src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o
src/file_analysis/libbro_file_analysis.a: src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o
src/file_analysis/libbro_file_analysis.a: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o
src/file_analysis/libbro_file_analysis.a: src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o
src/file_analysis/libbro_file_analysis.a: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o
src/file_analysis/libbro_file_analysis.a: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o
src/file_analysis/libbro_file_analysis.a: src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o
src/file_analysis/libbro_file_analysis.a: src/file_analysis/CMakeFiles/bro_file_analysis.dir/build.make
src/file_analysis/libbro_file_analysis.a: src/file_analysis/CMakeFiles/bro_file_analysis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX static library libbro_file_analysis.a"
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && $(CMAKE_COMMAND) -P CMakeFiles/bro_file_analysis.dir/cmake_clean_target.cmake
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bro_file_analysis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/file_analysis/CMakeFiles/bro_file_analysis.dir/build: src/file_analysis/libbro_file_analysis.a

.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/build

src/file_analysis/CMakeFiles/bro_file_analysis.dir/requires: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Manager.cc.o.requires
src/file_analysis/CMakeFiles/bro_file_analysis.dir/requires: src/file_analysis/CMakeFiles/bro_file_analysis.dir/File.cc.o.requires
src/file_analysis/CMakeFiles/bro_file_analysis.dir/requires: src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileTimer.cc.o.requires
src/file_analysis/CMakeFiles/bro_file_analysis.dir/requires: src/file_analysis/CMakeFiles/bro_file_analysis.dir/FileReassembler.cc.o.requires
src/file_analysis/CMakeFiles/bro_file_analysis.dir/requires: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Analyzer.cc.o.requires
src/file_analysis/CMakeFiles/bro_file_analysis.dir/requires: src/file_analysis/CMakeFiles/bro_file_analysis.dir/AnalyzerSet.cc.o.requires
src/file_analysis/CMakeFiles/bro_file_analysis.dir/requires: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Component.cc.o.requires
src/file_analysis/CMakeFiles/bro_file_analysis.dir/requires: src/file_analysis/CMakeFiles/bro_file_analysis.dir/Tag.cc.o.requires
src/file_analysis/CMakeFiles/bro_file_analysis.dir/requires: src/file_analysis/CMakeFiles/bro_file_analysis.dir/file_analysis.bif.cc.o.requires

.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/requires

src/file_analysis/CMakeFiles/bro_file_analysis.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/file_analysis && $(CMAKE_COMMAND) -P CMakeFiles/bro_file_analysis.dir/cmake_clean.cmake
.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/clean

src/file_analysis/CMakeFiles/bro_file_analysis.dir/depend: src/file_analysis/file_analysis.bif.h
src/file_analysis/CMakeFiles/bro_file_analysis.dir/depend: src/file_analysis/file_analysis.bif.cc
src/file_analysis/CMakeFiles/bro_file_analysis.dir/depend: src/file_analysis/file_analysis.bif.init.cc
src/file_analysis/CMakeFiles/bro_file_analysis.dir/depend: scripts/base/bif/file_analysis.bif.bro
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/file_analysis /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/file_analysis /home/ubuntu/bro/my_build_dir/src/file_analysis/CMakeFiles/bro_file_analysis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/file_analysis/CMakeFiles/bro_file_analysis.dir/depend

