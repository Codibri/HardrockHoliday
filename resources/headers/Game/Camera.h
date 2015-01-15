#pragma once

#include "root.h"
#include "GameObjects\Player.h"

class Camera
{
public:
	Camera();
	~Camera();

	void initViewPort(float camAngle, Vektoria::CFrame* frame);

	void setPlayerPlacement(Player* p);

	Vektoria::CViewport* getViewPort();

private:

	Vektoria::CViewport mViewPort;
	Vektoria::CCamera mVektoriaCamera;
	Vektoria::CPlacement mCamPlacement;

};

