#include "..\Include\CBoid.h"

CBoid::CBoid()
{
}

CBoid::~CBoid()
{
}

CVector CBoid::seek(float SeekForce, CVector target)
{
	CVector res;
	return res = (this->position() - target).normalize() * SeekForce;
}

CVector CBoid::flee(float fleeForce, CVector target)
{
	CVector res;
	return res = (target - this->position()).normalize() * fleeForce;
}
