#ifndef COLLIDER_H
#define COLLIDER_H

/****************************************

Base class for all types of colliders



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

#include <set>
#include <mutex>
#include <future>

#include <HMat.h>
#include <HVector.h>

#include "Callbacks.h"
#include "SpinLockX.h"
#include "OctreeX.h"

namespace phyX
{
	class RigidBodyOwner;

	namespace detail
	{
		struct CollisionResponse
		{
			Vektoria::CHVector m_dir;
			float m_strength;
			Vektoria::CHVector m_perfectDistance;
			bool m_fromStatic;
			Collider* m_conter;

			CollisionResponse(Vektoria::CHVector direction, float strength, Vektoria::CHVector perfectDistance, bool fromStatic, Collider* conter)
				: m_dir(direction), m_strength(strength), m_perfectDistance(perfectDistance), m_fromStatic(fromStatic), m_conter(conter)
			{
			}
		};
	}


	class Collider
	{

		friend class CPhysiX;
		friend class RigidBodyX;
		friend void detail::OctreeX::InsertCollider(Collider* coll);

	public:

		Collider(RigidBodyOwner* parent, unsigned int projectionLines, float bouncyness = 0.f, bool isStatic = false, bool isTrigger = false);
		~Collider();

		//returs true for the static setting
		bool const IsStatic();

		//returs true for the bouncy setting and if there is a bouncing effect
		float const Bounciness();

		//returns true if collider is trigger and no collision response gets calculated
		bool const isTrigger();
		
		//returns the center of the collider in global coords
		Vektoria::CHVector GetGlobalCenter();

		//returns the radius to the outer point of the collider, which is the radius of a possible collision
		float GetCollisionRadius();

		//returns true if colliding, after physiX calculates all collisions
		bool IsColliding();

		//returns the layer the collider is part of
		int GetCollisionLayer();

		//returns the name of layer the collider is part of
		std::string GetCollisionLayerName();

		//sets the physiclayer, if the layer doesn't exist the layer gets created
		void SetLayer(std::string layer);

		//returns the RigidBodyOwner the collider belongs to
		RigidBodyOwner* GetParent();

		//gets called when collider starts colliding
		detail::Callbacks<RigidBodyOwner*, float> OnCollisionEnter;
		//gets called while colliding
		detail::Callbacks<RigidBodyOwner*, float> DuringCollision;

		

	protected:

		//represents the collider in a tick
		class GhostImage
		{

		public:

			GhostImage();
			~GhostImage();
			void Init(Vektoria::CHMat& position);
			bool AddCollision(Collider* coll);

			std::set<Collider*> m_conterCollInTick;
			std::set<Collider*> m_conterCollInLastTick;
			std::mutex m_lock;
			bool m_TickColliding;
			bool m_hasMoved;
			Vektoria::CHMat m_position_Last;
		};

		bool const m_isStatic;
		bool const m_isTrigger;
		float const m_bounciness;
		Vektoria::CHVector m_localCenter;
		float m_collisionRadius;
		bool m_isColliding;
		int m_physicLayer;
		std::atomic_bool m_updateProjectionLines;
		Vektoria::CHMat* m_mat;
		std::set<detail::OctreeX*> m_octrees;
		detail::SpinLockX m_responseLock;
		Vektoria::CHVector* m_projectionLines;
		const unsigned int m_projectionLinesCount;
		std::mutex m_lock;
		GhostImage m_ghostImage;
		RigidBodyOwner* m_parent;
		std::vector<detail::CollisionResponse> m_collResponses;
		detail::SpinLockX m_collRespLock;

		//adds octreeleaf to this collider, in which the colider gets calculated
		void AddCollisionZone(detail::OctreeX* octree);

		//removes octreeleaf from collider
		void RemoveFromOctree();

		//removes octreeleave from collider
		void RemoveFromOctree(detail::OctreeX* octree);
		
		//returns projection lines for collision calculation, be sure to delete the result when no longer needed
		virtual Vektoria::CHVector* GetProjectionLines(Collider* otherCollider) = 0;

		//returns the outer points on a projection line, last vector is projected center
		virtual std::tuple<Vektoria::CHVector, Vektoria::CHVector, Vektoria::CHVector> GetPointsOnLine(Vektoria::CHVector projectionline) = 0;

		//returns the hitpoint of the collider with the given ray, if the collider of this rayhit is null there is no intersection
		virtual struct RayHit GetRayHit(Vektoria::CHVector& direction, Vektoria::CHVector& startPos, float Length) = 0;

		void AddCollision(Collider* coll, detail::CollisionResponse& response);
		void AddCollision(Collider* coll);
		void InitGhost(Vektoria::CHMat& mat);

		//prepares the collider for collision
		void PostRenderUpdate_first(Vektoria::CHMat& mat);

		//callbacks after collision get called and collision is completed
		void PostRenderUpdate_second(float fTimeDelta);

	};

}

#endif