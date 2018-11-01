#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Include/CBoid.h"
#include "../Include/CVector.h"
using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Behaviours");

	
	//Clock for delta time
	sf::Clock clock;

	//Forces
	CVector steeringForce;
	float seekForce = 10.f;

	//Boid_1 object
	CBoid boid_1;
	CVector StartDir(0.f, 1.f);
	boid_1.setPosition(400.f, 300.f);
	boid_1.setDirection(StartDir);
	
	//Actor object
	sf::CircleShape actor(10.f);
	actor.setFillColor(sf::Color::Green);
	actor.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actor.setOrigin(sf::Vector2f(10.f, 10.f));
	
	//Target object
	sf::CircleShape target(20.f);
	target.setFillColor(sf::Color::Red);
	target.setPosition(500.f, 400.f);
	CVector targetVect(target.getPosition().x, target.getPosition().y);
	target.setOrigin(20, 20);
	while (window.isOpen())
	{
		//Events
		sf::Event event;

		//Program Loop
		while (window.pollEvent(event))
		{
			//Close Event
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}

		float deltaTime = clock.restart().asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			target.move(1.f, 0.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
		}	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// left key is pressed: move our character
			target.move(-1.f, 0.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// left key is pressed: move our character
			target.move(0.f, -1.f);
			targetVect.setValueX(target.getPosition().x); 
			targetVect.setValueY(target.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// left key is pressed: move our character
			target.move(0.f, 1.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
		}
		

	  /********************************UPDATE**********************************/

		//steeringForce = boid_1.arrive(targetVect, 20.f, seekForce);
		//steeringForce = boid_1.seek(targetVect, seekForce);
		steeringForce = boid_1.flee(targetVect, seekForce);
		boid_1.Update(deltaTime, steeringForce);

	  /************************************************************************/
		window.clear();

	  /********************************DRAW************************************/
		window.draw(target);
		boid_1.Draw(window, actor);
	  /************************************************************************/
		window.display();
	}

	return 0;
}