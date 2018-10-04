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

CVector CBoid::pursue(float time, CVector target)
{
	CVector prediccion;
	CVector direction;
	float distance;
	float velocity;
	float magnitudMaxima;

	direction = target - this->position();
	distance = direction.magnitude();
	velocity = distance / time;
	magnitudMaxima = velocity * time;

	if (distance > magnitudMaxima)
	{
		prediccion = target + (direction * magnitudMaxima);
	}
	else
	{
		prediccion = target + (direction * distance);
	}

	return prediccion;
}

CVector CBoid::evade(float time, CVector target)
{
	CVector direction;
	float distance;
	float velocity;
	float magnitudMaxima;
	float radius;

	direction = target - this->position();
	distance = direction.magnitude();
	velocity = distance / time;
	magnitudMaxima = velocity * time;

	if (distance < magnitudMaxima)
	{
		radius = distance;
	}
	else
	{
		radius = magnitudMaxima;
	}

}
