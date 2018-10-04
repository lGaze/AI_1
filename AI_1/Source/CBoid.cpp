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
