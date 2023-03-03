#include "simulator.h"

Simulator::Simulator(double time, vector<Vehicle*> vehicles, Charger* charger, int precision_mode) {
	this->vehicles = vehicles;
	this->charger = charger;
	this->simulation_time = time;
	this->iter = (int)rint(this->simulation_time * precision_mode);
	this->unit_time = 1.0 / precision_mode;
}

void Simulator::simulate() {
	for (int i = 0; i < this->iter; i++) {
		for (Vehicle* v : this->vehicles) {
			v->update(this->unit_time);

			if (VehicleStatus::OUT_OF_BATTERY == v->getVehicleStatus()) {
				this->low_battery_vehicles.push_back(v);
			}
		}
		
		
		charger->serve(this->low_battery_vehicles);
		this->low_battery_vehicles.clear();

	
	}
}