#pragma once
#include "../Include/CGameObject.h"
#include <iostream>
#include <vector>



class CBoid : public CGameObject
{
public:

	CBoid();
	~CBoid();
	CVector seek(CVector target, float seekForce);
	CVector flee(CVector target, float fleeForce);
	CVector pursue(CVector target, float time);
	CVector evade(CVector target, float time);
	CVector arrive(CVector target, float radius, float magnitude);
	CVector wanderRandom(int Minimumx, int Minimumy, int Maximumx, int Maximumy, float magnitude);
	CVector wanderDirectional(float distance, float radius, float visionAngle, float magitude);
	CVector followPath(CVector node, float force);
	CVector patrol(CVector node, float force);
	
	inline CVector getDirection() { return m_Dir; };
	void setDirection(CVector newDirection);
	void Update(float deltaTime, CVector steeringForce);

#ifdef SFML_GRAPHICS_API
	void Draw(sf::RenderWindow &window,sf::CircleShape actor)
	{
		std::vector<sf::Vertex>drLine;
		drLine.clear();
		drLine.emplace_back(sf::Vector2f(m_pos.X, m_pos.Y));

		CVector lineaPos = m_pos + (m_Dir * 100);
		drLine.emplace_back(sf::Vector2f(lineaPos.X, lineaPos.Y));
		window.draw(&drLine[0], 2, sf::Lines);

		actor.setPosition(m_pos.getValueX(), m_pos.getValueY());
		window.draw(actor);
	}
#endif

private:

	CVector m_Dir;
	float m_Velocity = 20.f;
};
