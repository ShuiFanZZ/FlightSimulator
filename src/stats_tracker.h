#ifndef STATS_TRACKER_H
#define STATS_TRACKER_H
#include <vector>
#include <unordered_map>
#include "vehicle/vehicle.h"
#include "vehicle/evtol.h"
using namespace std;
/*
	StatsTracker collect results of a simulation session, and generates statistics report.
*/

class StatsTracker {
public:
	/*
		Collect the statictis from a list of vehicles.
	*/
	void collect(vector<Vehicle*> vehicles);

	/*
		Generate collected statistics.
	*/
	void generateReport();
private:
	unordered_map<string, struct StatsReport> modelStatsMap;

	void collectEvtol(Evtol* evtol);
};

struct StatsReport {
	double total_distance = 0.0;
	double total_charge_time = 0.0;
	double total_flight_time = 0.0;
	int count_flight = 0;
	int count_charge = 0;
	int count_fault = 0;
	int num_passenger = 0;

	string toStatsString() {
		return
			"Average Flight Time per Flight: " +
			to_string(total_flight_time / count_flight) + "\n" +
			"Average Distance Traveled per Flight: " +
			to_string(total_distance / count_flight) + "\n" +
			"Average Charge Time per Session: " +
			to_string(total_charge_time / count_charge) + "\n" +
			"Total Faults: " + to_string(count_fault) + "\n" +
			"Total Passenger Miles: " + to_string(total_distance * num_passenger) + "\n";
	}

};


#endif 