#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include <map>
#include <random>
using namespace std;
enum class VehicleType
{
	EVTOL,
	OTHER
};

enum class VehicleStatus
{
	ACTIVE,
	OUT_OF_BATTERY,
	IN_CHARGING_QUEUE,
	CHARGING,
	DISABLED
};

class Vehicle {
public:

	/*
	* Update the curent status of this vehicle in the simulator, giving the unit timelapse. 
	*/
	virtual void update(double dt) {}

	virtual VehicleType getVehicleType() { return VehicleType::OTHER; }


	virtual VehicleStatus getVehicleStatus() final{
		return status;
	}

	virtual string toString() {
		return "Base Vehicle Class.\n";
	}


	virtual string getID() final{
		return id;
	}

	virtual string getModelID() final{
		return model_id;
	}

	virtual string getCompanyName() final{
		return maker;
	}

	virtual void setID(string value) final{
		id = value;
	}

	virtual void setModelID(string value) final{
		model_id = value;

	}

	virtual void setCompany(string value) final {
		maker = value;

	}

	virtual void setStatus(VehicleStatus value) final {
		status = value;
	}

	string getStatusString() {
		switch (status) {
		case VehicleStatus::ACTIVE:
			return "Active";
		case VehicleStatus::OUT_OF_BATTERY:
			return "Out of Battery";
		case VehicleStatus::IN_CHARGING_QUEUE:
			return "Pending for Charger";
		case VehicleStatus::CHARGING:
			return "Being Charged";
		case VehicleStatus::DISABLED:
			return "Disabled";
		}
	}

protected:
	string id;
	string model_id;
	string maker;
	VehicleStatus status = VehicleStatus::DISABLED;

	
};


#endif 