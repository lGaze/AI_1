#include "..\Include\CBoid.h"
#include <random>

CBoid::CBoid()
{
}

CBoid::~CBoid()
{
}

CVector CBoid::seek(CVector target, float seekForce)
{
	CVector res;
	return res = (this->position() - target).normalize() * seekForce;
}

CVector CBoid::flee(CVector target, float fleeForce)
{
	CVector res;
	return res = (target - this->position()).normalize() * fleeForce;
}

CVector CBoid::pursue(CVector target, float time)
{
	CVector prediction;
	CVector direction;
	float distance = 0;
	float velocity = 0;
	float magnitudMaxima = 0;

	direction = target - this->position();
	distance = direction.magnitude();
	velocity = distance / time;
	magnitudMaxima = velocity * time;

	if (distance > magnitudMaxima)
	{
		prediction = target + (direction * magnitudMaxima);
	}
	else
	{
		prediction = target + (direction * distance);
	}

	return prediction;
}

CVector CBoid::evade(CVector target, float time)
{
	CVector direction;
	CVector prediction;
	float distance = 0;
	float velocity = 0;
	float magnitudMaxima = 0;
	float radius = 0;

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

	prediction = target + (direction * radius);
	CVector predictionToMe = prediction - this->position();
	CVector result = direction + predictionToMe;
	return result;
}

CVector CBoid::arrive(CVector target, float radius, float magnitude)
{

	CVector direction;
	CVector force;
	float distance;

	direction = (target - this->position()).normalize();
	distance = direction.magnitude();
	force = seek(target,magnitude);

	if (distance < radius)
	{
		force = force + (direction*(distance / radius)*magnitude);
	}

	return force;
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

CVector CBoid::wanderDirectional(float distance, float radius, float visionAngle, float magitude)
{
	CVector projectedPoint;
	CVector finalPoint;
	float force;
	
	//NDir.x = cos(0)
	//NDir.Y = sen(0)

	//PF = PP + (Dir*r)
	//N (PF-P)
}
