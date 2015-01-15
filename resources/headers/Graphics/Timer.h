#pragma once

#include "root.h"

/*
	Timer zum Anzeigen der benötigten Zeit im Level
*/

class Timer {

public:

	Timer();
	~Timer();

	void AddToViewPort(Vektoria::CViewport* vp);

	void Update(float fTimeDelta, float fTime);

	void Start();
	void Stop();
	void Reset();

	void Show();
	void Hide();

	int GetMinutes();
	int GetSeconds();
	int GetMilliSeconds();

private:

	void InitWriting();
	void UpdateDuration(float fTimeDelta);

	Vektoria::CWriting mWriting;
	Vektoria::CWritingFont mWritingFont;
	int mMinutes, mSeconds, mMilliSeconds;
	float mTotalTime;
	bool mIsRunning;
};