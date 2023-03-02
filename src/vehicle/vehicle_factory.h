#ifndef VEHICLE_FACTORY_H
#define VEHICLE_FACTORY_H
#include <random>
#include <string>
#include <vector>
#include <unordered_map>
#include "vehicle.h"

using namespace std;

/*
	VehicleFactory class is responsible for constructing Vehicle instances
	used in the simulation. 

*/
class VehicleFactory {
public:
	/*
	* Build vehicles randomly from blueprints.
	* Return a vector of num vehicles.
	*/
	vector<Vehicle*> buildRandomVehicles(int num);

private:
	Vehicle* buildVehicle(struct Blueprint blueprint);
	
	// stores the number of produced vehicels for each model
	std::unordered_map<string, int> historyMap;
	int num_blueprint = 5;
};


// stats and info of a vehicle model
struct Blueprint{
	string vehicleTypeName;
	string modelName;
	string companyName;
	double cruiseSpeed;
	double batteryCapacity;
	double chargeTime;
	double energyUse;
	int passengerCount;
	double probFault;

};


#endif