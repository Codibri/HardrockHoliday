#pragma once

#include "Vertex.h"
#include "RenderApi.h"
#include "TriangleList.h"

#define INDEX_INCREASE 1024

class CTriangleStripIndexed : public CTriangleList
{
public:
	CTriangleStripIndexed();
	~CTriangleStripIndexed();

	void AddIndex(int index);

	void Init(CRenderApi *prenderapi);
	void Fini();

	void Draw(float fDistanceToCameraSquare, bool bTransparent, CHMat & mGlobal);

	int *m_pindices;
	int m_iindicesCount;
	int m_iindicesMax;
	CRenderApi *m_prenderapi;
};