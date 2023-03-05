#include "../src/vehicle/vehicle.h"
#include "../src/vehicle/evtol.h"
#include "test_util.h"

/*
	Unit tests for Evtol object.
*/

static int num_test = 0;
static int num_pass = 0;

Evtol createEvtol() {
	Evtol evtol = Evtol();
	evtol.setStatus(VehicleStatus::ACTIVE);
	evtol.setCruiseSpeed(0.5);
	evtol.setCruiseEnergyUse(1.0);
	evtol.setBatteryCapacity(1.0);
	evtol.setTimeToCharge(2.0);
	evtol.setBatteryFull();
	return evtol;
}


/*
	Check if the milage increases during flight
*/
void Test_Flight_Single_Update() {
	num_test++;
	int error = 0;
	Evtol evtol = createEvtol();
	double dt = 1.0;
	evtol.update(dt);
	error += ASSERT_EQUAL(1.0, evtol.getTotalFightTime(), "Total flight time");
	error += ASSERT_EQUAL(0.5, evtol.getMilage(), "Milage");

	if (error == 0) {
		num_pass++;
	}
	else {
		cout << "Test_Flight_Single_Update failed." <<  endl;
	}
}

/*
	Check if battery decrease during flight, and if status is changed when battery runs out.
*/
void Test_Flight_Low_Battery() {
	num_test++;
	int error = 0;
	Evtol evtol = createEvtol();
	double dt = 1.0;
	evtol.update(dt);
	evtol.update(dt);
	error += ASSERT_EQUAL(0.0, evtol.getBatteryLeft(), "Battery left");
	error += ASSERT_EQUAL_STATUS(VehicleStatus::OUT_OF_BATTERY, evtol.getVehicleStatus());
	if (error == 0) {
		num_pass++;
	}
	else {
		cout << "Test_Flight_Low_Battery failed." << endl;
	}
}

/*
	Check if charge time is updated and if status is changed when charging is complete.
*/
void Test_Charge_Complete() {
	num_test++;
	int error = 0;
	Evtol evtol = createEvtol();
	evtol.setStatus(VehicleStatus::CHARGING);
	double dt = 1.0;
	evtol.update(dt);
	evtol.update(dt);
	error += ASSERT_EQUAL(2.0, evtol.getTotalChargeTime(), "Total charge time");
	error += ASSERT_EQUAL_STATUS(VehicleStatus::ACTIVE, evtol.getVehicleStatus());
	if (error == 0) {
		num_pass++;
	}
	else {
		cout << "Test_Flight_Low_Battery failed." << endl;
	}
}

/*
	Check if the queue time gets updated when waiting for charger
*/
void Test_Queue_Update() {
	num_test++;
	int error = 0;
	Evtol evtol = createEvtol();
	evtol.setStatus(VehicleStatus::IN_CHARGING_QUEUE);
	double dt = 1.0;
	evtol.update(dt);
	error += ASSERT_EQUAL(1.0, evtol.getTotalQueueTime(), "Total queue time");

	if (error == 0) {
		num_pass++;
	}
	else {
		cout << "Test_Flight_Single_Update failed." << endl;
	}
}

int main() {
	num_test = 0;
	num_pass = 0;
	Test_Flight_Single_Update();
	Test_Flight_Low_Battery();
	Test_Charge_Complete();
	Test_Queue_Update();

	cout << "Evtol Test Pass: " << num_pass << "/" << num_test << endl;

	return num_test - num_pass;
}
