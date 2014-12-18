#pragma once

#include <hdl/hdl.h>
#include <hdlu/hdlu.h>
#include <iostream>



class Haptics {
	friend HDLServoOpExitCode ContactCB(void *data);
	friend HDLServoOpExitCode GetStateCB(void *data);

public:

	Haptics();
	~Haptics();


	// Initialize
	void init();

	// Clean up
	void uninit();

	// Get position
	void getPosition(double pos[3]);

	// Nothing happens until initialization is done
	bool m_inited;

	// Transformation from Device coordinates to Application coordinates
	double m_transformMat[16];

	// Variables used only by servo thread
	double m_positionServo[3];	//position vector
	bool   m_buttonServo;		//buttton pressed
	double m_forceServo[3];		//force back to servo

	// Device workspace dimensions: left, bottom, far, right, top, near,  workspace center is (0,0,0) 
	double m_workspaceDims[6];	

	HDLDeviceHandle m_deviceHandle;
	HDLServoOpExitCode m_servoOp;

};