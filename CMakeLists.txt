# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("BankingSystem")

# Include sub-projects.
add_subdirectory ("BankingSystem")

# TODO: Add tests and install targets if needed.
add_executable (UnitTest "test.cpp" "pch.cpp" "pch.h")