#pragma once
#include "Game\MapPart.h"
#include "Graphics\LochFalleVisual.h"
#include "root.h"

class Level1Part1 : public MapPart
{
public:
	Level1Part1();
	~Level1Part1();

private:
	
	// Um das löschen der GameObjects kümmert sich der 
	// zuständige MapPart
	LochFalleVisual* mFalle1Ptr;
	LochFalleVisual* mFalle2Ptr;


	void loadMaterial();
	void initGameObjects();
};

