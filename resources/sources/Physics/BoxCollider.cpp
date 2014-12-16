#include "Physics\BoxCollider.h"

/*****************************************

#BoxCollider.cpp

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
#include <algorithm>

namespace phyX
{

	BoxCollider::BoxCollider(RigidBodyOwner* parent, Vektoria::CHVector size, float bounciness, bool isStatic, bool isTrigger) : Collider(parent, 3, bounciness, isStatic, isTrigger),
		m_cornerIndex({ { 4, 0, 3, 7, 1, 5, 6, 2, 5, 4, 0, 1, 3, 2, 6, 7, 5, 4, 7, 6, 0, 1, 2, 3 } })
	{
		size *= 0.5f
		m_collisionRadius = size.Length();

		m_corners[0] = Vektoria::CHVector(-size.x, -size.y, -size.z, 0.0f);
		m_corners[1] = Vektoria::CHVector(size.x, -size.y, -size.z, 0.0f);
		m_corners[2] = Vektoria::CHVector(size.x, size.y, -size.z, 0.0f);
		m_corners[3] = Vektoria::CHVector(-size.x, size.y, -size.z, 0.0f);
		m_corners[4] = Vektoria::CHVector(-size.x, -size.y, size.z, 0.0f);
		m_corners[5] = Vektoria::CHVector(size.x, -size.y, size.z, 0.0f);
		m_corners[6] = Vektoria::CHVector(size.x, size.y, size.z, 0.0f);
		m_corners[7] = Vektoria::CHVector(-size.x, size.y, size.z, 0.0f);

		m_normals[0] = Vektoria::CHVector(-1.f, 0.0f, 0.0f, .0f);
		m_normals[1] = Vektoria::CHVector(1.f, 0.0f, 0.0f, .0f);
		m_normals[2] = Vektoria::CHVector(0.f, -1.0f, 0.0f, .0f);
		m_normals[3] = Vektoria::CHVector(0.f, 1.0f, 0.0f, .0f);
		m_normals[4] = Vektoria::CHVector(0.f, 0.0f, -1.0f, .0f);
		m_normals[5] = Vektoria::CHVector(0.f, 0.0f, 1.0f, .0f);

		m_projectionLines = static_cast<Vektoria::CHVector*>(std::malloc(m_projectionLinesCount * sizeof(Vektoria::CHVector)));
	}

	BoxCollider::~BoxCollider()
	{
		free(m_projectionLines);
	}

	Vektoria::CHVector* BoxCollider::GetProjectionLines(Collider* otherCollider)
	{
		if (!m_updateProjectionLines)
		{
			m_projectionLines[0] = Vektoria::CHVector(*m_mat * m_normals[0]).Normal();
			m_projectionLines[1] = Vektoria::CHVector(*m_mat * m_normals[2]).Normal();
			m_projectionLines[2] = Vektoria::CHVector(*m_mat * m_normals[4]).Normal();
			m_updateProjectionLines.store(true);
		}

		return m_projectionLines;
	}

	std::tuple<Vektoria::CHVector, Vektoria::CHVector, Vektoria::CHVector> BoxCollider::GetPointsOnLine(Vektoria::CHVector projectionline)
	{
		projectionline.MakeDirection();

		Vektoria::CHVector pCenter;
		std::array<Vektoria::CHVector, 8> pCorners;
			
		pCenter = phyX_utilties::ProjectVector(GetGlobalCenter(), projectionline);
		
		std::transform(m_corners.begin(), m_corners.end(), pCorners.begin(), [&](Vektoria::CHVector& corner) ->Vektoria::CHVector { return phyX_utilties::ProjectVector(*m_mat * corner, projectionline);});

		//sort the projected points to get the point with max distance
		float Length = std::max_element(pCorners.begin(), pCorners.end(), 
			[&](Vektoria::CHVector v1, Vektoria::CHVector v2) -> bool { 
			return ((Vektoria::CHVector)pCenter - v1).LengthSquare() < ((Vektoria::CHVector)pCenter - v2).LengthSquare(); 
			})->Length();
					
		return std::make_tuple(pCenter - projectionline * Length, pCenter + projectionline * Length, pCenter);
	}

	RayHit BoxCollider::GetRayHit(Vektoria::CHVector& direction, Vektoria::CHVector& startPos, float Length)
	{
		Vektoria::CHVector movedCenter;
		Vektoria::CHVector pCenter;

		struct RayHit hit;

		movedCenter = GetGlobalCenter() - startPos;
		pCenter = phyX_utilties::ProjectVector(movedCenter, direction);

		if ((movedCenter - pCenter).LengthSquare() <= (m_collisionRadius + detail::FLOATCOMPENSATION)*(m_collisionRadius + detail::FLOATCOMPENSATION))
		{
			
			Vektoria::CHVector normal, hitpoint;
			
			std::array<Vektoria::CHVector, 24> sidecorners;
			std::vector<Vektoria::CHVector> hitpoints;

			for (unsigned int i = 0; i < 24; ++i)
				sidecorners[i] = GetGlobalCenter() + *m_mat * m_corners[m_cornerIndex[i]];  //calculate the sidepoints of the box in global coords

			for (unsigned int i = 0; i < 6; ++i)  //check all normals with all sides of the box for intersection point
			{
				
				normal = *m_mat * m_normals[i];	//calc global normal

				if (normal * direction == 0)	//ray is parallel to the side of the box
					continue;
				
				float distanceHitPoint = (normal * (sidecorners[4 * i] - startPos)) / (normal * direction);

				hitpoint = direction.Normal() * distanceHitPoint + startPos;

				if (distanceHitPoint > Length)	//hitpoint is out of raysize
					continue;
				

				//check if hitpoint is outside boxside then continue to next side
				if (((hitpoint.x > sidecorners[i * 4 + 1].x) && (hitpoint.x > sidecorners[i * 4 + 3].x)) ||    
					((hitpoint.x < sidecorners[i * 4 + 1].x) && (hitpoint.x < sidecorners[i * 4 + 3].x)))
					continue;

				if (((hitpoint.y > sidecorners[i * 4 + 1].y) && (hitpoint.y > sidecorners[i * 4 + 3].y)) ||
					((hitpoint.y < sidecorners[i * 4 + 1].y) && (hitpoint.y < sidecorners[i * 4 + 3].y)))
					continue;

				if (((hitpoint.z > sidecorners[i * 4 + 1].z) && (hitpoint.z > sidecorners[i * 4 + 3].z)) ||
					((hitpoint.z < sidecorners[i * 4 + 1].z) && (hitpoint.z < sidecorners[i * 4 + 3].z)))
					continue;

				hitpoints.push_back(hitpoint);
				
			}

			if (hitpoints.size() > 0)
			{
				//sort the hit points to get the point with min distance at the beginning of the array
				std::sort(hitpoints.begin(), hitpoints.end(), [&](Vektoria::CHVector v1, Vektoria::CHVector v2) -> bool {
					return ((Vektoria::CHVector)startPos - v1).LengthSquare() < ((Vektoria::CHVector)startPos - v2).LengthSquare();
				});

				hit.m_hitCollider = this;
				hit.m_hitpoint = hitpoints.at(0);
			}
		}

		return hit;
	}
}