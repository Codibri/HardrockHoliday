#include "Physics\SphereCollider.h"

/*****************************************

#SphereCollider.cpp

@(#)Author: Alexander Thoma

▄████▄  ▒█████  ▓█████▄ ▓█████ ▒██   ██▒
▒██▀ ▀█ ▒██▒  ██▒▒██▀ ██▌▓█   ▀ ▒▒ █ █ ▒░
▒▓█    ▄▒██░  ██▒░██   █▌▒███   ░░  █   ░
▒▓▓▄ ▄██▒██   ██░░▓█▄   ▌▒▓█  ▄  ░ █ █ ▒
▒ ▓███▀ ░ ████▓▒░░▒████▓ ░▒████▒▒██▒ ▒██▒
░ ░▒ ▒  ░ ▒░▒░▒░  ▒▒▓  ▒ ░░ ▒░ ░▒▒ ░ ░▓ ░
░  ▒    ░ ▒ ▒░  ░ ▒  ▒  ░ ░  ░░░   ░▒ ░
░       ░ ░ ░ ▒   ░ ░  ░    ░    ░    ░
░ ░         ░ ░     ░       ░  ░ ░    ░
░
*****************************************/


#include "Physics\Utilities.h"
#include "Physics\CPhysiX.h"

namespace phyX
{
	SphereCollider::SphereCollider(RigidBodyOwner* parent, float radius, float bounciness, bool isStatic, bool isTrigger) : Collider(parent, 1, bounciness, isStatic, isTrigger)
	{
		m_collisionRadius = radius;

		m_projectionLines = static_cast<Vektoria::CHVector*>(std::malloc(m_projectionLinesCount * sizeof(Vektoria::CHVector)));
	}

	SphereCollider::~SphereCollider()
	{
		free(m_projectionLines);
	}

	Vektoria::CHVector* SphereCollider::GetProjectionLines(Collider* otherCollider)
	{

		m_projectionLines[0] = Vektoria::CHVector(otherCollider->GetGlobalCenter() - GetGlobalCenter()).Normal();

		return m_projectionLines;
	}

	std::tuple<Vektoria::CHVector, Vektoria::CHVector, Vektoria::CHVector> SphereCollider::GetPointsOnLine(Vektoria::CHVector projectionline)
	{
		projectionline.MakeDirection();

		Vektoria::CHVector pCenter = phyX_utilties::ProjectVector(GetGlobalCenter(), projectionline);

		Vektoria::CHVector radVec = projectionline * m_collisionRadius;
		
		return std::make_tuple(pCenter - radVec, pCenter + radVec, pCenter);
	}

	RayHit SphereCollider::GetRayHit(Vektoria::CHVector& direction, Vektoria::CHVector& startPos, float Length)
	{

		Vektoria::CHVector movedCenter, pCenter, pCenterLot;

		struct RayHit hit;

		movedCenter = GetGlobalCenter() - startPos;
		pCenter = phyX_utilties::ProjectVector(movedCenter, direction);

		if ((movedCenter - pCenter).LengthSquare() <= (m_collisionRadius + detail::FLOATCOMPENSATION)*(m_collisionRadius + detail::FLOATCOMPENSATION))
		{

			Vektoria::CHVector hitpoint1, hitpoint2;

			if (movedCenter != pCenter)
			{
				float addVectorLength = std::sqrt(std::fabsf(m_collisionRadius * m_collisionRadius - (movedCenter - pCenter).LengthSquare()));
				Vektoria::CHVector addVector = direction.Normal() * addVectorLength;

				hitpoint1 = pCenter + addVector + startPos;
				hitpoint2 = pCenter - addVector + startPos;
				hitpoint1.MakePoint();
				hitpoint2.MakePoint();
			}
			else
			{
				Vektoria::CHVector addVector = direction.Normal() * m_collisionRadius;

				hitpoint1 = pCenter + addVector + startPos;
				hitpoint2 = pCenter - addVector + startPos;
				hitpoint1.MakePoint();
				hitpoint2.MakePoint();

			}

			if ((hitpoint1.Dist(startPos) > hitpoint2.Dist(startPos)) && (hitpoint2.Dist(startPos) < Length))
			{
				hit.m_hitCollider = this;
				hit.m_hitpoint = hitpoint2;
			}
			else if (hitpoint1.Dist(startPos) < Length)
			{
				hit.m_hitCollider = this;
				hit.m_hitpoint = hitpoint1;
			}


		}

		return hit;
	}
}