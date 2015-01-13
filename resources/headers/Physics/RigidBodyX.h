#ifndef RIGIDBODYX_H
#define RIGIDBODYX_H

/*****************************************

Rigidbody is the physical representation of a object.
It handles all impulses and forces affecting the object.

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

#include <vector>
#include <array>

#include <HVector.h>
#include <HMat.h>
#include <Placement.h>

#include "CLink.h"

namespace phyX
{
	class Collider;

	/*Rigidbody is the physical representation of the object.
	It handles all impulses and forces affecting the object.*/
	class RigidBodyX
	{
		friend class CPhysiX;
		friend detail::BALANCERESULT detail::CLink::Balance();

	public:
		RigidBodyX(Vektoria::CPlacement* ownerPlacement, Collider* collider, float mass, bool hasGravity = false);
		~RigidBodyX();

		//adds an impulse, the strength is reduces in every tick, fromStatic is true in case the impulse is given by a static object
		void AddImpulse(Vektoria::CHVector impulse, float strength, bool fromStatic = false);
		//adds a constant impulse, called force, if constant is true it is added every update else it gets deleted after one update
		void AddForce(Vektoria::CHVector force, float strength, bool constant = true);
		//get the collider of the ridigbody
		Collider* GetCollider();
		//returns the current velocity vector in global coordsystem
		Vektoria::CHVector GetVelocity_Global();
		//returns the current velocity vector in the object's local coordsystem
		Vektoria::CHVector GetVelocity_Local();

	private:

		float m_mass;
		Vektoria::CHVector m_velocityVec;
		Vektoria::CHVector m_currImpulse;
		Vektoria::CHVector m_currForce;
		const bool m_isStatic;
		Vektoria::CHMat m_mat;
		Vektoria::CHMat m_local;
		Collider* m_collider;
		Vektoria::CPlacement* m_ownerPlacement;

		std::vector<Vektoria::CHVector> m_force;
		std::vector<Vektoria::CHVector> m_impulses;

		std::array<bool, 6> m_staticDirs; //0 : x, 1 : -x, 2 : y, 3 : -y, 4 : z, 5: -z
		std::array<std::vector<detail::CLink>, 6> m_links;

		void Init();

		//the static directions get reseted and the chained rigibodies get disconnected
		void Reset();

		//creates a link between this an rigid with a vector that shows the perfect distance between this and rigid so that both colliders aren't intersectiong no longer
		void AddLink(Vektoria::CHVector& perfectDistance, Vektoria::CHVector& dir, RigidBodyX* rigid);

		//checks all links in the direction code for perfect distance
		void CorrectPosition(unsigned short direction);

		//moves the object to the right position and splits the collisions into corrections and impulses
		void SolveCollisions();

		//does all post collision events of the collider
		void PostRenderUpdate_first(float fTimeDelta);

		//in case of collision the object gets removed out of other colliders and collisionresponses get collected from the collider
		void PostRenderUpdate_second(float fTimeDelta);

		//converts the collision responses to links and impulses
		void ConvertResponses();

		//assigns static blocks in a direction to all links and link's of links in the linkdirektion
		void SetStatic(unsigned short linkdirektion, unsigned short staticDirection);
	};
}

#endif