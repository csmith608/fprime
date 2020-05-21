# Install script for directory: /Users/anniesmith/fprime/Ref

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
    set(CMAKE_INSTALL_CONFIG_NAME "DEBUG")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/F-Prime/Autocoders/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/F-Prime/Fw/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/F-Prime/Svc/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/F-Prime/Os/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/F-Prime/Drv/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/F-Prime/CFDP/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/F-Prime/Utils/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/Ref/PingReceiver/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/Ref/RecvBuffApp/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/Ref/SendBuffApp/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/Ref/SignalGen/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/Ref/MathPorts/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/Ref/MathTypes/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/Ref/MathSender/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/Ref/MathReceiver/cmake_install.cmake")
  include("/Users/anniesmith/fprime/Ref/cmake-build-debug/Ref/Top/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/anniesmith/fprime/Ref/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
