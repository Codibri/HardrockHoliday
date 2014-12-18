// Mareike

#include "Input/BlockedSphericalSector.h"
#include "Input/Falcon.h"
#include <iostream>
#include <iomanip>
#include <cmath>  


BlockedSphericalSector::BlockedSphericalSector() {
}

BlockedSphericalSector::BlockedSphericalSector(int direction, float startPoint, float blockStrength, float blockStrengthIncrease, bool rumbleOnCollide) {
	//memcpy(m_direction, direction, sizeof(direction));
	m_direction = direction;
	m_startPoint = startPoint;
	m_blockStrength = blockStrength;
	m_blockStrengthIncrease = blockStrengthIncrease;
	m_rumbleOnCollide = rumbleOnCollide;
}


BlockedSphericalSector::~BlockedSphericalSector() {
}


float BlockedSphericalSector::crossedBorder(double position) {
	// In der "anderen" Halbkugel / andere Blockierrichtung
	if (position*100 * m_startPoint*5 < 0) {
		return 0.0;
	}
	if (abs(position*100) + CROSSING_PRECISION / 100 > abs(m_startPoint*5)) {
		return abs(position * 100) - abs(m_startPoint * 5);
	}
	return 0.0;
}
