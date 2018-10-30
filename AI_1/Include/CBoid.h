#pragma once
#include "../Include/CGameObject.h"


class CBoid : public CGameObject
{
public:

	CBoid();
	~CBoid();
	CVector seek(CVector target, float seekForce);
	CVector flee(CVector target, float fleeForce);
	CVector pursue(CVector target, float time);
	CVector evade(CVector target, float time);
	CVector arrive(CVector target, float radius, float magnitude);
	CVector wanderRandom(float magnitude);
	CVector wanderDirectional(float distance, float radius, float visionAngle, float magitude);
	CVector followPath();
	CVector patrol();

	inline CVector getDirection() { return m_Dir; };
	void setDirection(CVector newDirection);

private:

	CVector m_Dir;
};
