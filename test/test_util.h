#ifndef TEST_UTIL_H
#define TEST_UTIL_H
#include <iostream>

#define EPSILON (1.0E-8)

// Some helper functions for unit test

using namespace std;
int ASSERT_EQUAL(int expected, int actual, string name) {
	if (expected == actual) {
		return 0;
	}
	else {
		cout << "Assertion failed: " << name << " expecting " << expected <<
			"but got " << actual << endl;
		return 1;
	}
}


int ASSERT_EQUAL(double expected, double actual, string name) {
	if (abs(expected - actual) < EPSILON) {
		return 0;
	}
	else {
		cout << "Assertion failed: " << name << " expecting " << expected <<
			"but got " << actual << endl;
		return 1;
	}
}

int ASSERT_EQUAL_STATUS(VehicleStatus expected, VehicleStatus actual) {
	if (expected == actual) {
		return 0;
	}
	else {
		cout << "Assertion failed: vehicle status is not as expected. " << endl;
		return 1;
	}
}

#endif