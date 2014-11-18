#pragma once
#include "Game\MapPart.h"
#include "Graphics\LochFalleVisual.h"
#include "Graphics\MapWallVisual.h"
class Level1Part2 :
	public MapPart
{
public:
	Level1Part2();
	~Level1Part2();

private:
	LochFalleVisual* mFalle1Ptr;
	LochFalleVisual* mFalle2Ptr;


	void loadMaterial();
	void initGameObjects();
};

