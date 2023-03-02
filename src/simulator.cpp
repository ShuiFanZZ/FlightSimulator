#include "simulator.h"

Simulator::Simulator(double time, vector<Vehicle*> vehicles, Charger* charger) {
	this->vehicles = vehicles;
	this->charger = charger;
	this->simulation_time = time;
	this->iter = rint(this->simulation_time * SIMULATION_PRECISION);
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