#ifndef OCTREE_X
#define OCTREE_X

/****************************************

Octree

Used for collision detection
This kind of octree is implemented as lazy octree.
Leaves get only generated if parent contains at least two colliders


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

#include <array>
#include <vector>
#include <HVector.h>


namespace phyX
{
	class Collider;

	namespace detail
	{

		//Vector structure used by the octree
		struct OctreeXVector
		{
			float x;
			float y;
			float z;

			OctreeXVector(){}

			OctreeXVector(float x, float y, float z) : x(x), y(y), z(z){}

			OctreeXVector operator+ (OctreeXVector& vec)
			{
				return OctreeXVector(x + vec.x, y + vec.y, z + vec.z);
			}

			OctreeXVector operator+ (const OctreeXVector& vec) const
			{
				return OctreeXVector(x + vec.x, y + vec.y, z + vec.z);
			}

			OctreeXVector operator- (OctreeXVector& vec)
			{
				return OctreeXVector(x - vec.x, y - vec.y, z - vec.z);
			}

			OctreeXVector operator- (const OctreeXVector& vec) const
			{
				return OctreeXVector(x - vec.x, y - vec.y, z - vec.z);
			}

			OctreeXVector operator* (float value)
			{
				return OctreeXVector(x * value, y * value, z * value);
			}

			Vektoria::CHVector ToCHVector()
			{
				return Vektoria::CHVector(x, y, z);
			}

			Vektoria::CHVector ToCHVector() const
			{
				return Vektoria::CHVector(x, y, z);
			}
		};


		//octree implemented as lazy ocree
		class OctreeX
		{

		public:
			OctreeX(float WorldSize, float minOctreeSize);
			~OctreeX();

			// only filled by the root, contains all leaves of the octree filled with at least one dynamic collider
			std::vector<OctreeX*>* m_filledLeaves;

			//add collider to the octree and insert it to the right leaves
			void InsertCollider(Collider* coll);

			//remove collider from this octreeleaf
			void RemoveFromOctree(Collider* coll);

			//returns a pointer the vector which contains all colliders in that sector
			std::vector<Collider*>* GetEnclosedColliders();

			//for raycast, fills the container with all colliders of the childs that get hit by the ray
			void GetRayHitColliders(std::vector<Collider*>& vec, Vektoria::CHVector& direction, Vektoria::CHVector& startPos, float Length);

			//resets the octree and deletes all childs
			void ResetOctree();

		private:
			//constructor for intern octree growth
			OctreeX(OctreeXVector min, OctreeXVector max, OctreeX* parent, OctreeX* root);

			const float m_worldSize;			//size of the ingameworld
			const float m_octreeMinSize;		//minimum size of a child
			const OctreeXVector m_cornerMin;
			const OctreeXVector m_cornerMax;
			const OctreeXVector m_center;
			const float m_sphereRadius;
			OctreeX* m_root;
			bool m_isRegistered;
			bool m_isMinimumLeaf;
			std::array<OctreeX*, 8> m_childs;
			std::vector<Collider*> m_enclosedColls;	//container for all colliders in this leave, if sector is parent it this container is empty

			void CreateChilds();
			void registerAtRoot();
			void unregisterAtRoot();

		};
	}
}
#endif