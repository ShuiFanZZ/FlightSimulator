#ifndef CONFIG_H
#define CONFIG_H

// How many times simulation runs
static int SIMULATION_LOOP = 10;
// How long each simulation runs in hour
static int SIMULATION_TIME = 3;
// How many vehicles are randomly generated in each simulation
static int SIMULATION_VEHICLES = 20;

// number of time frames per hour
static const int HOUR_H = 1;
static const int MINUTE_H = 60;
static const int SECOND_H = 3600;
static const int MSECOND_H = 360000;

// The time precision the simulator is using
static int SIMULATION_PRECISION = SECOND_H;


#endif 