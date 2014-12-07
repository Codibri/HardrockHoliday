#include "Game\Camera.h"


Camera::Camera()
{
	mCamPlacement.AddCamera(&mVektoriaCamera);

	mCamPlacement.TranslateY(0.45);
	mCamPlacement.TranslateZDelta(1.1);

}


Camera::~Camera()
{
}


void Camera::initViewPort(float camAngle, Vektoria::CViewport* viewport){
	mVektoriaCamera.Init(camAngle);
	viewport->InitFull(&mVektoriaCamera);
}



void Camera::setPlayerPlacement(Vektoria::CPlacement* p){
	// Player placement wird in der Player klasse geändert um
	// die Kugel und die Kamera zu bewegen. -> Kamera als child
	// des Player placements anhängen
	p->AddPlacement(&mCamPlacement);
}