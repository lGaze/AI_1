#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Include/CBoid.h"
#include "../Include/CVector.h"
#include <vector>
using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Behaviours");

	
	//Clock for delta time
	sf::Clock clock;

	//Forces
	CVector steeringForce;
	CVector steeringForce_2;
	float seekForce = 10.f;

	//Boid_1 object
	CBoid boid_1;
	CVector StartDir(1.f, 1.f);
	boid_1.setPosition(400.f, 300.f);
	boid_1.setDirection(StartDir);
	
	//Boid_2 object
	CBoid boid_2;
	CVector StartDir_2(0.f, 1.f);
	boid_2.setPosition(700.f, 500.f);
	boid_2.setDirection(StartDir_2);

	//Actor object
	sf::CircleShape actor(10.f);
	actor.setFillColor(sf::Color::Green);
	actor.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actor.setOrigin(sf::Vector2f(10.f, 10.f));
	
	//Target object
	sf::CircleShape target(20.f);
	target.setFillColor(sf::Color::Red);
	target.setPosition(300.f, 400.f);
	CVector targetVect(target.getPosition().x, target.getPosition().y);
	target.setOrigin(20, 20);
	

	sf::CircleShape target_2(20.f);
	target_2.setFillColor(sf::Color::Red);
	target_2.setPosition(boid_2.getPosition().X, boid_2.getPosition().Y);
	CVector targetVect_2(target_2.getPosition().x, target_2.getPosition().y);
	target_2.setOrigin(20, 20);
	float delta = 0.0f;
	steeringForce = boid_1.wanderRandom(0, 0, 800, 600, seekForce);

	//Follow path nodes 800x600
	int i = 0;
	std::vector<CVector> nodes;
	CVector node_1(50, 50);
	nodes.push_back(node_1);
	CVector node_2(20, 150);
	nodes.push_back(node_2);
	CVector node_3(350, 120);
	nodes.push_back(node_3);
	CVector node_4(500, 220);
	nodes.push_back(node_4);
	steeringForce = boid_1.followPath(nodes[i], seekForce);

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

		delta += deltaTime;

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
		//steeringForce = boid_1.seek(boid_2.getPosition(), seekForce);
		//steeringForce = boid_1.flee(targetVect, seekForce);
		//steeringForce = boid_1.pursue(targetVect, seekForce);
	
		//if (delta >= 2.f)
		//{
		//	delta = 0.0f;
		//	steeringForce = boid_1.wanderRandom(0, 0, 800, 600, seekForce);
		//}


		//if (delta >= 2.f)
		//{
		//	if (i == nodes.size()-1)
		//	{
		//		steeringForce = boid_1.arrive(nodes[i], 10.f, seekForce);
		//	}
		//	else
		//	{
		//		delta = 0.0f;
		//		steeringForce = boid_1.followPath(nodes[i], seekForce);
		//		i++;
		//	}
		//	
		//}

		//if (delta >= 2.f)
		//{
		//	if (i == nodes.size() - 1)
		//	{
		//		delta = 0.0f;
		//		i = 0;
		//		steeringForce = boid_1.patrol(nodes[i], seekForce);
		//		i++;
		//	}
		//	else
		//	{
		//		delta = 0.0f;
		//		steeringForce = boid_1.patrol(nodes[i], seekForce);
		//		i++;
		//	}
		//
		//}

			boid_1.Update(deltaTime, steeringForce);

		


		//steeringForce_2 = boid_2.pursue(boid_1.getPosition(), 50.f);
		//boid_2.Update(deltaTime, steeringForce_2);

	  /************************************************************************/
		window.clear();

	  /********************************DRAW************************************/
		window.draw(target);
		boid_2.Draw(window, target_2);
		boid_1.Draw(window, actor);

	  /************************************************************************/
		window.display();
	}

	return 0;
}