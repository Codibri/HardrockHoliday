#pragma once

#include "root.h"

class Camera
{
public:
	Camera();
	~Camera();

	void initViewPort(float camAngle, Vektoria::CViewport* viewport);

	void setPlayerPlacement(Vektoria::CPlacement* p);

private:



	Vektoria::CCamera mVektoriaCamera;
	Vektoria::CPlacement mCamPlacement;

};

