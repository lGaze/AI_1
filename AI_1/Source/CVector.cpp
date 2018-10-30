#include "..\Include\CVector.h"

CVector::CVector()
{
	this->m_X = 0.f;
	this->m_Y = 0.f;
}

CVector::CVector(float x, float y)
{
	this->m_X = x;
	this->m_Y = y;
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
	this->m_Y = y;
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
	normalized.setValueX( m_X / magnitude());
	normalized.setValueY( m_Y / magnitude());
	return normalized;
}

CVector CVector::operator-(const CVector & val)
{
	CVector res;
	res.setValueX(this->m_X - val.m_X);
	res.setValueY(this->m_Y - val.m_Y);
	return res;
}

CVector CVector::operator*(float val)
{
	CVector res;
	res.setValueX(m_X * val);
	res.setValueY(m_Y * val);
	return res;
}

CVector CVector::operator+(const CVector & val)
{
	CVector res;
	res.setValueX(this->m_X + val.m_X);
	res.setValueY(this->m_Y + val.m_Y);
	return res;
}
