#ifndef CHARGER_H
#define CHARGER_H
#include<vector>
#include<queue>
#include<unordered_set>
#include "../vehicle/vehicle.h"
#include "../vehicle/evtol.h"
using namespace std;

/*
	Interface for charger object. Serves battery powered vehicles.
*/

class Charger {
public:
	// Serve the input vehicles
	virtual void serve(vector<Vehicle*> vehicles_to_serve) {};

protected:
	int capacity;
	int occupancy = 0;

};

/*
	A charger that serves EVTOL and follows a First-in-First-Serve policy.
*/
class FIFSEvtolCharger : public Charger {
public:
	FIFSEvtolCharger(int capacity) {
		this->capacity = capacity;
	}

	void serve(vector<Vehicle*> vehicles_to_serve) override;


private:
	queue<Evtol*> queue;
	unordered_set<Evtol*> serving_set;

};

#endif