﻿#include "Physics\CPhysiX.h"

/***************************************

#CPhysiX.cpp

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

#include <iterator>
#include <algorithm>
#include "Physics\Utilities.h"
#include "Physics\RigidBodyOwner.h"

namespace phyX
{
	CPhysiX* CPhysiX::m_instance = nullptr;

	CPhysiX* CPhysiX::GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new CPhysiX();

		return m_instance;
	}

	void CPhysiX::Destroy(){

		delete m_instance;
	}

	CPhysiX::CPhysiX() : m_octree(WORLDSIZE, OCTREECHILD_MIN), m_tPool(16), m_layerMatrix(2)
	{
		m_layerMatrix.m_layers[DEFAULT_PHYSICLAYER] = 0;
		m_layerMatrix.m_layers[RAY_PHYSICLAYER] = 1;
	}

	CPhysiX::~CPhysiX()
	{
		for (unsigned int i = 0; i < m_rigidBodies.size(); ++i)
			delete m_rigidBodies[i];

		m_rigidBodies.clear();

		for (unsigned int i = 0; i < m_newRigidBodies.size(); ++i)
			delete m_newRigidBodies[i];

		m_newRigidBodies.clear();

		m_instance = nullptr;
	}

	void CPhysiX::RefreshPhysiX()
	{
		for (auto& rigid : m_newRigidBodies)
			rigid->m_collider->RemoveFromOctree();

		m_octree.ResetOctree();

		for (auto& rigid : m_newRigidBodies)
			m_octree.InsertCollider(rigid->m_collider);
	}

	RigidBodyX* CPhysiX::AddRigidBody(RigidBodyX* rigid)
	{
		if (rigid != nullptr)
			m_newRigidBodies.push_back(rigid);
		
		return rigid;
	}

	void CPhysiX::RemoveRigidBody(RigidBodyX* rigid)
	{
		rigid->m_collider->RemoveFromOctree();
		m_rigidBodies.erase(remove(m_rigidBodies.begin(), m_rigidBodies.end(), rigid), m_rigidBodies.end());
	}

	int CPhysiX::AddPhysiXLayer(std::string layer)
	{
		int result = GetLayerNumber(layer);

		if (result == -1)
		{
			m_layerMatrix.Resize(m_layerMatrix.GetSize() + 1);
			m_layerMatrix.m_layers[layer] = m_layerMatrix.GetSize() - 1;
			result = m_layerMatrix.GetSize() - 1;
		}
			
		return result;
	}
	
	std::string CPhysiX::TranslateLayer(unsigned int LayerNumber)
	{
		std::string retVal = "";

		for (auto iter = m_layerMatrix.m_layers.begin(); iter != m_layerMatrix.m_layers.end(); ++iter)
			if (iter->second == LayerNumber)
				retVal = iter->first;
		return retVal;
	}

	int CPhysiX::GetLayerNumber(std::string layerName)
	{
		auto iter = m_layerMatrix.m_layers.find(layerName);
		if (iter != m_layerMatrix.m_layers.end())
			return iter->second;

		return -1;
	}
	
	void CPhysiX::PrintLayerMatrix()
	{
		
		std::cout << "\t";
		for (unsigned int i = 0; i < m_layerMatrix.GetSize(); ++i)
			std::cout << TranslateLayer(i) << "   ";

		std::cout << std::endl;

		for (unsigned int i = 0; i < m_layerMatrix.GetSize(); ++i)
		{
			std::cout << TranslateLayer(i) << "\t";
			
			for (unsigned int j = 0; j < m_layerMatrix.GetSize(); ++j)
			{
				std::cout << m_layerMatrix.m_values[i][j] << "\t";
			}
			std::cout << std::endl;
		}
			
	}

	bool CPhysiX::CompareLayers(unsigned int layer, unsigned int  layer2)
	{
		return m_layerMatrix.m_values[layer][layer2];
	}

	bool CPhysiX::SetLayerProperty(std::string layer, std::string layer1, bool collision)
	{
		if (m_layerMatrix.m_layers.find(layer) == m_layerMatrix.m_layers.end() || m_layerMatrix.m_layers.find(layer1) == m_layerMatrix.m_layers.end())
			return false;
		
		m_layerMatrix.m_values[GetLayerNumber(layer)][GetLayerNumber(layer1)] = collision;
		m_layerMatrix.m_values[GetLayerNumber(layer1)][GetLayerNumber(layer)] = collision;

		return true;
	}

	bool CPhysiX::SpheresIntersect(Collider* coll, Collider* coll1)
	{
		float radius = coll->GetCollisionRadius() + coll1->GetCollisionRadius();
		return ((coll->GetGlobalCenter() - coll1->GetGlobalCenter()).LengthSquare() <= (radius * radius));
	}

	bool CPhysiX::Intersect(Collider* coll, Collider* coll1)
	{

		if (SpheresIntersect(coll, coll1))
		{
			float minIntersection = FLT_MAX, checkTemp = 0;
			Vektoria::CHVector collNormal;
			Vektoria::CHVector* lines;
			std::array<Vektoria::CHVector, 3> collPoints, coll1Points;
			
			Vektoria::CHVector interPoint1, interPoint2;
			
			auto findNormal = [&]() -> bool {

				checkTemp = std::min<float>({ ((collPoints[0] - coll1Points[1]).LengthSquare()),
												((collPoints[1] - coll1Points[0]).LengthSquare()) });

				if (checkTemp < minIntersection)
				{
					minIntersection = checkTemp;
					collNormal = (collPoints[2] - coll1Points[2]).Normal();
					return true;
				}

				return false;
			};

			lines = coll->GetProjectionLines(coll1);

			//check all projectionlines of first collider
			for (unsigned int i = 0; i < coll->m_projectionLinesCount; ++i)
			{
				std::tie(collPoints[0], collPoints[1], collPoints[2]) = coll->GetPointsOnLine(*lines);
				std::tie(coll1Points[0], coll1Points[1], coll1Points[2]) = coll1->GetPointsOnLine(*lines);

				//if both points of both colliders are not inside the other two points, there is no collision
				if (!PointInsideAABB(coll1Points[0], coll1Points[1], collPoints[0]) && !PointInsideAABB(coll1Points[0], coll1Points[1], collPoints[1])
					&& !PointInsideAABB(collPoints[0], collPoints[1], coll1Points[0]) && !PointInsideAABB(collPoints[0], collPoints[1], coll1Points[1]))
					return false;

				//check for point that is the closest to the midpoint of each collider to get the intersection depth
				if (findNormal())
				{
					interPoint1 = ((coll1Points[2] - collPoints[0]).LengthSquare() < (coll1Points[2] - collPoints[1]).LengthSquare()) ? collPoints[0] : collPoints[1];
					interPoint2 = ((collPoints[2] - coll1Points[0]).LengthSquare() < (collPoints[2] - coll1Points[1]).LengthSquare()) ? coll1Points[0] : coll1Points[1];
				}				

				++lines;
			}
			
			lines = coll1->GetProjectionLines(coll);

			//check all projectionlines of second collider
			for (unsigned int i = 0; i < coll1->m_projectionLinesCount; ++i)
			{
				std::tie(collPoints[0], collPoints[1], collPoints[2]) = coll->GetPointsOnLine(*lines);
				std::tie(coll1Points[0], coll1Points[1], coll1Points[2]) = coll1->GetPointsOnLine(*lines);

				//if both points of both colliders are not inside the other two points, there is no collision
				if (!PointInsideAABB(coll1Points[0], coll1Points[1], collPoints[0]) && !PointInsideAABB(coll1Points[0], coll1Points[1], collPoints[1])
					&& !PointInsideAABB(collPoints[0], collPoints[1], coll1Points[0]) && !PointInsideAABB(collPoints[0], collPoints[1], coll1Points[1]))
					return false;

				//check for point that is the closest to the midpoint of each collider to get the intersection depth
				if (findNormal())
				{
					interPoint1 = ((coll1Points[2] - collPoints[0]).LengthSquare() < (coll1Points[2] - collPoints[1]).LengthSquare()) ? collPoints[0] : collPoints[1];
					interPoint2 = ((collPoints[2] - coll1Points[0]).LengthSquare() < (collPoints[2] - coll1Points[1]).LengthSquare()) ? coll1Points[0] : coll1Points[1];
				}

				++lines;
			}

			//calculate response
			CalcResponse(coll, coll1, interPoint2 - interPoint1, collNormal);
			return true;
		}
		return false;
	}

	void CPhysiX::CalcResponse(Collider* coll, Collider* coll1, Vektoria::CHVector intersection, Vektoria::CHVector collNormal)
	{
		//if one of both is a trigger no response is calculated
		if (coll->isTrigger() || coll1->isTrigger())
		{
			coll->AddCollision(coll1);
			coll1->AddCollision(coll);
			return;
		}
		//first collider is always non static

		const float collVelo = phyX_utilties::MultipleScalar(phyX_utilties::AbsOne(collNormal), coll->GetParent()->GetRigidBody()->m_velocityVec).Length();
		const Vektoria::CHVector perfectDistance = (coll->GetGlobalCenter() - coll1->GetGlobalCenter()) + intersection;

		coll->AddCollision(coll1, detail::CollisionResponse(collNormal, coll1->IsStatic() ? 
																		coll1->m_bounciness * collVelo * 2.0f :	
																		coll1->m_bounciness * phyX_utilties::MultipleScalar(phyX_utilties::AbsOne(collNormal), coll1->GetParent()->GetRigidBody()->m_velocityVec).Length(),
														   perfectDistance, coll1->IsStatic(), coll1));

		//check if second collider is static
		if (!coll1->IsStatic())
		{
			coll1->AddCollision(coll, detail::CollisionResponse(-collNormal, coll->m_bounciness * collVelo, perfectDistance, coll->IsStatic(), coll));
		}
		else
			coll1->AddCollision(coll);

	}

	bool CPhysiX::PointInsideAABB(Vektoria::CHVector& boxCorner1, Vektoria::CHVector& boxCorner2, Vektoria::CHVector& point)
	{
		if (((point.x < boxCorner1.x) && (point.x < boxCorner2.x))
			|| ((point.x > boxCorner1.x) && (point.x > boxCorner2.x)))
			return false;

		if (((point.y < boxCorner1.y) && (point.y < boxCorner2.y))
			|| ((point.y > boxCorner1.y) && (point.y > boxCorner2.y)))
			return false;

		if (((point.z < boxCorner1.z) && (point.z < boxCorner2.z))
			|| ((point.z > boxCorner1.z) && (point.z > boxCorner2.z)))
			return false;

		return true;
	}

	std::vector<RayHit> CPhysiX::RayCast(Vektoria::CHVector& direction, Vektoria::CHVector& startPos, float Length)
	{
		startPos.MakeDirection();
		std::vector<RayHit> retCollection;

		Collider **ptr;
		RayHit hit;

		std::vector<Collider*> hitColls;
		m_octree.GetRayHitColliders(hitColls, direction, startPos, Length);
		

		for (unsigned int i = 0; i < hitColls.size(); ++i)
		{
			ptr = &hitColls[i];

			if (!CompareLayers((*ptr)->GetCollisionLayer(), RAY_PHYSICLAYER_ID))
				continue;

			hit = (*ptr)->GetRayHit(direction, startPos, Length);

			if (hit.m_hitCollider != nullptr)
				retCollection.push_back(hit);
		}

		std::sort(retCollection.begin(), retCollection.end(), [&](RayHit hit1, RayHit hit2) -> bool {
			Collider *coll1 = hit1.m_hitCollider, *coll2 = hit2.m_hitCollider;
			return ((Vektoria::CHVector)startPos - coll1->GetGlobalCenter()).LengthSquare() < ((Vektoria::CHVector)startPos - coll2->GetGlobalCenter()).LengthSquare();
		});

		return retCollection;
	}
	
	std::vector<RayHit> CPhysiX::RayCastFromCamera(Vektoria::CFrame* frame, Vektoria::CPlacement* cameraPlacement, Vektoria::CCamera* camera, float Length)
	{
		std::vector<RayHit> retCollection;

		//float frx = mouse->GetAbsoluteX()/(float)frame->m_iWidthWindow;
		//float fry = mouse->GetAbsoluteY() / (float)frame->m_iHeightWindow;


		float frx, fry;

		frame->m_pdevicecursor->GetFractional(frx, fry);

		frx -= 0.5f;
		fry -= 0.5f;

		std::cout << "mouse: " << frx << "|" << fry << std::endl;

		Vektoria::CHVector vDirectionFovea = Vektoria::CHVector(0.0F, 0.0F, -1.0F, 0.0F);
		Vektoria::CHVector vDirectionUp = Vektoria::CHVector(0.0F, 1.F, 0.0F, 0.0F);
		Vektoria::CHVector vDirectionRight = Vektoria::CHVector(1.F, 0.0F, 0.0F, 0.0F);
		Vektoria::CHVector vOrigin = Vektoria::CHVector(0.0F, 0.0F, 0.0F, 1.0F);

		
		vOrigin = cameraPlacement->m_amGlobal[0] * vOrigin;
		vDirectionFovea = cameraPlacement->m_amGlobal[0] * vDirectionFovea;
		vDirectionUp = cameraPlacement->m_amGlobal[0] * vDirectionUp;
		vDirectionRight = cameraPlacement->m_amGlobal[0] * vDirectionRight;

		/*float fax = camera->m_faFov*frx;
		float fay = (camera->m_faFov / camera->m_fViewportAspectRatio)*fry;*/

		float fax =  camera->m_faFov * frx;
		float fay = (camera->m_faFov / camera->m_fViewportAspectRatio) * fry;
		

		float xScale = 1.5f * tan(fax); // Tan (alpha)   = Gegenkathete / Ankathete => Tan (alpha) *Ankathete  = Gegenkathete   
		float yScale = 1.5f * tan(fay); // Tan (alpha)   = Gegenkathete / Ankathete => Tan (alpha) *Ankathete  = Gegenkathete   
		Vektoria::CHVector vDirection = vDirectionFovea + vDirectionRight * xScale - vDirectionUp * yScale;
		vDirection.Normal();
		//r.Init(vOrigin, vDirection);
		//r.m_fMin = m_fNearClipping;
		//r.m_fMax = m_fFarClipping;*/

		retCollection = RayCast(vDirection, vOrigin, Length);

		return retCollection;
	}

	
	void CPhysiX::PostRenderUpdate(float fTimeDelta)
	{
		
#ifdef FTIMEDELTACLIPPING
		fTimeDelta = fTimeDelta > 0.09f ? 0.09f : fTimeDelta;
#endif

		for each (auto& rigid in m_rigidBodies)
		{
			rigid->PostRenderUpdate_first(fTimeDelta);
			if (rigid->m_collider->m_ghostImage.m_hasMoved)
			{
				rigid->m_collider->RemoveFromOctree();
				m_octree.InsertCollider(rigid->m_collider);
			}
		}


#ifdef _SINGLTHREADEDDEBUG

		for (auto& leaf : *m_octree.m_filledLeaves)
		CollisionCheck(leaf);
#else

		if (m_rigidBodies.size() > 100)
		{
			for (auto& leaf : *m_octree.m_filledLeaves)
				m_CheckTasks.push_back(std::bind(&CPhysiX::CollisionCheck, this, leaf));

			m_tPool.addMultipleTasks(m_CheckTasks);
			m_CheckTasks.clear();
			m_tPool.WaitForTasksDone();
		}
		else
		{
			for (auto& leaf : *m_octree.m_filledLeaves)
				CollisionCheck(leaf);
		}

#endif

		for each (auto& rigid in m_rigidBodies)
			rigid->SolveCollisions();

		for each (auto& rigid in m_rigidBodies)
			rigid->PostRenderUpdate_second(fTimeDelta);

		for each (auto& rigid in m_newRigidBodies)
		{
			rigid->Init();
			m_rigidBodies.push_back(rigid);
			m_octree.InsertCollider(rigid->m_collider);
		}
		m_newRigidBodies.clear();

	}

	//checks a leaf of the octree for all collisions
	void CPhysiX::CollisionCheck(detail::OctreeX* leaf)
	{

		auto colliders = leaf->GetEnclosedColliders();

		if (!colliders->empty())		//use prev because you don't need to check the last collider in vector for collision with itself
		{
			auto collCheck_Begin = colliders->begin();
			std::all_of(colliders->begin(), std::prev(colliders->end()), [&](Collider* coll) -> bool
			{
				//if the collider is static don't check anymore for collision because all further colliders are static
				if (coll->IsStatic())
					return FALSE;

				std::for_each(++collCheck_Begin, colliders->end(), [&, coll](Collider* coll2){

					if (CompareLayers(coll->GetCollisionLayer(), coll2->GetCollisionLayer()))
						Intersect(coll, coll2);

				});
				return TRUE;
			});
		}
	}
	


