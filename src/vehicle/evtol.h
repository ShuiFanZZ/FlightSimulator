#ifndef EVTOL_H
#define EVTOL_H
#include "vehicle.h"
class Evtol : public Vehicle {
public:
	Evtol();

	void update(double dt) override;

	string toString() override;

	void setCruiseSpeed(double value) {
		cruise_speed = value;
	}

	void setBatteryCapacity(double value) {
		battery_capacity = value;
	}

	void setBatteryFull() {
		battery_left = battery_capacity;
	}

	void setTimeToCharge(double value) {
		time_to_charge = value;
	}

	void setCruiseEnergyUse(double value) {
		energy_use_cruise = value;
	}

	void setNumPassenger(int value) {
		num_passenger = value;

	}

	void setFaultRate(double value) {
		fault_rate = value;
	}

	// Normally called by a charger. Start a charging session.
	// Update: Consider joining queue as the start of a charging session.
	void startChargingSession() {
		num_charge++;
		status = VehicleStatus::IN_CHARGING_QUEUE;
	}

	double getMilage() {
		return milage;
	}

	int getNumFault() {
		return num_fault;
	}

	int getNumPassenger() {
		return num_passenger;
	}

	int getNumCharge() {
		return num_charge;
	}

	double getTotalChargeTime() {
		return time_charged_total;
	}

	double getTotalFightTime() {
		return time_flight_total;
	}

	int getNumFlight() {
		return num_flight;
	}

	double getBatteryLeft() {
		return battery_left;
	}

	double getTotalQueueTime() {
		return time_queue_total;
	}

	VehicleType getVehicleType() {
		return VehicleType::EVTOL;
	}

private:

	// Cruise Speed (mph)
	double cruise_speed;
	// Battery Capacity (kWh)
	double battery_capacity;
	// Time to Charge (hours)
	double time_to_charge;
	// Energy use at Cruise (kWh/mile)
	double energy_use_cruise;
	// Passenger Count
	int num_passenger;
	// Probability of fault per hour
	double fault_rate;

	double milage = 0.0;
	int num_fault = 0;
	double battery_left = 0.0;
	double time_charged = 0.0;
	double time_charged_total = 0.0;
	double time_flight_total = 0.0;
	double time_queue_total = 0.0;
	int num_flight = 0;
	int num_charge = 0;


};

#endif