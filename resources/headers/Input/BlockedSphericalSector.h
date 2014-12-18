// Mareike

#pragma once
class BlockedSphericalSector {

public:
	BlockedSphericalSector();
	BlockedSphericalSector(int direction, float startPoint, float blockStrength, float blockStrengthIncrease, bool rumbleOnCollide);
	~BlockedSphericalSector();

	float crossedBorder(double position);

//private:
	int m_direction;
	float m_startPoint;
	float m_blockStrength;
	float m_blockStrengthIncrease;
	bool m_rumbleOnCollide;
};

