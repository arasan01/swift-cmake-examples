# This source file is part of the Swift open source project
#
# Copyright (c) 2023 Apple Inc. and the Swift project authors.
# Licensed under Apache License v2.0 with Runtime Library Exception
#
# See https://swift.org/LICENSE.txt for license information

cmake_minimum_required(VERSION 3.29)
cmake_policy(SET CMP0156 NEW)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(Project2 LANGUAGES Swift)

add_subdirectory("lib/")
add_subdirectory("src/")
