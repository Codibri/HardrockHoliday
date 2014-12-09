#include "Physics\Collider.h"

/*****************************************

#Collider.cpp

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
#include "Physics\Utilities.h"
#include "Physics\RigidBodyOwner.h"

namespace phyX
{

	Collider::Collider(RigidBodyOwner* parent, unsigned int projectionLines, float bounciness, bool isStatic, bool isTrigger)
		: m_parent(parent), m_isStatic(isStatic), m_isTrigger(isTrigger), m_bounciness(bounciness),
		m_physicLayer(0), m_isColliding(false), m_collisionRadius(0.f), m_projectionLinesCount(projectionLines)
	{
		
		m_localCenter = Vektoria::CHVector(0.f, 0.f, 0.f, 0.f); // center;
		m_localCenter.MakePoint();

	}

	Collider::~Collider()
	{

	}

	bool Collider::IsStatic()
	{
		return m_isStatic;
	}

	float Collider::Bounciness()
	{
		return m_bounciness;
	}

	bool Collider::isTrigger()
	{
		return m_isTrigger;
	}

	Vektoria::CHVector Collider::GetGlobalCenter()
	{
		return *m_mat * m_localCenter;
	}


	float Collider::GetCollisionRadius()
	{
		return m_collisionRadius;
	}


	bool Collider::IsColliding()
	{
		return m_isColliding;
	}

	int Collider::GetCollisionLayer()
	{
		return m_physicLayer;
	}

	std::string Collider::GetCollisionLayerName()
	{
		return CPhysiX::GetInstance()->TranslateLayer(m_physicLayer);
	}

	void Collider::SetLayer(std::string layer)
	{
		m_physicLayer = CPhysiX::GetInstance()->AddPhysiXLayer(layer);
	}

	RigidBodyOwner* Collider::GetParent()
	{
		return m_parent;
	}

	void Collider::AddCollision(Collider* coll, detail::CollisionResponse& response)
	{
		if (m_ghostImage.AddCollision(coll))
		{
			m_collRespLock.lock();
			m_collResponses.push_back(response);
			m_collRespLock.unlock();
		}
	}

	void Collider::AddCollision(Collider* coll)
	{
		m_ghostImage.AddCollision(coll);
	}

	void Collider::AddCollisionZone(detail::OctreeX* octree)
	{
		m_octrees.insert(octree);
	}

	void Collider::RemoveFromOctree()
	{
		for (auto& oc : m_octrees)
			oc->RemoveFromOctree(this);

		m_octrees.clear();
	}

	void Collider::RemoveFromOctree(detail::OctreeX* octree)
	{
		auto iter = m_octrees.find(octree);
		if (iter != m_octrees.end())
			m_octrees.erase(iter);
	}
	
	void Collider::InitGhost(Vektoria::CHMat& mat)
	{
		m_mat = &mat;
		m_ghostImage.Init(mat);
	}

	void Collider::PostRenderUpdate_first(Vektoria::CHMat& mat)
	{
		m_mat = &mat;

		if (phyX_utilties::CompareCHMat(&m_ghostImage.m_position_Last, m_mat))
			m_ghostImage.m_hasMoved = false;
		else
			m_ghostImage.m_hasMoved = true;

		m_ghostImage.m_TickColliding = false;
		m_ghostImage.m_conterCollInLastTick = m_ghostImage.m_conterCollInTick;
		m_ghostImage.m_conterCollInTick = std::set<Collider*>();

	}

	void Collider::PostRenderUpdate_second(float fTimeDelta)
	{
		for (auto& coll : m_ghostImage.m_conterCollInTick)
		{
			if (m_ghostImage.m_conterCollInLastTick.find(coll) == m_ghostImage.m_conterCollInLastTick.end())
				OnCollisionEnter(coll->m_parent, fTimeDelta);

			DuringCollision(coll->m_parent, fTimeDelta);
		}

		m_isColliding = m_ghostImage.m_TickColliding;
		m_ghostImage.m_position_Last = *m_mat;
	}

/******************************
	
GhostImage
	
******************************/

	Collider::GhostImage::GhostImage() : m_TickColliding(false), m_hasMoved(false)
	{
	}

	Collider::GhostImage::~GhostImage()
	{
	}

	void Collider::GhostImage::Init(Vektoria::CHMat& position)
	{
		m_position_Last = position;
	}

	bool Collider::GhostImage::AddCollision(Collider* coll)
	{
		std::lock_guard<std::mutex> guard(m_lock);
		if (m_conterCollInTick.find(coll) == m_conterCollInTick.end())
		{
			m_conterCollInTick.insert(coll);
			m_TickColliding = true;
			return true;
		}
		return false;
	}
}