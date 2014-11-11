#pragma once
#include "Game\MapPart.h"
#include "Graphics\LochFalleVisual.h"
class Level1Part3 :
	public MapPart
{
public:
	Level1Part3();
	~Level1Part3();

private:
	LochFalleVisual* mFalle1Ptr;
	LochFalleVisual* mFalle2Ptr;


	void loadMaterial();
	void initGameObjects();
};

