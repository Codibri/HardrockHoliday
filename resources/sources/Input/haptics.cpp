#include "Input/haptics.h"


Haptics::Haptics() {
}


Haptics::~Haptics() {
}

/*void Haptics::init() {
	// Passing "DEFAULT" or 0 initializes the default device based on the
	// [DEFAULT] section of HDAL.INI.   The names of other sections of HDAL.INI
	// could be passed instead, allowing run-time control of different devices
	// or the same device with different parameters.  See HDAL.INI for details.
	m_deviceHandle = hdlInitNamedDevice("DEFAULT");
	if (m_deviceHandle == HDL_INVALID_HANDLE) {
		std::cout << "Could not open device, Device Failure" << std::endl;
	}
	// Now that the device is fully initialized, start the servo thread.
	hdlStart();

	// Set up callback function (for force feedback); set false for nonBlocking
	m_servoOp = hdlCreateServoOp(ContactCB, this, false);
	if (m_servoOp == HDL_INVALID_HANDLE) {
		std::cout << "Invalid servo op handle Device Failure" << std::endl;
	}

	// Make the device current.  All subsequent calls will
	hdlMakeCurrent(m_deviceHandle);

	// Get the extents of the device workspace.
	// Used to create the mapping between device and application coordinates.
	// Returned dimensions in the array are minx, miny, minz, maxx, maxy, maxz
	//                                      left, bottom, far, right, top, near)
	// Right-handed coordinates:
	//   left-right is the x-axis, right is greater than left
	//   bottom-top is the y-axis, top is greater than bottom
	//   near-far is the z-axis, near is greater than far
	// workspace center is (0,0,0)
	hdlDeviceWorkspace(m_workspaceDims);

	// Establish the transformation from device space to app space
	// To keep things simple, we will define the app space units as
	// inches, and set the workspace to approximate the physical
	// workspace of the Falcon.  That is, a 4" cube centered on the
	// origin.  Note the Z axis values; this has the effect of
	// moving the origin of world coordinates toward the base of the
	// unit.
	double gameWorkspace[] = { -2, -2, -2, 2, 2, 3 };
	bool useUniformScale = true;
	hdluGenerateHapticToAppWorkspaceTransform(
		m_workspaceDims,
		gameWorkspace,
		useUniformScale,
		m_transformMat);

	m_inited = true;

	double position[3] = {0.0, 0.0, 0.0};
	hdlSetToolForce(position);
	//hdlToolPosition

}



// uninit() undoes the setup in reverse order.  Note the setting of
// handles.  This prevents a problem if uninit() is called
// more than once.
void Haptics::uninit() {
	if (m_servoOp != HDL_INVALID_HANDLE) 	{
		hdlDestroyServoOp(m_servoOp);
		m_servoOp = HDL_INVALID_HANDLE;
	}

	//stop servo thread
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


HDLServoOpExitCode ContactCB(void* pUserData) {
	Haptics* haptics = static_cast< Haptics* >(pUserData);
	// Get current state of haptic device
	hdlToolPosition(haptics->m_positionServo);
	hdlToolButton(&(haptics->m_buttonServo));

	// TODO: hdlGetState();
	// TODO: hdlGetError();

	// Call the function that does the heavy duty calculations.  ->WallContact(); ??
	//haptics->cubeContact();
	//TODO:  WIeder rein

	// Send forces to device
	hdlSetToolForce(haptics->m_forceServo);

	// Make sure to continue processing
	return HDL_SERVOOP_CONTINUE;
}*/