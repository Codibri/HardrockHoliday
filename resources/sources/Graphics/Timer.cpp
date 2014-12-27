#include "Graphics\Timer.h"

Timer::Timer(){
	Reset();
	mIsRunning = false;
	InitWriting();
}

Timer::~Timer(){

}

void Timer::AddToViewPort(Vektoria::CViewport* vp){
	vp->AddWriting(&mWriting);
}

void Timer::Update(float fTimeDelta, float fTime){
	if (!mIsRunning)
		return;
	UpdateDuration(fTime);
	mWriting.PrintF("Time: %d : %d : %d", mMinutes, mSeconds, mMilliSeconds);
}

void Timer::Start(){
	mIsRunning = true;
}

void Timer::Stop(){
	mIsRunning = false;
}

void Timer::Reset(){
	mMinutes = 0;
	mSeconds = 0;
	mMilliSeconds = 0;
}

void Timer::Show(){
	mWriting.SwitchOn();
}

void Timer::Hide(){
	mWriting.SwitchOff();
}

int Timer::GetMinutes(){
	return mMinutes;
}

int Timer::GetSeconds(){
	return mSeconds;
}

int Timer::GetMilliSeconds(){
	return mMilliSeconds;
}

void Timer::InitWriting(){

	mWritingFont.Init("GameResources\\Textures\\font.png", true);
	mWritingFont.SetTableSize(16, 16);
	mWritingFont.SetTableStartASCII(0);
	mWriting.Init(Vektoria::CFloatRect(0.425, 0.05, 0.15, 0.03), 20, &mWritingFont);
	mWriting.PrintF("Time: %d:%d:%d", 0, 0, 0);

}

void Timer::UpdateDuration(float fTime){
	mSeconds = (int)fTime;
	mMinutes = mSeconds / 60;
	mMilliSeconds = (int)((fTime - (float)mSeconds) * 1000.0);
}