#pragma once
#include "../Include/CGameObject.h"


class CBoid : public CGameObject
{
public:

	CBoid();
	~CBoid();
	CVector seek(float seekForce, CVector target);
	CVector flee(float fleeForce, CVector target);
	CVector pursue(float time, CVector target);
	CVector evade(float time, CVector target);
	CVector arrive();
	CVector wanderRandom();
	CVector wanderDirectional();
	CVector followPath();
	CVector patrol();

private:

};
