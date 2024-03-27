# This source file is part of the Swift open source project
#
# Copyright (c) 2023 Apple Inc. and the Swift project authors.
# Licensed under Apache License v2.0 with Runtime Library Exception
#
# See https://swift.org/LICENSE.txt for license information

cmake_minimum_required(VERSION 3.29)
cmake_policy(SET CMP0156 NEW)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options($<$<COMPILE_LANGUAGE:Swift>:-index-store-path> $<$<COMPILE_LANGUAGE:Swift>:${CMAKE_BINARY_DIR}/IndexStore/index>)

# Project PingPong: Bouncing control flow between Swift and C++ like a ping pong
#                   ball.
project(PingPong LANGUAGES C CXX Swift)

# Verify that we have a new enough compiler
if("${CMAKE_Swift_COMPILER_VERSION}" VERSION_LESS 5.9)
  message(FATAL_ERROR "Bidirectional C++ Interop requires Swift 5.9 or greater. Have ${CMAKE_Swift_COMPILER_VERSION}")
endif()

if(NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" AND
   NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
  message(FATAL_ERROR "Project requires building with Clang.
  Have ${CMAKE_CXX_COMPILER_ID}")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

# cmake/modules/AddSwift.cmake provides the function for creating the Swift to
# C++ bridging header
include(AddSwift)

set(PINGPONG_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(PINGPONG_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(PINGPONG_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(PINGPONG_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_OSX_DEPLOYMENT_TARGET 13.0)
set(CMAKE_CXX_STANDARD 17)

include_directories(${PINGPONG_INCLUDE_DIR})

add_subdirectory("${PINGPONG_LIB_DIR}/fibonacci")
add_subdirectory("src/")
