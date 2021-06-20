cmake_minimum_required(VERSION 3.5)

project(GioGraphic)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(GioGraphic main.cpp GUI.h HardwareObjects.h Primitives.h Controller.h Model.h Events.h GUI.cpp Controller.cpp HardwareObjects.cpp Events.cpp)

set_target_properties(GioGraphic PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
