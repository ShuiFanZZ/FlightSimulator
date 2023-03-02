#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "vehicle/vehicle.h"
#include "charger/charger.h"
#include "Config.h"
class Simulator {
public:
	Simulator(double time, vector<Vehicle*> vehicles, Charger* charger);

	void simulate();

private:
	vector<Vehicle*> vehicles;
	Charger* charger;
	vector<Vehicle*> low_battery_vehicles;
	int iter;
	double simulation_time;
	double unit_time = 1.0 / SIMULATION_PRECISION;
		

};

#endif