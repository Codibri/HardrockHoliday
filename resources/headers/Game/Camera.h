#pragma once

#include "root.h"

class Camera
{
public:
	Camera();
	~Camera();

	void initViewPort(float camAngle, Vektoria::CFrame* frame);

	void setPlayerPlacement(Vektoria::CPlacement* p);

	Vektoria::CViewport* getViewPort();

private:

	Vektoria::CViewport mViewPort;
	Vektoria::CCamera mVektoriaCamera;
	Vektoria::CPlacement mCamPlacement;

};

