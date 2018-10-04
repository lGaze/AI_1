#include "..\Include\CVector.h"

CVector::CVector()
{
}

CVector::~CVector()
{
}

void CVector::setValueX(float x)
{
	this->m_X = x;
}

void CVector::setValueY(float y)
{
	this->m_X = y;
}

float CVector::getValueX()
{
	return m_X;
}

float CVector::getValueY()
{
	return m_Y;
}

float CVector::magnitude()
{
	float mag;
	mag = sqrt((m_X*m_X) + (m_Y*m_Y));
	return mag;
}

CVector CVector::normalize()
{
	CVector normalized;
	normalized.setValueX(this->getValueX() / this->magnitude());
	normalized.setValueY(this->getValueY() / this->magnitude());
	return normalized;
}
