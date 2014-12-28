// Mareike

#include "Input/FalconManager.h"
#include "Input/Falcon.h"
#include <iostream>
#include <iomanip>
#include <cmath>  

//	Setup sequence :
// 	** hdlInitNamedDevice(...);
// 	** hdlStart();
// 	** hdlCreateServoOp(...);

// Teardown sequence :
// 	** hdlDestroyServoOp(...);
// 	** hdlStop();
// 	** hdlUninitDevice(...);


FalconManager::FalconManager() {
	blockedSectors[DIRECTION_RIGHT] = new BlockedSphericalSector(0, 0.8f, -10.0f, -0.0f, false);
	blockedSectors[DIRECTION_LEFT] = new BlockedSphericalSector(0, -0.8f, 10.0f, 0.0f, false);

	blockedSectors[DIRECTION_TOP] = new BlockedSphericalSector(1, 1.5f, -0.0f, -0.0f, false);
	blockedSectors[DIRECTION_BOTTOM] = new BlockedSphericalSector(1, -0.05f, 10.0f, 0.0f, false);

	blockedSectors[DIRECTION_BACK] = new BlockedSphericalSector(2, 0.2f, -5.0f, -5.0f, false);
	blockedSectors[DIRECTION_FRONT] = new BlockedSphericalSector(2, -0.2f, 5.0f, 1.0f, false);

	//falconTestUtil.blockDirection(0, -10);		// Block RECHTS
	//falconTestUtil.blockDirection(0, 10);			// Block LINKS
	//falconTestUtil.blockDirection(1, -10);		// Block OBEN
	//falconTestUtil.blockDirection(1, 10);			// Block UNTEN
	//falconTestUtil.blockDirection(2, -10);		// Block HINTEN
	//falconTestUtil.blockDirection(2, 10);			// Block VORNE
}

FalconManager::~FalconManager() {
}



void FalconManager::init() {
	// DEFAULT Device init
	// siehe auch HDAL.INI
	m_deviceHandle = hdlInitNamedDevice("DEFAULT");
	if (m_deviceHandle == HDL_INVALID_HANDLE) {
		std::cout << "Could not open device, Device Failure" << std::endl;
	}

	// Servo thread starten
	hdlStart();

	// Forcefeedback aktivieren ohne Blockieren des ServoOps
	// ** @param[in] pServoOp  Pointer to servo operation function
	// ** @param[in] pParam    Pointer to data for servo operation function
	// ** @param[in] bBlocking Flag to indicate whether servo loop blocks
	m_servoOp = hdlCreateServoOp(ContactCB, this, false);
	if (m_servoOp == HDL_INVALID_HANDLE) {
		std::cout << "Invalid servo op handle Device Failure" << std::endl;
	}

	// Falcon in Fokus setzen
	hdlMakeCurrent(m_deviceHandle);

	// [IN] Speichere Dimensionen des Falcon Device 3D Workspaces in m_workspaceDims
	// Für Mapping zwischen Game und Falcon Device Workspace
	// minX,  minY,  minZ,   maxX,   maxY, maxZ
	// links, unten, hinten, rechts, oben, vorne
	hdlDeviceWorkspace(m_workspaceDims);

	// Transformation Game und Falcon Device Workspace
	// Original in inches
	double gameWorkspace[] = { -2, -2, -2, 2, 2, 3 };
	// double gameWorkspace[] = { -1, -1, -1, 1, 1, 1 };
	bool useUniformScale = true;
	hdluGenerateHapticToAppWorkspaceTransform(m_workspaceDims,
											  gameWorkspace,
											  useUniformScale,
											  m_transformMat);
	m_forceServo[0] = 0.0;		// 10 sperrt nach links hin, -10 nach rechts
	m_forceServo[1] = 0.0;		// 10 sperrt nach unten hin, -10 nach oben
	m_forceServo[2] = 0.0;		// 10 sperrt nach vorne hin, -10 nach hinten
	m_inited = true;
	ContactCB(this);
}



// Setup in umgekehrter Reihenfolge
void FalconManager::uninit() {
	if (m_servoOp != HDL_INVALID_HANDLE) 	{
		hdlDestroyServoOp(m_servoOp);
		m_servoOp = HDL_INVALID_HANDLE;
	}

	// Stop Servo thread
	hdlStop();

	if (m_deviceHandle != HDL_INVALID_HANDLE) 	{
		hdlUninitDevice(m_deviceHandle);
		m_deviceHandle = HDL_INVALID_HANDLE;
	}
	m_inited = false;
}

// This is the entry point used by the application to synchronize
// data access to the device.  Using this function eliminates the 
// need for the application to worry about threads.
//void Haptics::synchFromServo() {
//hdlCreateServoOp(GetStateCB, this, bBlocking);
//}


