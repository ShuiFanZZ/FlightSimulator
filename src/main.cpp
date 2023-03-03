// Main program for the simulator
//
#include <iostream>
#include <vector>
#include "vehicle/vehicle_factory.h"
#include "vehicle/vehicle.h"
#include "simulator.h"
#include "charger/charger.h"
#include "stats_tracker.h"
#include "Config.h"
using namespace std;

int main()
{	
	int num_vehicel = SIMULATION_VEHICLES;
	int simulation_time_hour = SIMULATION_TIME;
	int iterations = SIMULATION_LOOP;

	VehicleFactory factory = VehicleFactory();
	StatsTracker stats_tracker = StatsTracker();

	// Simulation Loop
	for (int i = 0; i < iterations; i++) {
		// Factory builds random vehicles for this simulation iteration
		vector<Vehicle*> vehicles = factory.buildRandomVehicles(num_vehicel);
		// Create chargers for this simulation 
		FIFSEvtolCharger* charger = new FIFSEvtolCharger(simulation_time_hour);
		// Add vehicles and charger object to simulator. Specify simulation time precision, e.g second.
		Simulator simulator = Simulator(simulation_time_hour, vehicles, charger, SIMULATION_PRECISION);
		// Start simulation
		simulator.simulate();

		// Collect simulation results
		stats_tracker.collect(vehicles);
	}
	
	stats_tracker.generateReport();

	
	return 0;
}
