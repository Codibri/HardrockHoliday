#include "Utility\TangentSpaceHelper.h"

namespace rs {

	TangentSpaceHelper::TangentSpaceHelper(){}

	TangentSpaceHelper::~TangentSpaceHelper(){}

	void TangentSpaceHelper::calculateTangentsAndBitangents(Vektoria::CGeo* geo){
		Vektoria::CVertexs* vertices = &geo->m_vertices;
		std::vector<Face> faces;
		const int arraySize = vertices->m_iVertexs;
		for (int i = 0; i < arraySize; i += 3)
		{
			Face f;
			f.v1 = vertices->m_apvertex[i];
			f.v2 = vertices->m_apvertex[i + 1];
			f.v3 = vertices->m_apvertex[i + 2];
			faces.push_back(f);
		}
		calculateTangents(faces);
	}




	void TangentSpaceHelper::calculateTangents(std::vector<Face>& faces){

		for (Face f : faces){


			Vektoria::CHVector v1 = f.v1->m_vPos;
			Vektoria::CHVector v2 = f.v2->m_vPos;
			Vektoria::CHVector v3 = f.v3->m_vPos;

			Vec2 w1; w1.X = f.v1->m_fU; w1.Y = f.v1->m_fV;
			Vec2 w2; w2.X = f.v2->m_fU; w2.Y = f.v2->m_fV;
			Vec2 w3; w3.X = f.v3->m_fU; w3.Y = f.v3->m_fV;

			float x1 = v2.x - v1.x;
			float x2 = v3.x - v1.x;
			float y1 = v2.y - v1.y;
			float y2 = v3.y - v1.y;
			float z1 = v2.z - v1.z;
			float z2 = v3.z - v1.z;

			float s1 = w2.X - w1.X;
			float s2 = w3.X - w1.X;
			float t1 = w2.Y - w1.Y;
			float t2 = w3.Y - w1.Y;

			float temp = (s1 * t2 - s2 * t1);
			float r = 1.0F / (s1 * t2 - s2 * t1);

			Vektoria::CHVector sdir((t2 * x1 - t1 * x2) * r, (t2 * y1 - t1 * y2) * r,
				(t2 * z1 - t1 * z2) * r);
			Vektoria::CHVector tdir((s1 * x2 - s2 * x1) * r, (s1 * y2 - s2 * y1) * r,
				(s1 * z2 - s2 * z1) * r);

			sdir.Norm();
			tdir.Norm();

			f.v1->m_vBitangent = sdir;
			f.v1->m_vTangent = tdir;

			f.v2->m_vBitangent = sdir;
			f.v2->m_vTangent = tdir;

			f.v3->m_vBitangent = sdir;
			f.v3->m_vTangent = tdir;

		}

	}

}