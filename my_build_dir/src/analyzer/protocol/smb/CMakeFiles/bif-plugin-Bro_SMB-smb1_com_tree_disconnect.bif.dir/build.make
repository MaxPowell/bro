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

# Utility rule file for bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif.

# Include the progress variables for this target.
include src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif.dir/progress.make

src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif: src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.h
src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif: src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.cc
src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif: src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.init.cc


src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.h: ../src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif
src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.h: src/bifcl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BIFCL] Processing smb1_com_tree_disconnect.bif"
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/smb && ../../../bifcl -p Bro::SMB /home/ubuntu/bro/src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif || ( rm -f smb1_com_tree_disconnect.bif.h smb1_com_tree_disconnect.bif.cc smb1_com_tree_disconnect.bif.init.cc smb1_com_tree_disconnect.bif.register.cc && exit 1 )
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/smb && /usr/bin/cmake -E copy smb1_com_tree_disconnect.bif.bro /home/ubuntu/bro/my_build_dir/scripts/base/bif/plugins/Bro_SMB.smb1_com_tree_disconnect.bif.bro
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/smb && /usr/bin/cmake -E remove -f smb1_com_tree_disconnect.bif.bro

src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.cc: src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.cc

src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.init.cc: src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.init.cc

src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.register.cc: src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.register.cc

scripts/base/bif/plugins/Bro_SMB.smb1_com_tree_disconnect.bif.bro: src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.h
	@$(CMAKE_COMMAND) -E touch_nocreate scripts/base/bif/plugins/Bro_SMB.smb1_com_tree_disconnect.bif.bro

bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif: src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif
bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif: src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.h
bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif: src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.cc
bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif: src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.init.cc
bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif: src/analyzer/protocol/smb/smb1_com_tree_disconnect.bif.register.cc
bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif: scripts/base/bif/plugins/Bro_SMB.smb1_com_tree_disconnect.bif.bro
bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif: src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif.dir/build.make

.PHONY : bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif

# Rule to build all files generated by this target.
src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif.dir/build: bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif

.PHONY : src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif.dir/build

src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/smb && $(CMAKE_COMMAND) -P CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif.dir/cmake_clean.cmake
.PHONY : src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif.dir/clean

src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/src/analyzer/protocol/smb /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/smb /home/ubuntu/bro/my_build_dir/src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/analyzer/protocol/smb/CMakeFiles/bif-plugin-Bro_SMB-smb1_com_tree_disconnect.bif.dir/depend

