# Install script for directory: /home/ubuntu/bro/src/file_analysis/analyzer

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/data_event/cmake_install.cmake")
  include("/home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/entropy/cmake_install.cmake")
  include("/home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/extract/cmake_install.cmake")
  include("/home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/hash/cmake_install.cmake")
  include("/home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/pe/cmake_install.cmake")
  include("/home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/unified2/cmake_install.cmake")
  include("/home/ubuntu/bro/my_build_dir/src/file_analysis/analyzer/x509/cmake_install.cmake")

endif()