// Fahre zu Position
// Position (x, y, z)
// Precision in cm (möglichst nicht kleiner als 0.2)
// Sicherheitsexit, falls Precision zu klein
void FalconManager::moveToPosition(double position[3], double precision) {
	bool positionReached = false;
	int count = 5000;
	while (!positionReached && count > 0) {
		// Hole aktuelle Position
		hdlToolPosition(m_positionServo);
		//printPosition();

		positionReached = true;

		// TODO: mit Schleife
		double delta = (position[0] * 5) - (m_positionServo[0] * 100);
		if (abs(delta) > precision) {
			m_forceServo[0] = getForceBetween(delta, 2.0, 0.8, count);
			//printDouble(delta);
			positionReached = false;
		}

		delta = (position[1] * 5) - (m_positionServo[1] * 100);
		if (abs(delta) > precision) {
			m_forceServo[1] = getForceBetween(delta, 2.0, 0.8, count);
			//printDouble(delta);
			positionReached = false;
		}

		delta = (position[2] * 5) - (m_positionServo[2] * 100);
		if (abs(delta) > precision) {
			m_forceServo[2] = getForceBetween(delta, 5.0, 4.0, count);
			//printDouble(delta);
			positionReached = false;
		}

		// Wait
		for (int i = 0; i < 500; i++) {
			for (int j = 0; j < 1000; j++) {}
		}

		// Motorenstärken aktualisieren
		ContactCB(this);
		count--;
	}
	m_forceServo[0] = 0.0;
	m_forceServo[1] = 0.0;
	m_forceServo[2] = 0.0;
	ContactCB(this);
}

void FalconManager::rumbleSwitch(float strength) {
	// Push Force Werte
	double forcePush[3];
	memcpy(forcePush, m_forceServo, sizeof(m_forceServo));

	if (rumbleDirection) {
		m_forceServo[0] = strength;
		m_forceServo[1] = strength;
		m_forceServo[2] = strength;
	}
	else {
		m_forceServo[0] = -strength;
		m_forceServo[1] = -strength;
		m_forceServo[2] = -strength;
	}
	rumbleDirection = !rumbleDirection;
	ContactCB(this);

	// Pop Force Werte
	m_forceServo[0] = forcePush[0];		
	m_forceServo[1] = forcePush[1];	
	m_forceServo[2] = forcePush[2];
}

void FalconManager::updateBlocking() {
	//hdlToolPosition(m_positionServo);
	ContactCB(this);
	for (int i = 0; i < 6; i++) { 
		BlockedSphericalSector* bss = blockedSectors[i];
		float borderCrossing = bss->crossedBorder(m_positionServo[bss->m_direction]);
		if (borderCrossing > 0.0) {
			if (i % 2 == 1 && m_forceServo[bss->m_direction] < 0.0) {
				// TODO: Fehler 
				printDouble(13333337.0);
			}
			else {
				//m_forceServo[bss->m_direction] = bss->m_blockStrength;
				m_forceServo[bss->m_direction] = bss->m_blockStrength + borderCrossing*bss->m_blockStrengthIncrease;
				//printDouble(m_forceServo[bss->m_direction]);
			}
		}
		else if (i % 2 == 0) {
			m_forceServo[bss->m_direction] = 0.0;
		}
	}
	/*if (m_forceServo[2] < 0.0) {
		m_forceServo[0] = 0.0;
		m_forceServo[1] = 0.0;
		m_forceServo[2] = -10.0;
		ContactCB(this);
		printDouble(m_forceServo[2]);
		while (true);
	}*/

	//hdlSetToolForce(m_forceServo);
	ContactCB(this);
}

float FalconManager::getNewPosition(int direction) {
	ContactCB(this);
	hdlToolPosition(m_positionServo);
	// TODO direction checken ob 0 1 2 
	// TODO 3 inch in z richtung
	//printPosition();
	return m_positionServo[direction]*100/(2*inch);
}


HDLServoOpExitCode ContactCB(void* pUserData) {
	FalconManager* haptics = static_cast< FalconManager* >(pUserData);
	// Hole aktuelle Position
	hdlToolPosition(haptics->m_positionServo);
	// Hole aktuellen Status der Knöpfe (momentan nicht verwendet)
	hdlToolButton(&(haptics->m_buttonServo));

	// TODO: Falls Probleme mit der Falcon, Umstellung auf Tastatur
	// TODO: hdlGetState();
	// TODO: hdlGetError();

	// Call the function that does the heavy duty calculations.  ->WallContact(); ??
	// haptics->cubeContact();
	// TODO:  WIeder rein

	// Motorenstärken aktualisieren
	hdlSetToolForce(haptics->m_forceServo);

	return HDL_SERVOOP_CONTINUE;
}

void FalconManager::printPosition() {
	std::cout << "x = " << std::setw(8) << std::setprecision(5) << std::fixed << m_positionServo[0] * inch / 2
		<< " y = " << std::setw(8) << m_positionServo[1] * inch / 2
		<< " z = " << std::setw(8) << m_positionServo[2] * inch / 2 << std::endl;
}

void FalconManager::printDouble(double d) {
	std::cout << "d = " << std::setw(8) << std::setprecision(5) << std::fixed << d << std::endl;
}

double FalconManager::getForceBetween(double force, double forceMax, double forceMin, int count) {
	double newForce = force;
	if (abs(force) > forceMax) {
		newForce = forceMax;
		if (count > 1000) {
			newForce += forceMin;
		}
		if (force * forceMax < 0) {
			newForce = -newForce;
		}
	}
	else if (abs(force) < forceMin) {
		newForce = forceMin;
		if (force * forceMin < 0) {
			newForce = -forceMin;
		}
	}
	return newForce;
}