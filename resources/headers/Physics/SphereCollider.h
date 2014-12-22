#ifndef SPHERECOLLIDER_H
#define SPHERECOLLIDER_H

/****************************************

Collidertype Sphere



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

#include "Collider.h"

namespace phyX
{

	class SphereCollider : public Collider
	{
	public:
		/**
		* SphereCollider, a collider type represented by a sphere
		* @param parent : pointer to the object
		* @param radius : radius of the sphere
		* @param bounciness : the factor other objects bounce against this object
		* @param isStatic : set to true if the object doesn't move and can't moved
		* @param isTrigger : if true, collisions get ignored but the collision events get triggered
		*/
		SphereCollider(RigidBodyOwner* parent, float radius, float bounciness, bool isStatic = false, bool isTrigger = false);
		~SphereCollider();

	protected:
		//returns projection lines for collision calculation, be sure to delete the result when no longer needed
		Vektoria::CHVector* GetProjectionLines(Collider* otherCollider);

		//returns the outer points on a projection line, delete the result if no longer needed
		std::tuple<Vektoria::CHVector, Vektoria::CHVector, Vektoria::CHVector> GetPointsOnLine(Vektoria::CHVector projectionline);
		
		//returns the hitpoint of the collider with the given ray, if the collider of this rayhit is null there is no intersection
		RayHit GetRayHit(Vektoria::CHVector& direction, Vektoria::CHVector& startPos, float Length);

	};

}

#endif