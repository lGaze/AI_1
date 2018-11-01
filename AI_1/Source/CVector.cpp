#include "..\Include\CVector.h"

CVector::CVector()
{
	this->X = 0.f;
	this->Y = 0.f;
}

CVector::CVector(float x, float y)
{
	this->X = x;
	this->Y = y;
}

CVector::~CVector()
{
}

void CVector::setValueX(float x)
{
	this->X = x;
}

void CVector::setValueY(float y)
{
	this->Y = y;
}

float CVector::getValueX()
{
	return X;
}

float CVector::getValueY()
{
	return Y;
}

float CVector::magnitude()
{
	float mag;
	mag = sqrt((X*X) + (Y*Y));
	return mag;
}

CVector CVector::getNormalize()
{
	float mag = magnitude();
	CVector normalized;
	normalized.setValueX( X / mag);
	normalized.setValueY( Y / mag);
	return normalized;
}

void CVector::Normalize()
{
	float mag = magnitude();
	X /= mag;
	Y /= mag;
}

CVector CVector::operator-(const CVector & val)
{
	CVector res;
	res.setValueX(X - val.X);
	res.setValueY(Y - val.Y);
	return res;
}

CVector CVector::operator*(float val)
{
	CVector res;
	res.setValueX(X * val);
	res.setValueY(Y * val);
	return res;
}

CVector CVector::operator+(const CVector & val)
{
	CVector res;
	res.setValueX(X + val.X);
	res.setValueY(Y + val.Y);
	return res;
}

CVector CVector::operator/(float val)
{
	return CVector();
}

void CVector::truncate(float max)
{
	float mag = magnitude();
	if (mag = max)
	{
		Normalize();
		*this = *this * max;
	}
}
