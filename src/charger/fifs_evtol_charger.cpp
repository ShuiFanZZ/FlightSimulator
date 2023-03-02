#include "charger.h"
#include <queue>
#include <unordered_set>

using namespace std;


void FIFSEvtolCharger::serve(vector<Vehicle*> vehicles_to_serve) {
	// Add low battery EVTOL to queue
	for (Vehicle* v : vehicles_to_serve) {
		if (VehicleType::EVTOL == v->getVehicleType()) {
			Evtol* evtol = (Evtol*)v;
			if (VehicleStatus::OUT_OF_BATTERY == evtol->getVehicleStatus()) {
				queue.push(evtol);
				evtol->setStatus(VehicleStatus::IN_CHARGING_QUEUE);
			}
		}
	}

	// Check if any EVTOLs complete charging
	vector<Evtol*> charge_complete;
	for (Evtol* evtol: this->serving_set) {
		if (VehicleStatus::ACTIVE == evtol->getVehicleStatus()) {
			charge_complete.push_back(evtol);
			
		}
	}
	// remove them from charger
	for (Evtol* evtol : charge_complete) {
		this->serving_set.erase(evtol);
		this->occupancy--;
	}

	// Serve next EVTOL in queue if there is a vacancy
	while (!queue.empty() && this->occupancy < this->capacity) {
		Evtol* evtol = queue.front();
		queue.pop();
		serving_set.insert(evtol);
		evtol->startCharging();
		occupancy++;
	}

}