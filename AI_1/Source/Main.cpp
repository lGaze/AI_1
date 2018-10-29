#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


int main()
{
	
	//Create the SFML window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");
	window.setFramerateLimit(60);

	sf::Time startTime = sf::seconds(0.0f);
	sf::Time time = sf::seconds(1.0f);
	sf::Time movingTime = sf::seconds(30.0f);

	//Actor
	sf::RectangleShape actor(sf::Vector2f(100.f, 50.f));
	actor.setFillColor(sf::Color::White);

	//Target
	sf::CircleShape target(10.f);
	target.setFillColor(sf::Color::Yellow);
	target.setPosition(sf::Vector2f(900, 520));

	sf::Vector2f moveDir;
	moveDir = target.getPosition() - actor.getPosition();
	float magDir = sqrt((moveDir.x*moveDir.x) + (moveDir.y * moveDir.y));
	sf::Vector2f nmoveDir;
	nmoveDir.x = moveDir.x / magDir;
	nmoveDir.y = moveDir.y / magDir;


	//Program loop
	while (window.isOpen())
	{
		sf::Event Event;
		startTime = startTime + time;
		cout << startTime.asSeconds() << endl;

		while (window.pollEvent(Event))
		{
			//Close Event
			if (Event.type == sf::Event::Closed)
			{
				window.close();
			}

		}


		if (startTime == movingTime)
		{
		}

		//Color of the screen
		window.clear(sf::Color::Black);

		//Draw 
		window.draw(actor);
		window.draw(target);

		//Display the window
		window.display();
	}


	return 0;
}