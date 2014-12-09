#ifndef CLINK_H
#define CLINK_H

/*****************************************

CLink is a link between two rigidbodies
It has distance and direction. This defines how far both
rigidbodies must be seperated from each other.

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

#include <HVector.h>

namespace phyX
{
	class RigidBodyX;

	namespace detail
	{
		enum BALANCERESULT
		{
			BR_SUCCESS,
			BR_SUCCESS_REVERT,
			BR_NONE,
			BR_NONE_REVERT,
			BR_FAIL
		};

		class CLink
		{
			public:
				CLink(RigidBodyX* origin, RigidBodyX* target, float linkDistance, Vektoria::CHVector linkDirection);
				~CLink();

				BALANCERESULT Balance();
				RigidBodyX* GetTarget();

			private:
				RigidBodyX* m_origin;
				RigidBodyX* m_target;
				float m_linkDistance;
				Vektoria::CHVector m_linkDirection;

				//throws an exception if the direction is a bad vector that can't be analysed
				unsigned short ConvertDir(Vektoria::CHVector& direction);
		};
	}

}
#endif