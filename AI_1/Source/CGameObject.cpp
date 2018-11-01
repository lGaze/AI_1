#include "..\Include\CGameObject.h"

CGameObject::CGameObject()
{
}

CGameObject::~CGameObject()
{
}

CVector CGameObject::getPosition()
{
	return m_pos;
}

void CGameObject::setPosition(float posX, float posY)
{
	m_pos = CVector(posX, posY);
}
