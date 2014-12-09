#ifndef RIGIDBODYOWNER_H
#define RIGIDBODYOWNER_H

/*****************************************

If you want to insert your object into the physics module,
you must inherit your object from RigidBodyOwner.
This is the interface for your object's physical image.

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

#include <Placement.h>
#include "RigidBodyX.h"

namespace phyX
{
	class RigidBodyOwner
	{
	public:
		/**
		* RigidBodyOwner Constructor for your physical interface
		* @param ownerPlacement : placement of the object(be aware the physics calculations get done with the matrix of this placement)
		* @param collider : create the type of collider you need for your object
		* @param mass : the mass of your object
		* @param hasGravity : if true the objects gets constant gravityforce
		*/
		RigidBodyOwner(Vektoria::CPlacement* ownerPlacement, Collider* collider, float mass, bool hasGravity);

		virtual ~RigidBodyOwner();

		//returns the rigidbody
		RigidBodyX* GetRigidBody();

	private:
		RigidBodyX* m_rigidBody;
	};
}

#endif