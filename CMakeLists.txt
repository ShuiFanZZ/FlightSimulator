# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("FlightSimulator" LANGUAGES CXX)

enable_testing()

# Include sub-projects.
add_subdirectory ("src")

# Include unit tests
add_subdirectory("test")