#pragma once
#include "../Include/CVector.h"



class CGameObject
{
public:

	CGameObject();
	~CGameObject();
	CVector getPosition();
	void setPosition(float posX, float posY);

private:

	CVector m_pos;
};
