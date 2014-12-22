#include "Physics\RigidBodyOwner.h"

/*****************************************

#RigidBodyOwner.cpp

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

#include "Physics\CPhysiX.h"

namespace phyX
{
	RigidBodyOwner::RigidBodyOwner(Vektoria::CPlacement* ownerPlacement, Collider* collider, float mass, bool hasGravity)
		: m_rigidBody(new RigidBodyX(ownerPlacement, collider, mass, hasGravity))
	{

	}

	RigidBodyOwner::~RigidBodyOwner()
	{
		delete m_rigidBody;
	}

	RigidBodyX* RigidBodyOwner::GetRigidBody()
	{
		return m_rigidBody;
	}
}