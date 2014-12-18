#pragma once

#include "root.h"
#include "Graphics\Visual.h"
#include <memory>
using namespace Vektoria;

// TODO discuss how to integrate / rework this into the architecture


class PlayerVisual : public Visual
{
public:
	PlayerVisual(Vektoria::CPlacement* rotationPlacement, CPlacement* posPlacement);
	~PlayerVisual();

	void update(float deltaMillis, float time) override;

	void loadMaterial();
	void loadMesh();

private:

	CGeoSphere mPlayerMesh;
	CGeo* mObjPlayerMesh;
	CMaterial mPlayerMaterial;
};


