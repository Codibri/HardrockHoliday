#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

/****************************************

Collidertype Box



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
****************************************/

#include <array>
#include "Collider.h"


namespace phyX
{
	class BoxCollider : public Collider
	{
		public:
			/**
			* BoxCollider, a collider type represented by a box
			* @param parent : pointer to the object
			* @param size : boxsize x-,y-,z-direction (e.g. 2,2,2 gives you a box of size 4,4,4)
			* @param bounciness : the factor other objects bounce against this object
			* @param isStatic : set to true if the object doesn't move and can't moved
			* @param isTrigger : if true, collisions get ignored but the collision events get triggered
			*/
			BoxCollider(RigidBodyOwner* parent, Vektoria::CHVector size, float bounciness, bool isStatic = false, bool isTrigger = false);
			~BoxCollider();

		protected:
			//returns projection lines for collision calculation, be sure to delete the result when no longer needed
			Vektoria::CHVector* GetProjectionLines(Collider* otherCollider);

			//returns the outer points on a projection line, delete the result if no longer needed
			std::tuple<Vektoria::CHVector, Vektoria::CHVector, Vektoria::CHVector> GetPointsOnLine(Vektoria::CHVector projectionline);
			
			//returns the hitpoint of the collider with the given ray, if the collider of this rayhit is null there is no intersection
			RayHit GetRayHit(Vektoria::CHVector& direction, Vektoria::CHVector& startPos, float Length);

		private:

			std::array<Vektoria::CHVector, 8> m_corners;		//corners of the bounding box
			std::array<Vektoria::CHVector, 6> m_normals;		//normals of the box
			const std::array<int, 24> m_cornerIndex;				//index of corners for all sides ( -x, x, -y, y, -z, z)
	};
}

#endif