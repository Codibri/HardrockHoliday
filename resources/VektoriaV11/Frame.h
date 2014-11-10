#pragma once
#include "Viewports.h"
#include "RenderApi.h"
#include "Device.h"
#include "DeviceKeyboard.h"
#include "DeviceMouse.h"
#include "DeviceGameController.h"
#include "DeviceCursor.h"

#include "DistributedGlobal.h"



//------------------------------------
// CFrame
//
// Autor    : Prof. Dr. Tobias Breiner
// Ort      : Pfungstadt, 11.10.2011
// Copyright: Moyzelle Vektoria
//------------------------------------

namespace Vektoria
{

enum EInputApi
{
	eInputApi_Null,
	eInputApi_DirectInput
};


class CRoot;

class CFrame
{
	friend class CRoot;
	friend class CFrames;
private:
	void Tick(float & fTimeDelta);

public:
	CFrame();
	~CFrame();
	CFrame operator=(CFrame frame);
	void Copy(CFrame frame);

//	CRenderApi * Init(HWND hwnd,  int iWidthWindow, int iHeightWindow, ERenderApi renderapi = eRenderApi_DirectX11_Shadermodel50, EInputApi inputapi = eInputApi_DirectInput);
	CRenderApi * Init(HWND hwnd,  ERenderApi renderapi = eRenderApi_DirectX11_Shadermodel50, EInputApi inputapi = eInputApi_DirectInput); // ab V11
	void Fini();


	void AddViewport(CViewport * pviewport);
	void AddDeviceKeyboard(CDeviceKeyboard * pdevicekeyboard);
	void AddDeviceMouse(CDeviceMouse * pdevicemouse);
	void AddDeviceGameController(CDeviceGameController * pdevicegamecontroller);
	void AddDeviceCursor(CDeviceCursor * pdevicecursor);

	void ReSize(int iWidthWindow, int iHeightWindow);

	CViewports m_viewports;
	CRenderApi * m_prenderapi;
	CDevice * m_pdevice;
	int m_iWidthWindow;
	int m_iHeightWindow;
	HWND m_hwnd;
	ERenderApi m_eRenderApi;
	EInputApi m_eInputApi;


	CDeviceCursor * m_pdevicecursor;
#ifdef NETWORKMASTER
	unsigned int GetidId();

private:

	unsigned int m_idId;
	int m_icId;
#endif
private:
	void SetRoot(CRoot * proot);
	CRoot * m_proot;
};

}