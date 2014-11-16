#pragma once
#include "Game\MapPart.h"
#include "Graphics\LochFalleVisual.h"
class Level1Part4 :
	public MapPart
{
public:
	Level1Part4();
	~Level1Part4();

private:
	LochFalleVisual* mFalle1Ptr;
	LochFalleVisual* mFalle2Ptr;


	void loadMaterial();
	void initGameObjects();
};

