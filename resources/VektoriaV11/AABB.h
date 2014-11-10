////////////////////////////////////////////////////
/// @file AABB.h
/// @author Benedikt Walser
/// @author Kim Werner
/// ** Copyright (c) Humanics GbR **
////////////////////////////////////////////////////
#pragma once

#include "HVector.h"

namespace Vektoria
{

class CAABB
{
  public:
    CAABB(void) {}
    CAABB(CHVector &vMin, CHVector &vMax);

    int GetLongestAxis(void);
    void Encompass(CAABB &box);
	void Encompass(CHVector &pos);
    bool IsInside(CHVector &pos);
    bool Intersects(CAABB &aabb);
    bool Intersects(CHVector &origin, CHVector &direction, float* r_fDistance);

    CHVector GetMidPoint(void) { return (m_vMin + m_vMax) * 0.5f; }
    CHVector &GetMin(void) { return m_vMin; }
    CHVector &GetMax(void) { return m_vMax; }
    CHVector GetSize(void) { return m_vMax - m_vMin; }

    void Copy(CAABB &box) { m_vMin = box.m_vMin; m_vMax = box.m_vMax; }

    CHVector m_vMin;
    CHVector m_vMax;
};

}