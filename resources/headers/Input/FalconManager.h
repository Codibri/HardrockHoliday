// Mareike

#pragma once

#include <hdl/hdl.h>
#include <hdlu/hdlu.h>
#include <iostream>
#include "BlockedSphericalSector.h"
#include "Input\Constants.h"


class FalconManager {

	friend HDLServoOpExitCode ContactCB(void *data);
	friend HDLServoOpExitCode GetStateCB(void *data);

public:

	FalconManager();
	~FalconManager();

	// Initialisieren
	int init();

	// Clean up
	void uninit();

	// Hole aktuelle Position
	// void getPosition();
	float getNewPosition(int direction);

	// Fahre zu Position
	void moveToPosition(double position[3], double precision);

	// Positions�berpr�fung
	// �berpr�fe, ob Motoren aufgrund der neuen Position gesperrt werden m�ssen
	void updateBlocking();

	// Game Steuerung (Neu, Beenden)
	bool isKeyPressed(Game_Inputs key);

	// Rumble
	void rumbleSwitch(float strength);

	// TEST-Methoden:
	void printPosition();
	void printDouble(double d);


	// Falcon erfolgreich initialisiert
	bool m_inited;

	// Transformationsmatrix zwischen Game und Falcon Device Workspace Koordinaten
	// NICHT �NDERN!
	double m_transformMat[16];

	// ServoOp
	double m_positionServo[3];	// Position im Koordinatensystem
	bool   m_buttonServo;		// Falcon Knopf gedr�ckt
	double m_forceServo[3];		// Force Feedback Motorenst�rken

	// Dimensionen des Falcon Device 3D Workspaces 
	double m_workspaceDims[6];

	HDLDeviceHandle m_deviceHandle;
	HDLServoOpExitCode m_servoOp;

	BlockedSphericalSector* blockedSectors[6];

	

private: 
	// Force in Newton im angegebenen Bereich (jeweil positiv wie negativ min/max)
	double getForceBetween(double force, double forceMax, double forceMin, int count);

	double inch = 39.3700787;



	bool rumbleDirection = false;
};