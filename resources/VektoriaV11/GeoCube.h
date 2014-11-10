#pragma once
#include "TriangleList.h"
#include "Vertex.h"
#include "Face.h"

//------------------------------------------------------------------
// CGeCube: Klasse für eine Wuerfel-Geometrie
//
// Autor: Prof. Dr. Tobias Breiner 
// Letzte Änderung: 2011-10-16
//-------------------------------------------------------------------

namespace Vektoria
{

class CRenderApi;

class CGeoCube :
	public CTriangleList
{
public:
	CGeoCube(void);
	~CGeoCube(void);

	void Init(float fSize, CMaterial * pmaterial, float fTextureRepeat = 1.0f, bool bFlip = false); // Initialisiert eine Würfel-Geometrie
	void Init(CHVector vSize, CMaterial * pmaterial, float fTextureRepeat = 1.0f, bool bFlip = false); // Initialisiert eine Quader-Geometrie
// 	void Resize(CHVector vSize, int iTextureRepeat = 1);

//	float m_fSize;
	CVertex m_avertex[24];
};

}