# FlightSimulator
A flight simulator that simulate the behaviors of various vehicles, and keep track of 
the statistics (milage, faults, etc) for each type of vehicles.

****
## Design
### 1. Objects that participate in the simulation
#### 1.1 Vehicles
* `vehicle/vehicle.h` : the interface of all types of vehicle objects. The `update(dt)` method is called 
to update a vehicle's states as time elapses in a simulation.
* `vehicle/evtol.h` : E-VTOL object that implements the vehicle interface.
* `vehicle/vehicle_factory.h` : abstracts the process of building vehicle objects, and also 
provides the functionality to generate a list of random vehicles used in simulation.
#### 1.2 Charger
* `charger/charger.h` : the interface of charger objects. A charger serves vehicles in the simulation who
need charging after battery runs out.
* `charger/fifs_evtol_charger.h` : a charger for E-VTOL that follows a First-In-First-Serve policy.
### 2. Simulator
* `simulator.h` : simulates the behavior of given objects with the specified time length and precision.
### 3. Stats Tracker
* `stats_tracker.h` : keeps track of the statistics of each type of vehicles throughout simulation sessions.
### 4. Other
* `main.cpp` : the main program.
* `Config.h` : stores some global variables, such as number of simulation runs.
* `test/` : contains all the unit tests.

****

## Results
### Sample Vehicles
Company Name  | Alpha Company | Bravo Company | Charlie Company| Delta Company|Echo Company | 
---------| --------| --------| --------| --------| --------|
Cruise Speed (mph)		| 120 | 100 | 160 | 90 | 30  |
Battery Capacity (kWh)  | 320 | 100 | 200 | 120 | 150 |
Time to Charge (hours)  | 0.6 | 0.2 | 0.8 | 0.62 | 0.3 |
Energy use at Cruise (kWh/mile)  | 1.6 | 1.5 | 2.2 | 0.8 | 5.8 |
Passenger Count | 4 | 5 | 3 | 2 | 2 |
Probability of fault per hour  | 0.25 | 0.10 | 0.05 | 0.22 | 0.61 |
### Output
(10 iterations, 3 hours each, 20 random vehicles per session)
```
B
Average Flight Time per Flight: 0.660885
Average Distance Traveled per Flight: 66.088457
Average Charge Time per Session: 0.766958
Total Faults: 17
Total Passenger Miles: 34035.555556


D
Average Flight Time per Flight: 1.628089
Average Distance Traveled per Flight: 146.527976
Average Charge Time per Session: 1.332202
Total Faults: 33
Total Passenger Miles: 12308.350000


A
Average Flight Time per Flight: 1.183069
Average Distance Traveled per Flight: 141.968306
Average Charge Time per Session: 1.149558
Total Faults: 38
Total Passenger Miles: 34640.266667


C
Average Flight Time per Flight: 0.625000
Average Distance Traveled per Flight: 100.000000
Average Charge Time per Session: 0.920455
Total Faults: 7
Total Passenger Miles: 19800.000000


E
Average Flight Time per Flight: 0.782158
Average Distance Traveled per Flight: 23.464752
Average Charge Time per Session: 0.967591
Total Faults: 65
Total Passenger Miles: 3472.783333
```
