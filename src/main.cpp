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

	for (int i = 0; i < iterations; i++) {
		vector<Vehicle*> vehicles = factory.buildRandomVehicles(num_vehicel);
		FIFSEvtolCharger* charger = new FIFSEvtolCharger(simulation_time_hour);
		Simulator simulator = Simulator(simulation_time_hour, vehicles, charger);
		simulator.simulate();

		stats_tracker.collect(vehicles);
	}
	
	stats_tracker.generateReport();

	
	return 0;
}
