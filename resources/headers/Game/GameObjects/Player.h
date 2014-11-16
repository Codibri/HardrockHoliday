#pragma once
#include "root.h"
#include "Game\PhysicalGameObject.h"



// Logik für Spieler ( Kugel )

// Muss GameObject erweitern
class Player : public PhysicalGameObject
{
public:
	Player();
	Player(Vektoria::CPlacement position);
	~Player();

	virtual void update(float deltaMillis, float time) override;

private:


protected:
	// Nur für Rotation der Spieler Kugel
	Vektoria::CPlacement _rotationPlacement;

};

