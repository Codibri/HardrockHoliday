// Mareike

#pragma once

#include "FalconManager.h"
#include <iostream>
#include <iomanip>


class FalconTestUtil {

public:
	FalconTestUtil();
	~FalconTestUtil();

	// Testprogramm Knopf drücken und an Nullpunkt fahren
	void testMoveToZero();

	// Testprogramm Rumble 
	void testRumble();

	// Testprogramm Spherical blocking
	void testSphericalBlocking();

	// Testmethoden einzelne Motoren blockieren
	void blockDirection(int direction, double strength);

private: 
	FalconManager falconManager;
};
