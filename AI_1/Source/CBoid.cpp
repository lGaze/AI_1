#include "..\Include\CBoid.h"
#include <random>

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

CVector CBoid::wanderRandom(float magnitude)
{
	std::default_random_engine generator;
	std::binomial_distribution<int> value(-1, 1);

	float Xvalue = value(generator);
	float Yvalue = value(generator);
	CVector target;
	target.setValueX(Xvalue);
    target.setValueY(Yvalue);
	target.normalize();
	return target * magnitude;

}
