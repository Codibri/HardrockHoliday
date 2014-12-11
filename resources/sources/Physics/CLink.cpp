#include "Physics\CLink.h"

/*****************************************

#CLink.cpp

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

#include <exception>

#include "Physics\RigidBodyX.h"
#include "Physics\Collider.h"

namespace phyX
{
	namespace detail
	{
		CLink::CLink(RigidBodyX* origin, RigidBodyX* target, float linkDistance, Vektoria::CHVector linkDirection)
			: m_origin(origin), m_target(target), m_linkDistance(std::fabsf(linkDistance)), m_linkDirection(linkDirection)
		{

		}

		CLink::~CLink()
		{

		}

		RigidBodyX* CLink::GetTarget()
		{
			return m_target;
		}

		unsigned short CLink::ConvertDir(Vektoria::CHVector& direction)
		{

			if (direction.x < -1.00e-005f)
			{
				return 1;
			}
			else if (direction.x > 1.00e-005f)
			{
				return 0;
			}

			if (direction.y < -1.00e-005f)
			{
				return 3;
			}
			else if (direction.y > 1.00e-005f)
			{
				return 2;
			}

			if (direction.z < -1.00e-005f)
			{
				return 5;
			}
			else if (direction.z > 1.00e-005f)
			{
				return 4;
			}

			//shouln't arrive here
			throw(std::exception("CLink::ConvertDir: Bad direction"));
			return 10;
		}

		BALANCERESULT CLink::Balance()
		{
			Vektoria::CHVector distance, offset;
			offset.MakeDirection();

			try
			{

				if (m_target->m_staticDirs[ConvertDir(m_linkDirection)])
				{
					if (m_origin->m_staticDirs[ConvertDir(-m_linkDirection)])
						return BR_FAIL;

					distance = m_origin->GetCollider()->GetGlobalCenter() - m_target->GetCollider()->GetGlobalCenter();

					offset.x = ((m_linkDirection.x != 0.f) && (std::fabsf(distance.x) < m_linkDistance)) ? (m_linkDistance - std::fabsf(distance.x)) * -m_linkDirection.x : 0.f;
					offset.y = ((m_linkDirection.y != 0.f) && (std::fabsf(distance.y) < m_linkDistance)) ? (m_linkDistance - std::fabsf(distance.y)) * -m_linkDirection.y : 0.f;
					offset.z = ((m_linkDirection.z != 0.f) && (std::fabsf(distance.z) < m_linkDistance)) ? (m_linkDistance - std::fabsf(distance.z)) * -m_linkDirection.z : 0.f;

					if (offset.IsNull())
					{
						return BR_NONE_REVERT;
					}
					else
					{
						m_origin->m_mat.TranslateDelta(offset);
						return BR_SUCCESS_REVERT;
					}

				}
				else
				{
					distance = m_target->GetCollider()->GetGlobalCenter() - m_origin->GetCollider()->GetGlobalCenter();

					offset.x = ((m_linkDirection.x != 0.f) && (std::fabsf(distance.x) < m_linkDistance)) ? (m_linkDistance - std::fabsf(distance.x)) * m_linkDirection.x : 0.f;
					offset.y = ((m_linkDirection.y != 0.f) && (std::fabsf(distance.y) < m_linkDistance)) ? (m_linkDistance - std::fabsf(distance.y)) * m_linkDirection.y : 0.f;
					offset.z = ((m_linkDirection.z != 0.f) && (std::fabsf(distance.z) < m_linkDistance)) ? (m_linkDistance - std::fabsf(distance.z)) * m_linkDirection.z : 0.f;

					if (offset.IsNull())
					{
						return BR_NONE;
					}
					else
					{
						m_target->m_mat.TranslateDelta(offset);
						return BR_SUCCESS;
					}
				}
			}
			catch (std::exception& e)
			{
				std::cerr << "Exception: " << e.what() << std::endl;
				return BR_FAIL;
			}
		}
	}
}