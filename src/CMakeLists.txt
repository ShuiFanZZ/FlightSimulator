# CMakeList.txt : CMake project for FlightSimulator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (
FlightSimulator
"main.cpp"
"vehicle/vehicle_factory.h"
"vehicle/vehicle_factory.cpp"
"simulator.h" 
"simulator.cpp" 
"stats_tracker.h" 
"stats_tracker.cpp" 
"Config.h"
)

# Vehicle Libraries
add_subdirectory(vehicle)
target_link_libraries(FlightSimulator vehicle)

# Charger Libraries
add_subdirectory(charger)
target_link_libraries(FlightSimulator charger)

