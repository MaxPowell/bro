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

# Utility rule file for install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro.

# Include the progress variables for this target.
include scripts/CMakeFiles/install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro.dir/progress.make

scripts/CMakeFiles/install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/bro/my_build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Installing /usr/local/share/bro/site/local-proxy.bro.example"
	cd /home/ubuntu/bro/my_build_dir/scripts && /usr/bin/cmake -E copy /home/ubuntu/bro/scripts/site/local-proxy.bro ${DESTDIR}/usr/local/share/bro/site/local-proxy.bro.example

install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro: scripts/CMakeFiles/install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro
install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro: scripts/CMakeFiles/install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro.dir/build.make

.PHONY : install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro

# Rule to build all files generated by this target.
scripts/CMakeFiles/install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro.dir/build: install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro

.PHONY : scripts/CMakeFiles/install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro.dir/build

scripts/CMakeFiles/install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro.dir/clean:
	cd /home/ubuntu/bro/my_build_dir/scripts && $(CMAKE_COMMAND) -P CMakeFiles/install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro.dir/cmake_clean.cmake
.PHONY : scripts/CMakeFiles/install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro.dir/clean

scripts/CMakeFiles/install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro.dir/depend:
	cd /home/ubuntu/bro/my_build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/bro /home/ubuntu/bro/scripts /home/ubuntu/bro/my_build_dir /home/ubuntu/bro/my_build_dir/scripts /home/ubuntu/bro/my_build_dir/scripts/CMakeFiles/install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : scripts/CMakeFiles/install-example-config-.home.ubuntu.bro.scripts.site.local-proxy.bro.dir/depend

