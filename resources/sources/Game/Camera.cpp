#include "Game\Camera.h"
#include "Engine\Engine.h"

Camera::Camera()
{
	mCamPlacement.AddCamera(&mVektoriaCamera);

	// Kameraabstand zur Spieler-Kugel
	mCamPlacement.TranslateY(0.35);
	mCamPlacement.TranslateZDelta(0.8);

}


Camera::~Camera()
{
}


void Camera::initViewPort(float camAngle, Vektoria::CFrame* frame){
	mVektoriaCamera.Init(camAngle);
	mViewPort.InitFull(&mVektoriaCamera);
	frame->AddViewport(&mViewPort);

	ENGINE->globalResources.vektoriaCoreElements.viewport = &mViewPort; //hack access to viewport  :D  don't kill me please
}



void Camera::setPlayerPlacement(Vektoria::CPlacement* p){
	// Player placement wird in der Player klasse ge�ndert um
	// die Kugel und die Kamera zu bewegen. -> Kamera als child
	// des Player placements anh�ngen
	p->AddPlacement(&mCamPlacement);
}

Vektoria::CViewport* Camera::getViewPort(){
	return &mViewPort;
}