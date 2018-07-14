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

# Utility rule file for bif-plugin-Bro_SMTP-functions.bif.

# Include the progress variables for this target.
include src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif.dir/progress.make

src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif: src/analyzer/protocol/smtp/functions.bif.h
src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif: src/analyzer/protocol/smtp/functions.bif.cc
src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif: src/analyzer/protocol/smtp/functions.bif.init.cc


src/analyzer/protocol/smtp/functions.bif.h: ../src/analyzer/protocol/smtp/functions.bif
src/analyzer/protocol/smtp/functions.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing functions.bif"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/smtp && ../../../bifcl -p Bro::SMTP /home/ubuntu/bro/src/analyzer/protocol/smtp/functions.bif || ( rm -f functions.bif.h functions.bif.cc functions.bif.init.cc functions.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/smtp && /usr/bin/cmake -E copy functions.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_SMTP.functions.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/smtp && /usr/bin/cmake -E remove -f functions.bif.bro

src/analyzer/protocol/smtp/functions.bif.cc: src/analyzer/protocol/smtp/functions.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/smtp/functions.bif.cc

src/analyzer/protocol/smtp/functions.bif.init.cc: src/analyzer/protocol/smtp/functions.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/smtp/functions.bif.init.cc

src/analyzer/protocol/smtp/functions.bif.register.cc: src/analyzer/protocol/smtp/functions.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/smtp/functions.bif.register.cc

scripts/base/bif/plugins/Bro_SMTP.functions.bif.bro: src/analyzer/protocol/smtp/functions.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_SMTP.functions.bif.bro

bif-plugin-Bro_SMTP-functions.bif: src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif
bif-plugin-Bro_SMTP-functions.bif: src/analyzer/protocol/smtp/functions.bif.h
bif-plugin-Bro_SMTP-functions.bif: src/analyzer/protocol/smtp/functions.bif.cc
bif-plugin-Bro_SMTP-functions.bif: src/analyzer/protocol/smtp/functions.bif.init.cc
bif-plugin-Bro_SMTP-functions.bif: src/analyzer/protocol/smtp/functions.bif.register.cc
bif-plugin-Bro_SMTP-functions.bif: scripts/base/bif/plugins/Bro_SMTP.functions.bif.bro
bif-plugin-Bro_SMTP-functions.bif: src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif.dir/build.make

.PHONY : bif-plugin-Bro_SMTP-functions.bif

# Rule to build all files generated by this target.
src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif.dir/build: bif-plugin-Bro_SMTP-functions.bif

.PHONY : src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif.dir/build

src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/smtp && $(CMAKE_COMMAND) -P CMakeFiles/bif-plugin-Bro_SMTP-functions.bif.dir/cmake_clean.cmake
.PHONY : src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif.dir/clean

src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/analyzer/protocol/smtp /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/smtp /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/protocol/smtp/CMakeFiles/bif-plugin-Bro_SMTP-functions.bif.dir/depend
