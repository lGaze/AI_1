#pragma once
#include "../Include/CGameObject.h"


class CBoid : public CGameObject
{
public:

	CBoid();
	~CBoid();
	CVector seek(float seekForce, CVector target);
	CVector flee();
	CVector pursue();
	CVector arrive();
	CVector wanderRandom();
	CVector wanderDirectional();
	CVector followPath();
	CVector patrol();

private:

};
