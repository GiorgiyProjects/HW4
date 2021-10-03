cmake_minimum_required(VERSION 3.5)

project(GioGraphic)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(GioGraphic main.cpp Model.h View.h Controller.h Shape.h)

set_target_properties(GioGraphic PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
