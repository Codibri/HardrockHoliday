#include "Physics\OctreeX.h"

/*****************************************

#OctreeX.cpp

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
#include <algorithm>

#include "Physics\Utilities.h"
#include "Physics\CPhysiX.h"
#include "Physics\Collider.h"

namespace phyX
{
	namespace detail
	{
		OctreeX::OctreeX(float WorldSize, float minOctreeSize) : m_root(this), m_isRegistered(false), m_filledLeaves(new std::vector<OctreeX*>()), m_isMinimumLeaf(false),
			m_worldSize(WorldSize), m_octreeMinSize(minOctreeSize),
			m_cornerMin(OctreeXVector(-m_worldSize * 0.5f, -m_worldSize * 0.5f, -m_worldSize * 0.5f)), m_cornerMax(OctreeXVector(m_worldSize * 0.5f, m_worldSize * 0.5f, m_worldSize * 0.5f)),
			m_center(OctreeXVector(0.f, 0.f, 0.f)), m_sphereRadius(Vektoria::CHVector(m_worldSize, m_worldSize, m_worldSize).Length() * 0.5f)
		{
			m_childs.fill(nullptr);

		}

		OctreeX::OctreeX(OctreeXVector min, OctreeXVector max, OctreeX* parent, OctreeX* root)
			: m_cornerMin(min), m_cornerMax(max), m_root(root), m_isRegistered(false), m_isMinimumLeaf(false), m_worldSize(root->m_worldSize),
			m_octreeMinSize(root->m_octreeMinSize), m_filledLeaves(root->m_filledLeaves),
			m_center(min + (max - min) * 0.5f), m_sphereRadius(((m_center - max).ToCHVector()).Length())
		{
			m_childs.fill(nullptr);

			if (((m_cornerMax.x - m_cornerMin.x) * 0.5f) < m_octreeMinSize)
				m_isMinimumLeaf = true;

		}

		OctreeX::~OctreeX()
		{
			if (m_root == this)
			{
				m_filledLeaves->clear();
				delete m_filledLeaves;
				m_filledLeaves = nullptr;
			}

			if (m_childs[0] != nullptr)
				for (unsigned int i = 0; i < 8; ++i)
					delete m_childs[i];
		}

		void OctreeX::ResetOctree()
		{
			m_root->m_filledLeaves->clear();

			if (m_root->m_childs[0] != nullptr)
				for (unsigned int i = 0; i < 8; ++i)
				{
					delete m_childs[i];
					m_childs[i] = nullptr;
				}
		}

		void OctreeX::CreateChilds()
		{
			if (m_cornerMax.x - m_cornerMin.x > m_octreeMinSize)
			{
				OctreeXVector octreeHalf = (m_cornerMax - m_cornerMin) * 0.5f + m_cornerMin;

				m_childs[0] = new OctreeX(m_cornerMin, octreeHalf, this, m_root);
				m_childs[1] = new OctreeX(OctreeXVector(octreeHalf.x, m_cornerMin.y, m_cornerMin.z), OctreeXVector(m_cornerMax.x, octreeHalf.y, octreeHalf.z), this, m_root);
				m_childs[2] = new OctreeX(OctreeXVector(m_cornerMin.x, m_cornerMin.y, octreeHalf.z), OctreeXVector(octreeHalf.x, octreeHalf.y, m_cornerMax.z), this, m_root);
				m_childs[3] = new OctreeX(OctreeXVector(octreeHalf.x, m_cornerMin.y, octreeHalf.z), OctreeXVector(m_cornerMax.x, octreeHalf.y, m_cornerMax.z), this, m_root);
				m_childs[4] = new OctreeX(OctreeXVector(m_cornerMin.x, octreeHalf.y, m_cornerMin.z), OctreeXVector(octreeHalf.x, m_cornerMax.y, octreeHalf.z), this, m_root);
				m_childs[5] = new OctreeX(OctreeXVector(octreeHalf.x, octreeHalf.y, m_cornerMin.z), OctreeXVector(m_cornerMax.x, m_cornerMax.y, octreeHalf.z), this, m_root);
				m_childs[6] = new OctreeX(OctreeXVector(m_cornerMin.x, octreeHalf.y, octreeHalf.z), OctreeXVector(octreeHalf.x, m_cornerMax.y, m_cornerMax.z), this, m_root);
				m_childs[7] = new OctreeX(octreeHalf, m_cornerMax, this, m_root);
			}

		}

		void OctreeX::InsertCollider(Collider* coll)
		{
			Vektoria::CHVector collCenter = coll->GetGlobalCenter();
			float radius = coll->GetCollisionRadius();

			if (((collCenter.x - radius <= m_cornerMax.x) && (collCenter.x + radius >= m_cornerMin.x))
				&& ((collCenter.y - radius <= m_cornerMax.y) && (collCenter.y + radius >= m_cornerMin.y))
				&& ((collCenter.z - radius <= m_cornerMax.z) && (collCenter.z + radius >= m_cornerMin.z)))
			{
				if (m_childs[0] != nullptr)
				{
					for (auto& child : m_childs)
					{
						child->InsertCollider(coll);
					}
				}
				else
				{
					if ((m_isMinimumLeaf) || (m_enclosedColls.size() == 0))
					{
						if (coll->IsStatic())
							m_enclosedColls.insert(m_enclosedColls.end(), coll);
						else
							m_enclosedColls.insert(m_enclosedColls.begin(), coll);

						coll->AddCollisionZone(this);
						registerAtRoot();
					}
					else
					{
						CreateChilds();

						for (auto& child : m_childs)
						{
							child->InsertCollider(coll);
							for (auto& collider : m_enclosedColls)
							{
								collider->RemoveFromOctree(this);
								child->InsertCollider(collider);
							}
						}
						m_enclosedColls.clear();
						unregisterAtRoot();
					}
				}
			}
		}


		void OctreeX::RemoveFromOctree(Collider* coll)
		{
			std::swap(*std::find(m_enclosedColls.begin(), m_enclosedColls.end(), coll), m_enclosedColls.back());
			m_enclosedColls.pop_back();

			if ((m_enclosedColls.size() < 2) || (m_enclosedColls.front()->IsStatic()))
				unregisterAtRoot();

		}

		std::vector<Collider*>* OctreeX::GetEnclosedColliders()
		{
			return &m_enclosedColls;
		}

		void OctreeX::registerAtRoot()
		{

			if ((!m_isRegistered) && (m_enclosedColls.size() > 1) && (!m_enclosedColls.front()->IsStatic()))
			{
				m_root->m_filledLeaves->push_back(this);
				m_isRegistered = true;
			}
		}

		void OctreeX::GetRayHitColliders(std::vector<Collider*>& vec, Vektoria::CHVector& direction, Vektoria::CHVector& startPos, float Length)
		{
			Vektoria::CHVector movedCenter = m_center.ToCHVector() - startPos;
			Vektoria::CHVector pCenter = phyX_utilties::ProjectVector(movedCenter, direction);

			if ((movedCenter - pCenter).LengthSquare() <= (m_sphereRadius + FLOATCOMPENSATION)*(m_sphereRadius + FLOATCOMPENSATION))
			{
				if (m_childs[0] != nullptr)
				{
					for (auto& child : m_childs)
					{
						child->GetRayHitColliders(vec, direction, startPos, Length);
					}
				}
				else
				{
					vec.insert(vec.end(), m_enclosedColls.begin(), m_enclosedColls.end());
				}

			}

			//delete duplicate only if you're the root, so after every child has inserted its colliders
			if (m_root == this)
			{
				std::sort(vec.begin(), vec.end());
				auto last = std::unique(vec.begin(), vec.end());
				vec.erase(last, vec.end());
			}
		}

		void OctreeX::unregisterAtRoot()
		{
			if (m_isRegistered)
			{
				std::swap(*std::find(m_filledLeaves->begin(), m_filledLeaves->end(), this), m_filledLeaves->back());
				m_filledLeaves->pop_back();

				m_isRegistered = false;
			}

		}
	}
}