#pragma once
#include "Game\MapPart.h"
#include "Graphics\LochFalleVisual.h"
class Level1Part5 :
	public MapPart
{
public:
	Level1Part5();
	~Level1Part5();


private:
	LochFalleVisual* mFalle1Ptr;
	LochFalleVisual* mFalle2Ptr;


	void loadMaterial();
	void initGameObjects();
};

