#ifndef CPHYSIX_H
#define CPHYSIX_H

/****************************************

Core class for the CPhysiX module. It provides the feature of collision detection and collision response.
A lazy octree is used for collision detection and a thread pool for calculation.
CPhysics needs to be ticked at the end of the frame (PostRenderUpdate). Be sure to move all object in PreRender
otherwise physix will override the movement and the translation is lost.

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

#include <vector>
#include <HVector.h>
#include <map>
#include <thread>

#include <Camera.h>
#include <DeviceMouse.h>
#include <Placement.h>
#include <Frame.h>
#include "OctreeX.h"
#include "ThreadPoolX.h"
#include "Collider.h"
#include "RigidBodyX.h"

//#define _SINGLTHREADEDDEBUG			//use this to turn of the threadpool
#define FTIMEDELTACLIPPING			//providing loss of collision ! Warning game speed is no longer equal


namespace phyX
{

	static float const WORLDSIZE = 6144.f;						//size of the gameplayworld
	static float const OCTREECHILD_MIN = 32.f;					//the minimum size of a leaf of the physics octree

	static std::string const DEFAULT_PHYSICLAYER = "__DEFAULT";	//default physic layer all colliders get pushed on by default
	static std::string const RAY_PHYSICLAYER = "RAYLAYER";		//layer for raycast

	namespace detail { static float const FLOATCOMPENSATION = 1.00e-005f; }//because of the inaccuracy of float
	
	class Collider;

	//struct for a raycast hit
	struct RayHit
	{
		//point the object got hit, always closest point to the raystart 
		Vektoria::CHVector m_hitpoint;
		//pointer to the collider that got hit
		Collider* m_hitCollider;

		RayHit()
		{
			m_hitCollider = nullptr;
		}
	};

	//class doing all the physic operations
	class CPhysiX
	{
		friend RigidBodyX::RigidBodyX(Vektoria::CPlacement* ownerPlacement, Collider* collider, float mass, bool hasGravity);
		friend RigidBodyX::~RigidBodyX();

	public:

		static CPhysiX* GetInstance();
		void Destroy();
		
		//on EndTick the collision gets calculated
		void PostRenderUpdate(float fTimeDelta);

		//refreshes the octree of the physic and reinserts all existing colliders(use this e.g. at level start)
		void RefreshPhysiX();

		//adds a phyiclayer and returns the layernumber of the layer, if this layer already exists it returns its layernumber
		int AddPhysiXLayer(std::string layer);
		//identifies layer by layernumber and returns its name
		std::string TranslateLayer(unsigned int LayerNumber);
		//returns layernumber of the layer, if the layer doesn't exist it returns -1
		int GetLayerNumber(std::string layerName);

		//sets collision between the two layers, if both can collide with eachother value is true, if not it's false
		bool SetLayerProperty(std::string layer, std::string layer1, bool collision);
		
		//prints the layermatrix where you can see the collision conditions
		void PrintLayerMatrix();

		/*
		shoots a ray with given startpos and direction and returns a vector of all colliders ordered by distance to the startposition
		first RayHit in return value is the closest collider and hitpoint
		length's default is inifinite
		*/
		std::vector<RayHit> RayCast(Vektoria::CHVector& direction, Vektoria::CHVector& startPos, float Length = std::numeric_limits<float>::infinity());
		std::vector<RayHit> RayCastFromCamera(Vektoria::CFrame* frame, Vektoria::CPlacement* cameraPlacement, Vektoria::CCamera* camera, float Length = std::numeric_limits<float>::infinity());

	private:

		CPhysiX();
		~CPhysiX();

		//2D bool array designed for the layermatrix structure of CphysiX
		struct LayerMatrix
		{
			LayerMatrix(unsigned int size);
			~LayerMatrix();

			const unsigned int GetSize();
			void Resize(unsigned int size);

			bool** m_values;
			std::map<std::string, unsigned int> m_layers;

		private:
			unsigned int m_size;
		};

		static CPhysiX* m_instance;
		std::vector<RigidBodyX*> m_rigidBodies;
		std::vector<RigidBodyX*> m_newRigidBodies;
		LayerMatrix m_layerMatrix;
		detail::OctreeX m_octree;
		detail::ThreadPoolX m_tPool;
		std::vector<std::function<void()>> m_CheckTasks;

		unsigned int const DEFAULT_PHYSICLAYER_ID = 0;					//id of default physic layer
		unsigned int const RAY_PHYSICLAYER_ID = 1;						//id of raycastlayer

		//adds collider to physicsystem, gets called when a collider is instanciated
		RigidBodyX* AddRigidBody(RigidBodyX* rigid);
		//removes collider from cphysix, gets called when collider gets distroyed
		void RemoveRigidBody(RigidBodyX* rigid);

		//returns true if layers can collide with eachother
		bool CompareLayers(unsigned int  layer, unsigned int  layer2);
		//checks whether the collisionshperes of collider one and two intersect
		bool SpheresIntersect(Collider* coll, Collider* coll1);
		//separating axis theorem is used
		bool Intersect(Collider* coll, Collider* coll1);
		//checks a leaf of the octree for all collisions
		void CollisionCheck(detail::OctreeX* leaf);
		//calculates response
		void CalcResponse(Collider* coll, Collider* coll1, Vektoria::CHVector intersection, Vektoria::CHVector collNormal);
		//returns true if the point is inside the AABB described by the corner1 and corner2 vector
		bool PointInsideAABB(Vektoria::CHVector boxCorner1, Vektoria::CHVector boxCorner2, Vektoria::CHVector point);
	};
}

#endif