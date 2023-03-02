#include "vehicle_factory.h"
#include "vehicle.h"
#include "evtol.h"

struct Blueprint blueprints[] = {
	{"Evtol", "A", "Alpha Company", 120.0, 320.0, 0.6, 1.6, 4, 0.25},
	{"Evtol", "B", "Bravo Company", 100.0, 100.0, 0.2, 1.5, 5, 0.10},
	{"Evtol", "C", "Charlie Company", 160.0, 220.0, 0.8, 2.2, 3, 0.05},
	{"Evtol", "D", "Delta Company", 90.0, 120, 0.62, 0.8, 2, 0.22},
	{"Evtol", "E", "Echo Company", 30.0, 150.0, 0.3, 5.8, 2, 0.61}
};

vector<Vehicle*> VehicleFactory::buildRandomVehicles(int num) {
	vector<Vehicle*> producedVehicles;

	static random_device rd;
	mt19937 generator(rd());

	std::uniform_int_distribution<int> distribution(0, num_blueprint - 1);

	for (int i = 0; i < num; i++)
	{
		int index = distribution(generator);
		producedVehicles.push_back(buildVehicle(blueprints[index]));
	}

	return producedVehicles;
}



Vehicle* VehicleFactory::buildVehicle(struct Blueprint blueprint) {
	Evtol* producedVehicle = new Evtol();
	int id = historyMap[blueprint.vehicleTypeName] + 1;
	historyMap[blueprint.vehicleTypeName]++;
	
	producedVehicle->setID(blueprint.vehicleTypeName + "_" + std::to_string(id));
	producedVehicle->setCompany(blueprint.companyName);
	producedVehicle->setModelID(blueprint.modelName);
	producedVehicle->setCruiseSpeed(blueprint.cruiseSpeed);
	producedVehicle->setTimeToCharge(blueprint.chargeTime);
	producedVehicle->setFaultRate(blueprint.probFault);
	producedVehicle->setBatteryCapacity(blueprint.batteryCapacity);
	producedVehicle->setBatteryFull();
	producedVehicle->setCruiseEnergyUse(blueprint.energyUse);
	producedVehicle->setNumPassenger(blueprint.passengerCount);
	producedVehicle->setStatus(VehicleStatus::ACTIVE);


	return producedVehicle;
}