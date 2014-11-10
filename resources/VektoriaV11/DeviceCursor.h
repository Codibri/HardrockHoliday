#pragma once
#include "windows.h"

namespace Vektoria
{

class CDeviceCursor
{
public:
	CDeviceCursor(void);
	~CDeviceCursor(void);

	bool GetAbsolute(int & ix, int & iy, bool bHideCursor = false); // Gibt die Zeigerpositionskoordinaten bez�glich der linken oberen Ecke des Frames aus, gibt true aus, wenn Cursor sich innerhalb des Frames befindet 
	bool GetFractional(float & frx, float & fry, bool bHideCursor = false); // Gibt die fraktionalen Zeigerpositionskoordinaten (Wertebereich jeweils 0..1) bez�glich des Frames aus, gibt true aus, wenn Cursor sich innerhalb des Frames befindet

	bool ButtonPressed(int iButton); // true, falls Taste iButton gedr�ckt wurde, ansonsten false

	bool ButtonPressedLeft(); // true, falls linke Maustaste gedr�ckt wird, ansonsten false
	bool ButtonPressedRight(); // true, falls rechte Maustaste gedr�ckt wird, ansonsten false
	bool ButtonPressedMid(); // true, falls mittlere Maustaste gedr�ckt wird, ansonsten false

	void Hide(); // Macht Cursor unsichtbar
	void Show(); // Macht Cursor sichtbar
	bool IsHidden(); // true, wenn Cursor unsichtbar, ansonsten false
	

	void SetFrame(HWND hwnd, int ixFrameSize, int iyFrameSize);
	HWND m_hwnd;
	int m_ixFrameSize;
	int m_iyFrameSize;
	bool m_bHidden;
};

}