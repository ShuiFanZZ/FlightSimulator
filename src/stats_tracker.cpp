#include "stats_tracker.h"

void StatsTracker::collect(vector<Vehicle*> vehicles) {
	for (Vehicle* v : vehicles) {
		
		
		if (VehicleType::EVTOL == v->getVehicleType()) {
			Evtol* evtol = (Evtol*)v;
			collectEvtol(evtol);
		}
	}
}

void StatsTracker::collectEvtol(Evtol* evtol) {
	struct StatsReport stats = this->modelStatsMap[evtol->getModelID()];

	stats.total_distance += evtol->getMilage();
	stats.total_charge_time += evtol->getTotalChargeTime();
	stats.total_flight_time += evtol->getTotalFightTime();
	stats.count_flight += evtol->getNumFlight();
	stats.count_charge += evtol->getNumCharge();
	stats.count_fault += evtol->getNumFault();
	stats.num_passenger = evtol->getNumPassenger();

	this->modelStatsMap[evtol->getModelID()] = stats;
}

void StatsTracker::generateReport() {
	for (auto it = modelStatsMap.begin(); it != modelStatsMap.end(); it++) {
		cout << it->first << endl << it->second.toStatsString() << endl << endl;
	}
}

