// Mareike

#include "Input/FalconTestUtil.h"


FalconTestUtil::FalconTestUtil() {
	falconManager.init();
}


FalconTestUtil::~FalconTestUtil() {
}

void FalconTestUtil::testMoveToZero() {
	while (true) {
		ContactCB(&falconManager);
		if (falconManager.m_buttonServo) {
			double pos[3] = { 0.0, 0.04, 0.0 };
			falconManager.printPosition();
			falconManager.moveToPosition(pos, 0.2);
			falconManager.printPosition();
		}
	}
}

void FalconTestUtil::testRumble() {
	while (true) {
		ContactCB(&falconManager);
		if (falconManager.m_buttonServo) {
			for (int i = 0; i < 500; i++) {}
			falconManager.rumbleSwitch(10);
		}
	}
}

void FalconTestUtil::testSphericalBlocking() {
	ContactCB(&falconManager);
	//while (!falconManager.m_buttonServo);

	double pos[3] = { 0.0, 0.04, 0.0 };
	falconManager.printPosition();
	falconManager.moveToPosition(pos, 0.2);
	falconManager.printPosition();

	while (true) {
		//for (int i = 0; i < 50000; i++) {}
		ContactCB(&falconManager);
		falconManager.updateBlocking();
	}
}

void FalconTestUtil::blockDirection(int direction, double strength) {
	ContactCB(&falconManager);
	falconManager.m_forceServo[0] = 0.0;
	falconManager.m_forceServo[1] = 0.0;
	falconManager.m_forceServo[2] = 0.0;

	falconManager.m_forceServo[direction] = strength;
	ContactCB(&falconManager);
	while (true);
}