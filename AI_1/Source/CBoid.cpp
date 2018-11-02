#include "..\Include\CBoid.h"
#include <random>
#include <iostream>


constexpr float EPSILON = .001;
constexpr int MAX_FORCE = 100;

CBoid::CBoid()
{
}

CBoid::~CBoid()
{
}

CVector CBoid::seek(CVector target, float seekForce)
{
	CVector res;
	res = (target - m_pos).getNormalize();
	return res * seekForce;
}

CVector CBoid::flee(CVector target, float fleeForce)
{
	CVector res = m_pos - target;
	res.Normalize();
	return res * fleeForce;
}

CVector CBoid::pursue(CVector target, float time)
{
	CVector prediction;
	CVector direction;
	float distance = 0;
	float velocity = 0;
	float magnitudMaxima = 0;

	direction = target - getPosition();
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

	prediction.Normalize();
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

	direction = target - getPosition();
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
	CVector predictionToMe = prediction - getPosition();
	CVector result = direction + predictionToMe;
	return result;
}

CVector CBoid::arrive(CVector target, float radius, float magnitude)
{

	CVector direction = (target - m_pos);
	float distance = direction.magnitude();
	direction.Normalize();
	direction = direction * magnitude;

	if (distance < radius)
	{
		direction = direction * (distance / radius);
	}

	return direction;
}

CVector CBoid::wanderRandom(int Minimumx , int Minimumy , int Maximumx , int Maximumy ,float magnitude)
{
	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<int> valueX(Minimumx,Maximumx);
	std::uniform_int_distribution<int> valueY(Minimumy,Maximumy);
	
	float Xvalue = valueX(eng);
	float Yvalue = valueY(eng);

	CVector target;
	target.setValueX(Xvalue);
    target.setValueY(Yvalue);

	return seek(target,magnitude);

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

	return projectedPoint;
}

CVector CBoid::followPath(CVector node, float force)
{
	CVector res = node - m_pos;
	res.Normalize();
	return res * force;
}

CVector CBoid::patrol(CVector node, float force)
{
	CVector res = node - m_pos;
	res.Normalize();

	return res * force;
}

void CBoid::setDirection(CVector newDirection)
{
	m_Dir.setValueX(newDirection.getValueX());
	m_Dir.setValueY(newDirection.getValueY());
}

void CBoid::Update(float deltaTime, CVector steeringForce)
{
	CVector NewDirection;
	CVector NewPos;

	if (steeringForce.magnitude() > EPSILON)
	{
		steeringForce.truncate(MAX_FORCE);

		NewDirection = steeringForce + (m_Dir * m_Velocity);
		NewPos = m_pos + (NewDirection * deltaTime);

		
/*		NewDirection.Normalize();*/
		setDirection(NewDirection.getNormalize());
		setPosition(NewPos.getValueX(), NewPos.getValueY());
	}
}
