#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "vehicle/vehicle.h"
#include "charger/charger.h"

/*
	Simulator object that runs the simulation with the given objects, and at the time precision
	specified.
*/
class Simulator {
public:
	Simulator(double time, vector<Vehicle*> vehicles, Charger* charger, int precision_mode);

	void simulate();

private:
	vector<Vehicle*> vehicles;
	Charger* charger;
	vector<Vehicle*> low_battery_vehicles;
	int iter;
	double simulation_time;
	double unit_time;
		

};

#endif