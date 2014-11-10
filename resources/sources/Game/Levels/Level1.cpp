#include "Game\Levels\Level1.h"


Level1::Level1()
{
	addMapParts();
}


Level1::~Level1()
{
}


void Level1::initialize(Vektoria::CScene* scene){
	mLight1.Init(CHVector(1, 2, 1), CColor(255, 255, 255));
	scene->AddParallelLight(&mLight1);
}

void Level1::addMapParts(){
	this->addMapPart(mPart1.get());
	this->addMapPart(mPart2.get());
	this->addMapPart(mPart3.get());
}

