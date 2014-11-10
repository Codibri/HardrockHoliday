#pragma once

#include "root.h"
#include "Game\GameObjects\Player.h"

using namespace Vektoria;

// TODO discuss how to integrate / rework this into the architecture


class PlayerVisual : public Player
{
public:
	PlayerVisual();
	PlayerVisual(Vektoria::CPlacement position);
	~PlayerVisual();

	void update(float deltaMillis, float time) override;

	void loadMaterial();
	void loadMesh();

private:

	CGeoSphere mPlayerMesh;
	CMaterial mPlayerMaterial;
};


