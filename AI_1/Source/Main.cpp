#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Include/CBoid.h"
#include "../Include/CVector.h"
using namespace std;


int main()
{
	//Create the SFML window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");
	window.setFramerateLimit(60);


	//Actor
	CBoid boid;
	sf::CircleShape actor(10.0f);

	//Target
	sf::CircleShape target(10.0f);
	CVector vectorTarget;

	//Settings of actor
	actor.setFillColor(sf::Color::Green);
	actor.setPosition(sf::Vector2f(10, 10));
	actor.setOrigin(10.0f, 10.0f);
	boid.setPosition(actor.getPosition().x, actor.getPosition().y);
	boid.setDirection(CVector( 0.f,0.f));
	float steeringForce = 10.f;
	CVector steering (0,0);

	//Settings of target
	target.setFillColor((sf::Color::Yellow));
	target.setPosition(sf::Vector2f(400, 300));
	vectorTarget.setValueX(target.getPosition().x);
	vectorTarget.setValueY(target.getPosition().y);

	//Cloack for delta
	sf::Clock clock;


	//Program loop
	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		sf::Event Event;
		//Close Event
		while (window.pollEvent(Event))
		{
			//Close Event
			if (Event.type == sf::Event::Closed)
			{
				window.close();
			}
			

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			target.move(5.f, 0.f);
			vectorTarget.setValueX(target.getPosition().x);
			vectorTarget.setValueY(target.getPosition().y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// left key is pressed: move our character
			target.move(-5.f, 0.f);
			vectorTarget.setValueX(target.getPosition().x);
			vectorTarget.setValueY(target.getPosition().y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// left key is pressed: move our character
			target.move(0.f, -5.f);
			vectorTarget.setValueX(target.getPosition().x);
			vectorTarget.setValueY(target.getPosition().y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// left key is pressed: move our character
			target.move(0.f, 5.f);
			vectorTarget.setValueX(target.getPosition().x);
			vectorTarget.setValueY(target.getPosition().y);
		}

		CVector newDirection = boid.getDirection();
		float angle = atan2f(
			newDirection.m_Y,
			newDirection.m_X) * 180.f / 3.14159265358979323;


		CVector posFin = boid.getDirection().normalize() * 50 + boid.getPosition();
		sf::Vertex line[] = 
		{
			sf::Vertex(sf::Vector2f(posFin.m_X, posFin.m_Y)),
			sf::Vertex(sf::Vector2f(boid.getPosition().m_X, boid.getPosition().m_Y))
		};

		line->color = sf::Color::White;

		steering = steering + boid.seek(vectorTarget, steeringForce) + boid.getDirection() * deltaTime;
		boid.setDirection(steering.normalize());
		boid.setPosition(steering.m_X * deltaTime, steering.m_Y * deltaTime);
		actor.setPosition(boid.getPosition().m_X, boid.getPosition().m_Y);
		actor.setRotation(angle);



		//Draw Calls
		window.clear();
		window.draw(line, 2, sf::Lines);
		window.draw(actor);
		window.draw(target);
		window.display();

	}

	

	return 0;
}