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
"vehicle/vehicle.h"
"vehicle/evtol.cpp"

 "charger/charger.h" "charger/fifs_evtol_charger.cpp" "vehicle/evtol.h" "simulator.h" "simulator.cpp" "stats_tracker.h" "stats_tracker.cpp" "Config.h")

# TODO: Add tests and install targets if needed.
