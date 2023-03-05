#include "../src/charger/charger.h"
#include "test_util.h"
#include "../src/vehicle/vehicle.h"
#include "../src/vehicle/evtol.h"
#include <vector>

/*
	Unit tests for Charger object.
*/

static int num_test = 0;
static int num_pass = 0;

Evtol createEvtol() {
	Evtol evtol = Evtol();
	evtol.setStatus(VehicleStatus::OUT_OF_BATTERY);
	evtol.setCruiseSpeed(0.5);
	evtol.setCruiseEnergyUse(1.0);
	evtol.setBatteryCapacity(1.0);
	evtol.setTimeToCharge(2.0);
	return evtol;
}


/*
	Check if vehicle status is changed after being served.
*/
void Test_Charger_Single_Vehicle() {
	num_test++;
	int error = 0;
	Evtol evtol = createEvtol();
	vector<Vehicle*> vehicles = { &evtol };
	FIFSEvtolCharger charger = FIFSEvtolCharger(1);
	charger.serve(vehicles);
	error += ASSERT_EQUAL_STATUS(VehicleStatus::CHARGING, evtol.getVehicleStatus());
	error += ASSERT_EQUAL(1, evtol.getNumCharge(), "Number of Chargeing Session");
	if (error == 0) {
		num_pass++;
	}
	else {
		cout << "Test_Charger_Single_Vehicle failed." << endl;
	}
}


/*
	A charger can only serve vehilces up to its capacity, the rest will be in queue.
	Also check if FIFS charger adopts FIFS policy.
*/
void Test_Charger_Capcity() {
	num_test++;
	int error = 0;
	Evtol evtol1 = createEvtol();
	Evtol evtol2 = createEvtol();
	vector<Vehicle*> vehicles = { &evtol1, &evtol2 };
	FIFSEvtolCharger charger = FIFSEvtolCharger(1);
	charger.serve(vehicles);
	error += ASSERT_EQUAL_STATUS(VehicleStatus::CHARGING, evtol1.getVehicleStatus());
	error += ASSERT_EQUAL_STATUS(VehicleStatus::IN_CHARGING_QUEUE, evtol2.getVehicleStatus());
	error += ASSERT_EQUAL(1, evtol1.getNumCharge(), "Number of Chargeing Session");
	// Entering the queue is considered as the start of a charging session
	error += ASSERT_EQUAL(1, evtol2.getNumCharge(), "Number of Chargeing Session");

	if (error == 0) {
		num_pass++;
	}
	else {
		cout << "Test_Charger_Capcity failed." << endl;
	}

}


/*
	Check if the charger serves the next vehicle in queue, when previous vehicle finished charging.
*/
void Test_Charger_Complete_Charging() {
	num_test++;
	int error = 0;
	Evtol evtol1 = createEvtol();
	Evtol evtol2 = createEvtol();
	Evtol evtol3 = createEvtol();
	vector<Vehicle*> vehicles = { &evtol1, &evtol2, &evtol3 };
	FIFSEvtolCharger charger = FIFSEvtolCharger(1);
	charger.serve(vehicles);
	error += ASSERT_EQUAL_STATUS(VehicleStatus::CHARGING, evtol1.getVehicleStatus());
	error += ASSERT_EQUAL_STATUS(VehicleStatus::IN_CHARGING_QUEUE, evtol2.getVehicleStatus());
	error += ASSERT_EQUAL_STATUS(VehicleStatus::IN_CHARGING_QUEUE, evtol3.getVehicleStatus());

	evtol1.setStatus(VehicleStatus::ACTIVE);
	charger.serve({});
	error += ASSERT_EQUAL_STATUS(VehicleStatus::CHARGING, evtol2.getVehicleStatus());
	error += ASSERT_EQUAL_STATUS(VehicleStatus::IN_CHARGING_QUEUE, evtol3.getVehicleStatus());

	if (error == 0) {
		num_pass++;
	}
	else {
		cout << "Test_Charger_Capcity failed." << endl;
	}

}



int main() {
	num_test = 0;
	num_pass = 0;
	Test_Charger_Single_Vehicle();
	Test_Charger_Capcity();
	Test_Charger_Complete_Charging();
	cout << "Evtol Test Pass: " << num_pass << "/" << num_test << endl;

	return num_test - num_pass;
}
