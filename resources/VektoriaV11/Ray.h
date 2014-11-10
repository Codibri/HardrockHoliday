#pragma once
#include "HVector.h"
#include "HVector.h"
#include "Util.h"

//------------------------------------
// CRay
//
// Autor    : Prof. Dr. Tobias Breiner (Anlehnung und Erweiterung von CRay von Patrick Fleischmann zur besseren Aufwärtskompabilität)
// Ort      : Pfungstadt, 11.10.2013
// Copyright: Moyzelle Vektoria
//------------------------------------

namespace Vektoria
{

class CRay
{
public:
	CRay();
	~CRay();
	CRay(CHVector & vOrigin, CHVector & vDirection);
	CRay(CHVector& vOrigin, CHVector& vDirection, float fStart = QUASI_ZERO, float fEnd = FLT_MAX);

	CHVector operator()(float fT);
	void GetDirectionSign(int aiSigns[3]);


	CRay operator=(CRay ray); // Kopieroperator von Strahl ray
	void Copy(CRay ray); // Kopiert von Strahl ray 

	void Init(CHVector & vOrigin, CHVector & vDirection); // Initialieret Strahl ray
	void InitFromTo(CHVector & vOrigin, CHVector & vTo); // Initialieret Strahl ray mittels Start- und Endvektor

	void SetMin(float fMin); // Setzt Strahlminimaldistanz ausgehend von vOrigin
	void SetMax(float fMax); // Setzt Strahlmaximaldistanz ausgehend von vOrigin
	float GetMin();  // Gibt Strahlminimaldistanz ausgehend von vOrigin aus
	float GetMax(); // Gibt Strahlmaximaldistanz ausgehend von vOrigin aus

	float Distance(CRay & ray); // Berechnet den minimalen Abstand zweier Strahlgeraden
	float Distance(CHVector & v); // Berechnet den kleinsten Abstand der aktuellen Strahlgeraden von Punkt v

	float Angle(CHVector & v); // Berechnet den Winkel der Strecke zwischenvOrigin und Punkt v zum Strahl 


	CHVector m_vOrigin;
	CHVector m_vDirection;
	float m_fMin, m_fMax;

};

}