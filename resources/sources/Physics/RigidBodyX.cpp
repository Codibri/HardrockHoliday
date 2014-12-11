#include "Physics\RigidBodyX.h"

/*****************************************

#RigidBodyX.cpp

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

#include <iostream>
#include "Physics\CPhysiX.h"
#include "Physics\RigidBodyOwner.h"
#include <algorithm>

#include "Physics\Utilities.h"

namespace phyX
{

	RigidBodyX::RigidBodyX(Vektoria::CPlacement* ownerPlacement, Collider* collider, float mass, bool hasGravity)
		: m_ownerPlacement(ownerPlacement),m_collider(collider), m_mass(mass), 
		  m_isStatic(collider->IsStatic()), m_staticDirs({ { m_isStatic, m_isStatic, m_isStatic, m_isStatic, m_isStatic, m_isStatic } })
	{
		CPhysiX::GetInstance()->AddRigidBody(this);

		if (hasGravity && !m_collider->IsStatic())
			AddForce(Vektoria::CHVector(0.f, -1.f, 0.f), 30.f);

	}

	RigidBodyX::~RigidBodyX()
	{
		CPhysiX::GetInstance()->RemoveRigidBody(this);
		delete m_collider;
		m_force.clear();
		m_impulse.clear();
	}

	Collider* RigidBodyX::GetCollider()
	{
		return m_collider;
	}

	void RigidBodyX::Reset()
	{
		m_staticDirs.assign(m_isStatic);
		std::for_each(m_links.begin(), m_links.end(), [](std::vector<detail::CLink>& links){ links.clear(); });
	}

	void RigidBodyX::AddForce(Vektoria::CHVector force, float strength, bool constant)
	{
		m_force.push_back(std::make_pair(force.Normal() * strength, constant));
	}

	void RigidBodyX::AddImpulse(Vektoria::CHVector impulse, float strength, bool fromStatic)
	{
		m_staticDirs[1] = (impulse.x > detail::FLOATCOMPENSATION) && fromStatic;
		m_staticDirs[0] = (impulse.x < -detail::FLOATCOMPENSATION) && fromStatic;
		m_staticDirs[3] = (impulse.y > detail::FLOATCOMPENSATION) && fromStatic;
		m_staticDirs[2] = (impulse.y < -detail::FLOATCOMPENSATION) && fromStatic;
		m_staticDirs[5] = (impulse.z > detail::FLOATCOMPENSATION) && fromStatic;
		m_staticDirs[4] = (impulse.z < -detail::FLOATCOMPENSATION) && fromStatic;
		
		m_impulse.push_back(std::make_pair(impulse.Normal(), strength));
	}

	void RigidBodyX::AddLink(Vektoria::CHVector& perfectDistance, Vektoria::CHVector& dir, RigidBodyX* rigid)
	{
		if (dir.x < -detail::FLOATCOMPENSATION)
		{
			m_links[1].push_back(detail::CLink(this, rigid, perfectDistance.x, Vektoria::CHVector(-1.f, 0.f, 0.f)));

			if (rigid->m_staticDirs[1])
				m_staticDirs[1] = true;
		}
		else if (dir.x > detail::FLOATCOMPENSATION)
		{
			m_links[0].push_back(detail::CLink(this, rigid, perfectDistance.x, Vektoria::CHVector(1.f, 0.f, 0.f)));

			if (rigid->m_staticDirs[0])
				m_staticDirs[0] = true;
		}

		if (dir.y < -detail::FLOATCOMPENSATION)
		{
			m_links[3].push_back(detail::CLink(this, rigid, perfectDistance.y, Vektoria::CHVector(0.f, -1.f, 0.f)));

			if (rigid->m_staticDirs[3])
				m_staticDirs[3] = true;
		}
		else if (dir.y > detail::FLOATCOMPENSATION)
		{
			m_links[2].push_back(detail::CLink(this, rigid, perfectDistance.y, Vektoria::CHVector(0.f, 1.f, 0.f)));

			if (rigid->m_staticDirs[2])
				m_staticDirs[2] = true;
		}

		if (dir.z < -detail::FLOATCOMPENSATION)
		{
			m_links[5].push_back(detail::CLink(this, rigid, perfectDistance.z, Vektoria::CHVector(0.f, 0.f, -1.f)));

			if (rigid->m_staticDirs[5])
				m_staticDirs[5] = true;
		}
		else if (dir.z > detail::FLOATCOMPENSATION)
		{
			m_links[4].push_back(detail::CLink(this, rigid, perfectDistance.z, Vektoria::CHVector(0.f, 0.f, 1.f)));

			if (rigid->m_staticDirs[4])
				m_staticDirs[4] = true;
		}
	}

	void RigidBodyX::Init()
	{
		m_mat = Vektoria::CHMat();
		m_collider->InitGhost(m_mat);
	}

	void RigidBodyX::PostRenderUpdate_first(float fTimeDelta)
	{

		m_mat = m_ownerPlacement->m_amGlobal[0];

		if (!m_isStatic)
		{
			Vektoria::CHVector deflection;

			for (int i = m_force.size() - 1; i >= 0; --i)
			{
				deflection += m_force.at(i).first;

				if (!m_force.at(i).second)
					m_force.erase(m_force.begin() + i);
			}

			for (int i = m_impulse.size() - 1; i >= 0; --i)
			{
				deflection += m_impulse.at(i).first * m_impulse.at(i).second;

				if ((m_impulse.at(i).second -= fTimeDelta) <= 0.f)
					m_impulse.erase(m_impulse.begin() + i);
			}

			deflection *= fTimeDelta;

			//add random magic vector
			deflection.x = (((deflection.x < 0.f) && m_staticDirs[1]) || ((deflection.x > 0.f) && m_staticDirs[0])) ? 0.f : deflection.x + (rand() % 21 - 10) * 1.0e-008f;
			deflection.y = (((deflection.y < 0.f) && m_staticDirs[3]) || ((deflection.y > 0.f) && m_staticDirs[2])) ? 0.f : deflection.y + (rand() % 21 - 10) * 1.0e-008f;
			deflection.z = (((deflection.z < 0.f) && m_staticDirs[5]) || ((deflection.z > 0.f) && m_staticDirs[4])) ? 0.f : deflection.z + (rand() % 21 - 10) * 1.0e-008f;

			deflection.MakeDirection();
			m_mat.TranslateDelta(deflection);
		}

		Reset();
		m_collider->PostRenderUpdate_first(m_mat);
	}

	void RigidBodyX::SolveCollisions()
	{
		for (unsigned short dir : {0, 1, 2, 3, 4, 5})
			CorrectPosition(dir);
	}

	void RigidBodyX::ConvertResponses()
	{
		if (!m_collider->m_collResponses.empty())
		{
			for (auto& respond : m_collider->m_collResponses)
			{
				AddImpulse(respond.m_dir, respond.m_strength, respond.m_fromStatic);
				AddLink(respond.m_perfectDistance, -respond.m_dir, respond.m_conter->GetParent()->GetRigidBody());
			}

			m_collider->m_collResponses.clear();
		}
	}

	void RigidBodyX::CorrectPosition(unsigned short direction)
	{
		ConvertResponses();
	
		for (auto& link : m_links[direction])
		{
			switch (link.Balance())
			{
			case detail::BALANCERESULT::BR_SUCCESS:
				link.GetTarget()->CorrectPosition(direction);
				break;
			case detail::BALANCERESULT::BR_SUCCESS_REVERT:
				CorrectPosition((direction % 2 == 1) ? direction - 1 : direction + 1);
			case detail::BALANCERESULT::BR_NONE_REVERT:
				SetStatic((direction % 2 == 1) ? direction - 1 : direction + 1, direction);
			}
		}
	}

	void RigidBodyX::SetStatic(unsigned short linkdirektion, unsigned short staticDirection)
	{
		ConvertResponses();

		m_staticDirs[staticDirection] = true;
		std::for_each(m_links[linkdirektion].begin(), m_links[linkdirektion].end(), [&](detail::CLink& link){link.GetTarget()->SetStatic(linkdirektion, staticDirection); });
	}

	void RigidBodyX::PostRenderUpdate_second(float fTimeDelta)
	{
		m_collider->PostRenderUpdate_second(fTimeDelta);
		m_ownerPlacement->SetMat(m_mat);
	}
}