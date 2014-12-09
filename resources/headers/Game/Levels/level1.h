#pragma once

#include <memory>

#include "Game\Levels\Level1part1.h"
#include "Game\Levels\Level1Part2.h"
#include "Game\Levels\Level1Part3.h"
#include "Game\Levels\Level1Part4.h"
#include "Game\Levels\Level1Part5.h"
#include "..\Level.h"

class Level1 : public Level
{
public:
	Level1();
	~Level1();

	void initialize(Vektoria::CScene* scene) override;


private:
	std::unique_ptr<Level1Part1> mPart1{ new Level1Part1() };
	std::unique_ptr<Level1Part2> mPart2{ new Level1Part2() };
	std::unique_ptr<Level1Part3> mPart3{ new Level1Part3() };
	std::unique_ptr<Level1Part4> mPart4{ new Level1Part4() };
	std::unique_ptr<Level1Part5> mPart5{ new Level1Part5() };
	

	CParallelLight mLight1;
	std::unique_ptr<CGeo> mSkyDome;
	CPlacement mSkyPlacement;
	CMaterial mSkyMaterial;


	void addMapParts();
	void loadSkyBox(Vektoria::CScene* scene);
};

