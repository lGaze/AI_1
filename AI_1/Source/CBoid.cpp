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

CVector CBoid::flee(CVector target, float radius, float fleeForce)
{
	CVector fleevec = m_pos - target;
	float distance = (m_pos - target).magnitude();

	if (distance < radius)
	{
		return fleevec * fleeForce;
	}

	CVector res(0, 0);
	return res;

}

CVector CBoid::pursue(CBoid target, float time, float radius, float force)
{
	CVector newDir = target.getPosition() - m_pos;
	CVector vel = target.getDirection() * target.m_Velocity;
	float distance = newDir.magnitude();

	CVector pred = target.getPosition() + vel * time;

	if (distance < radius)
	{
		return seek(pred, force);
	}
	return seek(target.getPosition(), force);
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

	CVector arriveVec = (target - m_pos);
	float distance = arriveVec.magnitude();
	
	if (distance < radius)
	{
		return arriveVec = arriveVec * (distance / radius);
	}


	return arriveVec * magnitude;
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

CVector CBoid::followPath(std::vector<CVector> nodes, float force)
{
	CVector target = nodes[m_FollowPathCounter];
	CVector followVec = target - m_pos;
	float radius = 10.f;
	float distance = followVec.magnitude();
	followVec.Normalize();

	if (distance < radius)
	{
		if (m_FollowPathCounter == nodes.size()-1)
		{
			followVec = arrive(target, radius, force);
			return followVec;
		}
		else
		{
			m_FollowPathCounter++;
		}
	}
	std::cout << m_FollowPathCounter << std::endl;
	return followVec * force;

}

CVector CBoid::patrol(std::vector<CVector> nodes, bool circular, float force)
{

	CVector target = nodes[m_PatolCounter];
	CVector followVec = target - m_pos;
	float radius = 10.f;
	float distance = followVec.magnitude();
	followVec.Normalize();

	if (m_PatolCounter == nodes.size()-1)
	{
		m_finish = true;
	}
	else if (m_PatolCounter == 0)
	{
		m_finish = false;
	}

	if (!circular)
	{
		if (distance < radius)
		{
			if (m_finish == false)
			{
				m_PatolCounter++;
			}
			else
			{
				m_PatolCounter--;
			}
		}
	}
	else
	{
		if (distance < radius)
		{
			if (m_finish == false)
			{
				m_PatolCounter++;
			}
			else
			{
				m_PatolCounter = 0;
			}
		}
	}
	return followVec * force;
}

CVector CBoid::obstacleAvoidance(CVector obstacle, float radius)
{
	CVector newDir = obstacle - m_pos;
	float distance = newDir.magnitude();
	if (distance < radius)
	{
		return newDir = newDir * -1000;
	}

	CVector vecZ (0.f, 0.f);
	return vecZ;
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
