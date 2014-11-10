#pragma once

#include "OVR.h"

#include "Quaternion.h"
#include "HVector.h"
#include "HMat.h"
#include "DeviceCursor.h"
#include "DeviceMouse.h"
#include "DeviceKeyboard.h"
#include "DeviceGameController.h"
#include "Scene.h"
#include "Frame.h"

#define MOVESPEED 4.f 
#define LOOKSPEED 2.f

namespace Vektoria
{
	class CDeviceOculusRift
	{
	public:
		CDeviceOculusRift();
		~CDeviceOculusRift();

		CQuaternion GetOrientation() const;
		CHVector GetAcceleration() const;
		CHVector GetAngulatVelocity() const;
		
		void Init(CFrame& zf, CScene& zs);
		// Initialisiere Rift mit 2 Kameras und der Szene
		void Init(CCamera& zc1, CCamera& zc2, CScene& zs);
		// Initialisiere Rift mit Maus/Tastatursteuerung
		void Init(CCamera& zc1, CCamera& zc2, CScene& zs, CDeviceMouse& zdm,
						CDeviceCursor& zdc, CDeviceKeyboard& zdk);
		void Tick(float fTimeDelta);
		void Fini();

	private:

		void MouseLook(float fRelativeX, float ReletiveY);

		OVR::DeviceManager* m_pManager;
		OVR::HMDDevice* m_pHMD;
		OVR::SensorDevice* m_pSensor;
		OVR::SensorFusion* m_sensorFusion;
		CPlacement m_zpCamera1;
		CPlacement m_zpCamera2;
		CPlacement m_zpMove;
		CPlacement m_zpRot;
		CCamera* m_pzc1;
		CCamera* m_pzc2;
		CQuaternion m_qOrientation;
		OVR::Vector3f m_vEyePos;
		OVR::Util::Render::StereoConfig m_sConfig;
		float m_fEyeYaw;
		float m_fEyePitch;
		float m_fEyeRoll;
		float m_fYawDelta;

		CDeviceMouse* m_pzdm;
		CDeviceKeyboard* m_pzdk;
		CDeviceCursor* m_pzdc;
		CDeviceGameController* m_pzdg;

		CViewport m_zv1;
		CViewport m_zv2;
		CCamera m_zc1;
		CCamera m_zc2;

		CDeviceMouse m_zdm;
		CDeviceKeyboard m_zdk;
		CDeviceCursor m_zdc;
		CDeviceGameController m_zdg;

	};
}