/********************************************************

struct LayerMatrix
	
******************************************************/


	CPhysiX::LayerMatrix::LayerMatrix(unsigned int size) : m_size(size)
	{
		if (size < 2)
			m_size = 2;

		m_values = new bool*[m_size];

		for (unsigned int i = 0; i < m_size; ++i)
		{
			m_values[i] = new bool[m_size];
			for (unsigned int j = 0; j < m_size; ++j)
				m_values[i][j] = true;
		}
	}

	CPhysiX::LayerMatrix::~LayerMatrix()
	{
		for (unsigned int j = 0; j < m_size; ++j)
			delete[] m_values[j];

		delete[] m_values;
	}

	const unsigned int CPhysiX::LayerMatrix::GetSize(){ return m_size; }

	void CPhysiX::LayerMatrix::Resize(unsigned int size)
	{
		bool** values = new bool*[size];

		for (unsigned int i = 0; i < size; ++i)
		{
			values[i] = new bool[size];
			for (unsigned int j = 0; j < size; ++j)
				values[i][j] = true;
		}

		for (unsigned int i = 0; (i < size) && (i < m_size); ++i)
			for (unsigned int j = 0; (j < size) && (j < m_size); ++j)
				values[i][j] = m_values[i][j];

		for (unsigned int i = 0; i < m_size; ++i)
			delete[] m_values[i];

		delete[] m_values;

		m_values = values;
		m_size = size;
	}
}