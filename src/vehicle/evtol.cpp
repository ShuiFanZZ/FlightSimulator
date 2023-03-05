#include "evtol.h"

Evtol::Evtol() {
	cruise_speed = 0.0;
	battery_capacity = 0.0;
	time_to_charge = 0.0;
	energy_use_cruise = 0.0;
	num_passenger = 0;
	fault_rate = 0.0;
	num_flight = 1;

}

void Evtol::update(double dt) {
	// Update milage and flight time if Active
	if (VehicleStatus::ACTIVE == status) {
		double distance = dt * cruise_speed;
		milage += distance;
		battery_left -= energy_use_cruise * distance;
		time_flight_total += dt;
		if (battery_left < energy_use_cruise * distance) {
			battery_left = 0.0;
			setStatus(VehicleStatus::OUT_OF_BATTERY);
		}

	}
	else if (VehicleStatus::IN_CHARGING_QUEUE == status) {
		time_queue_total += dt;
	}
	// Update battery and charge time if Charging
	else if (VehicleStatus::CHARGING == status) {
		time_charged_total += dt;
		time_charged += dt;
		if (time_charged >= time_to_charge) {
			time_charged = 0.0;
			setBatteryFull();
			setStatus(VehicleStatus::ACTIVE);
			num_flight++;
		}
	}

	// Update number of faults
	static random_device rd;
	mt19937 generator(rd());
	bernoulli_distribution distribution(Evtol::fault_rate * dt); // Assume fault rate is uniform in one-hour time
	if (distribution(generator)) {
		num_fault++;
	}


}


string Evtol::toString() {
	string result = this->id + " {\n";
	result += "Model: " + model_id + "\n";
	result += "Status: " + getStatusString() + "\n";
	result += "Milage: " + std::to_string(milage) + "\n";
	result += "Total Charging Time: " + std::to_string(time_charged_total) + "\n";
	double battery_percentage = battery_left / battery_capacity * 100.0;
	if (VehicleStatus::CHARGING == status) {
		battery_percentage = time_charged / time_to_charge * 100.0;
	}
	result += "Battery: " + std::to_string(battery_percentage) + "%\n";
	result += "Faults: " + std::to_string(num_fault) + "\n";
	result += "}\n";

	return result;
}

