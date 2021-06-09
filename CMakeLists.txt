cmake_minimum_required(VERSION 3.5)

project(GioGraphic)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(main main.cpp GUI.h HardwareObjects.h)

set_target_properties(main PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
