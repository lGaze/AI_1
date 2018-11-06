#include "..\Include\CProgram.h"
#include "..\Include\CBoid.h"

CProgram::CProgram()
{
}

CProgram::~CProgram()
{
}

void CProgram::run()
{

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Behaviours");
	sf::RectangleShape rectangle(sf::Vector2f(900, 200));
	rectangle.setFillColor(sf::Color(153, 153, 153));
	rectangle.setPosition(960.f, 540.f);
	rectangle.setOrigin(480.f, 270.f);

	sf::Font font;
	if (!font.loadFromFile("C:/Proyectos/AI_1/AI_1/A.Casual.Handwritten.Pen.Noncommercial.ttf"))
	{
		std::cout << "error" << std::endl;
	}

	sf::Text text;

	// select the font
	text.setFont(font); 

	// set the string to display
	text.setString("MENU");

	// set the character size
	text.setCharacterSize(100); // in pixels, not points!

	// set the color
	text.setFillColor(sf::Color::White);
	text.setPosition(840.f, 300.f);

	sf::Text txt;
	
	txt.setFont(font);
	txt.setString("Press 1 to see SEEK\nPress 2 to see FLEE\nPress 3 to see ARRIVE\nPress 4 to see PATROL\nPress 5 to see FOLLOW PATH\nPress 6 to see WANDER RANDOM\nPress 7 to see OBSTACLE AVOIDANCE\nPress 8 to see PURSUE");
	txt.setCharacterSize(50);
	txt.setFillColor(sf::Color::White);
	txt.setPosition(500.f, 500.f);


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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			seekScene();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			fleeScene();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			arriveScene();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			patrolScene();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			followPathScene();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			wanderRandomScene();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		{
			obstacleAvoidanceScene();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
		{
			pursueScene();
		}

		window.clear();
		window.draw(rectangle);
		window.draw(text);
		window.draw(txt);
		window.display();

	}
	
}

void CProgram::seekScene()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Seek");

	sf::Font font;
	if (!font.loadFromFile("C:/Proyectos/AI_1/AI_1/A.Casual.Handwritten.Pen.Noncommercial.ttf"))
	{
		std::cout << "error" << std::endl;
	}
	sf::Text text;

	// select the font
	text.setFont(font);

	// set the string to display
	text.setString("PRESS ESC TO RETURN");

	// set the character size
	text.setCharacterSize(50); 

	// set the color
	text.setFillColor(sf::Color::White);
	text.setPosition(1550.f, 20.f);

	//Clock for delta time
	sf::Clock clock;

	//Forces
	CVector steeringForce;
	float seekForce = 10.f;

	//Boid_1 object
	CBoid boid_1;
	CVector StartDir(1.f, 1.f);
	boid_1.setPosition(400.f, 300.f);
	boid_1.setDirection(StartDir);

	//Actor object
	sf::CircleShape actor(10.f);
	actor.setFillColor(sf::Color::Green);
	actor.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actor.setOrigin(sf::Vector2f(10.f, 10.f));
	//Actor Radius
	sf::CircleShape actorRadius(100.f);
	actorRadius.setFillColor(sf::Color::Black);
	actorRadius.setOutlineColor(sf::Color::White);
	actorRadius.setOutlineThickness(3.f);
	actorRadius.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actorRadius.setOrigin(100.f, 100.f);

	//Target object
	sf::CircleShape target(20.f);
	target.setFillColor(sf::Color::Red);
	target.setPosition(920.f, 500.f);
	CVector targetVect(target.getPosition().x, target.getPosition().y);
	target.setOrigin(20, 20);
	//Target Radius
	sf::CircleShape targetRadius(200.f);
	targetRadius.setFillColor(sf::Color::Black);
	targetRadius.setOutlineColor(sf::Color::Black);
	targetRadius.setOutlineThickness(3.f);
	targetRadius.setPosition(920.f, 500.f);
	targetRadius.setOrigin(200.f, 200.f);
	CVector targetRadiusVec(targetRadius.getPosition().x, targetRadius.getPosition().y);

	float delta = 0.0f;

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		float deltaTime = clock.restart().asSeconds();

		delta += deltaTime;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			target.move(-1.f, 0.f);
			targetRadius.move(-1.f, 0.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// left key is pressed: move our character
			target.move(1.f, 0.f);
			targetRadius.move(1.f, 0.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// left key is pressed: move our character
			target.move(0.f, -1.f);
			targetRadius.move(0.f, -1.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// left key is pressed: move our character
			target.move(0.f, 1.f);
			targetRadius.move(0.f, 1.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}


		/********************************UPDATE**********************************/

		steeringForce = boid_1.seek(targetVect, seekForce);
		boid_1.Update(deltaTime, steeringForce);

		/************************************************************************/
		window.clear();

		/********************************DRAW************************************/
		window.draw(text);
		window.draw(target);
		boid_1.Draw(window, actor);

		/************************************************************************/
		window.display();
	}
}

void CProgram::fleeScene()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Flee");

	sf::Font font;
	if (!font.loadFromFile("C:/Proyectos/AI_1/AI_1/A.Casual.Handwritten.Pen.Noncommercial.ttf"))
	{
		std::cout << "error" << std::endl;
	}
	sf::Text text;

	// select the font
	text.setFont(font);

	// set the string to display
	text.setString("PRESS ESC TO RETURN");

	// set the character size
	text.setCharacterSize(50);

	// set the color
	text.setFillColor(sf::Color::White);
	text.setPosition(1550.f, 20.f);


	//Clock for delta time
	sf::Clock clock;

	//Forces
	CVector steeringForce;
	float fleeForce = 10.f;

	//Boid_1 object
	CBoid boid_1;
	CVector StartDir(1.f, 1.f);
	boid_1.setPosition(400.f, 300.f);
	boid_1.setDirection(StartDir);

	//Actor object
	sf::CircleShape actor(10.f);
	actor.setFillColor(sf::Color::Green);
	actor.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actor.setOrigin(sf::Vector2f(10.f, 10.f));
	//Actor Radius
	sf::CircleShape actorRadius(300.f);
	actorRadius.setFillColor(sf::Color::Black);
	actorRadius.setOutlineColor(sf::Color::White);
	actorRadius.setOutlineThickness(3.f);
	actorRadius.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actorRadius.setOrigin(300.f, 300.f);

	//Target object
	sf::CircleShape target(10.f);
	target.setFillColor(sf::Color::Red);
	target.setPosition(920.f, 500.f);
	CVector targetVect(target.getPosition().x, target.getPosition().y);
	target.setOrigin(10, 10);
	//Target Radius
	sf::CircleShape targetRadius(200.f);
	targetRadius.setFillColor(sf::Color::Black);
	targetRadius.setOutlineColor(sf::Color::Black);
	targetRadius.setOutlineThickness(3.f);
	targetRadius.setPosition(920.f, 500.f);
	targetRadius.setOrigin(200.f, 200.f);
	CVector targetRadiusVec(targetRadius.getPosition().x, targetRadius.getPosition().y);

	float delta = 0.0f;

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		float deltaTime = clock.restart().asSeconds();

		delta += deltaTime;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			target.move(-1.f, 0.f);
			targetRadius.move(-1.f, 0.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// left key is pressed: move our character
			target.move(1.f, 0.f);
			targetRadius.move(1.f, 0.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// left key is pressed: move our character
			target.move(0.f, -1.f);
			targetRadius.move(0.f, -1.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// left key is pressed: move our character
			target.move(0.f, 1.f);
			targetRadius.move(0.f, 1.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}


		/********************************UPDATE**********************************/

		steeringForce = boid_1.flee(targetVect, 300, fleeForce);
		boid_1.Update(deltaTime, steeringForce);

		/************************************************************************/
		window.clear();

		/********************************DRAW************************************/
		window.draw(text);
		boid_1.Draw(window, actorRadius);
		window.draw(target);
		boid_1.Draw(window, actor);

		/************************************************************************/
		window.display();
	}
}

void CProgram::arriveScene()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Arrive");

	sf::Font font;
	if (!font.loadFromFile("C:/Proyectos/AI_1/AI_1/A.Casual.Handwritten.Pen.Noncommercial.ttf"))
	{
		std::cout << "error" << std::endl;
	}
	sf::Text text;

	// select the font
	text.setFont(font);

	// set the string to display
	text.setString("PRESS ESC TO RETURN");

	// set the character size
	text.setCharacterSize(50);

	// set the color
	text.setFillColor(sf::Color::White);
	text.setPosition(1550.f, 20.f);


	//Clock for delta time
	sf::Clock clock;

	//Forces
	CVector steeringForce;
	float arriveForce = 10.f;

	//Boid_1 object
	CBoid boid_1;
	CVector StartDir(1.f, 1.f);
	boid_1.setPosition(400.f, 300.f);
	boid_1.setDirection(StartDir);

	//Actor object
	sf::CircleShape actor(10.f);
	actor.setFillColor(sf::Color::Green);
	actor.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actor.setOrigin(sf::Vector2f(10.f, 10.f));
	//Actor Radius
	sf::CircleShape actorRadius(100.f);
	actorRadius.setFillColor(sf::Color::Black);
	actorRadius.setOutlineColor(sf::Color::White);
	actorRadius.setOutlineThickness(3.f);
	actorRadius.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actorRadius.setOrigin(100.f, 100.f);

	//Target object
	sf::CircleShape target(20.f);
	target.setFillColor(sf::Color::Red);
	target.setPosition(920.f, 500.f);
	CVector targetVect(target.getPosition().x, target.getPosition().y);
	target.setOrigin(20, 20);
	//Target Radius
	sf::CircleShape targetRadius(200.f);
	targetRadius.setFillColor(sf::Color::Black);
	targetRadius.setOutlineColor(sf::Color::Black);
	targetRadius.setOutlineThickness(3.f);
	targetRadius.setPosition(920.f, 500.f);
	targetRadius.setOrigin(200.f, 200.f);
	CVector targetRadiusVec(targetRadius.getPosition().x, targetRadius.getPosition().y);

	float delta = 0.0f;

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		float deltaTime = clock.restart().asSeconds();

		delta += deltaTime;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			target.move(-1.f, 0.f);
			targetRadius.move(-1.f, 0.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// left key is pressed: move our character
			target.move(1.f, 0.f);
			targetRadius.move(1.f, 0.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// left key is pressed: move our character
			target.move(0.f, -1.f);
			targetRadius.move(0.f, -1.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// left key is pressed: move our character
			target.move(0.f, 1.f);
			targetRadius.move(0.f, 1.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}


		/********************************UPDATE**********************************/

		steeringForce = boid_1.arrive(targetVect, 100.f, arriveForce);
		boid_1.Update(deltaTime, steeringForce);

		/************************************************************************/
		window.clear();

		/********************************DRAW************************************/
		window.draw(text);
		window.draw(target);
		boid_1.Draw(window, actor);

		/************************************************************************/
		window.display();
	}
}

void CProgram::pursueScene()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pursue");

	sf::Font font;
	if (!font.loadFromFile("C:/Proyectos/AI_1/AI_1/A.Casual.Handwritten.Pen.Noncommercial.ttf"))
	{
		std::cout << "error" << std::endl;
	}
	sf::Text text;

	// select the font
	text.setFont(font);

	// set the string to display
	text.setString("PRESS ESC TO RETURN");

	// set the character size
	text.setCharacterSize(50);

	// set the color
	text.setFillColor(sf::Color::White);
	text.setPosition(1550.f, 20.f);

	//Clock for delta time
	sf::Clock clock;

	//Forces
	CVector steeringForce;
	CVector steeringForce2;
	float purseForce = 10.f;

	//Boid_1 object
	CBoid boid_1;
	CVector StartDir(1.f, 1.f);
	boid_1.setPosition(400.f, 500.f);
	boid_1.setDirection(StartDir);

	//Actor object
	sf::CircleShape actor(10.f);
	actor.setFillColor(sf::Color::Green);
	actor.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actor.setOrigin(sf::Vector2f(10.f, 10.f));
	//Actor Radius
	sf::CircleShape actorRadius(100.f);
	actorRadius.setFillColor(sf::Color::Black);
	actorRadius.setOutlineColor(sf::Color::White);
	actorRadius.setOutlineThickness(3.f);
	actorRadius.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actorRadius.setOrigin(100.f, 100.f);

	//Target object
	sf::CircleShape target(20.f);
	target.setFillColor(sf::Color::Red);
	target.setPosition(1520.f, 500.f);
	CVector targetVect(target.getPosition().x, target.getPosition().y);
	target.setOrigin(20, 20);
	//Target Radius
	sf::CircleShape targetRadius(200.f);
	targetRadius.setFillColor(sf::Color::Black);
	targetRadius.setOutlineColor(sf::Color::Black);
	targetRadius.setOutlineThickness(3.f);
	targetRadius.setPosition(920.f, 500.f);
	targetRadius.setOrigin(200.f, 200.f);
	CVector targetRadiusVec(targetRadius.getPosition().x, targetRadius.getPosition().y);

	//Boid_2 object
	CBoid boid_2;
	CVector StartDir2(0.f, 1.f);
	boid_2.setPosition(700.f, 800.f);
	boid_2.setDirection(StartDir2);

	//Actor object2
	sf::CircleShape actor2(10.f);
	actor2.setFillColor(sf::Color::Green);
	actor2.setPosition(boid_2.getPosition().X, boid_2.getPosition().Y);
	actor2.setOrigin(sf::Vector2f(10.f, 10.f));


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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		float deltaTime = clock.restart().asSeconds();



		/********************************UPDATE**********************************/

		steeringForce = boid_1.seek(targetVect, purseForce);
		boid_1.Update(deltaTime, steeringForce);

		steeringForce2 = boid_2.pursue(boid_1, 10.f, 50.f, purseForce);
		boid_2.Update(deltaTime, steeringForce2);

		/************************************************************************/
		window.clear();

		/********************************DRAW************************************/
		window.draw(text);
		window.draw(target);
		boid_1.Draw(window, actor);
		boid_2.Draw(window, actor2);

		/************************************************************************/
		window.display();
	}
}

void CProgram::patrolScene()
{

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Patrol");

	sf::Font font;
	if (!font.loadFromFile("C:/Proyectos/AI_1/AI_1/A.Casual.Handwritten.Pen.Noncommercial.ttf"))
	{
		std::cout << "error" << std::endl;
	}
	sf::Text text;

	// select the font
	text.setFont(font);

	// set the string to display
	text.setString("PRESS ESC TO RETURN");

	// set the character size
	text.setCharacterSize(50);

	// set the color
	text.setFillColor(sf::Color::White);
	text.setPosition(1550.f, 20.f);


	//Clock for delta time
	sf::Clock clock;

	//Forces
	CVector steeringForce;
	float patrolForce = 10.f;

	//Boid_1 object
	CBoid boid_1;
	CVector StartDir(1.f, 1.f);
	boid_1.setPosition(400.f, 300.f);
	boid_1.setDirection(StartDir);

	//Actor object
	sf::CircleShape actor(10.f);
	actor.setFillColor(sf::Color::Green);
	actor.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actor.setOrigin(sf::Vector2f(10.f, 10.f));
	//Actor Radius
	sf::CircleShape actorRadius(100.f);
	actorRadius.setFillColor(sf::Color::Black);
	actorRadius.setOutlineColor(sf::Color::White);
	actorRadius.setOutlineThickness(3.f);
	actorRadius.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actorRadius.setOrigin(100.f, 100.f);

	//Target object
	sf::CircleShape target(20.f);
	target.setFillColor(sf::Color::Red);
	target.setPosition(920.f, 500.f);
	CVector targetVect(target.getPosition().x, target.getPosition().y);
	target.setOrigin(20, 20);
	//Target Radius
	sf::CircleShape targetRadius(200.f);
	targetRadius.setFillColor(sf::Color::Black);
	targetRadius.setOutlineColor(sf::Color::Black);
	targetRadius.setOutlineThickness(3.f);
	targetRadius.setPosition(920.f, 500.f);
	targetRadius.setOrigin(200.f, 200.f);
	CVector targetRadiusVec(targetRadius.getPosition().x, targetRadius.getPosition().y);

	std::vector<CVector> nodes;

	sf::CircleShape node1(10.f);
	node1.setFillColor(sf::Color::Yellow);
	node1.setPosition(100.f, 100.f);
	node1.setOrigin(10.f, 10.f);
	CVector node_1(node1.getPosition().x, node1.getPosition().y);
	nodes.push_back(node_1);

	sf::CircleShape node2(10.f);
	node2.setFillColor(sf::Color::Yellow);
	node2.setPosition(550.f, 600.f);
	node2.setOrigin(10.f, 10.f);
	CVector node_2(node2.getPosition().x, node2.getPosition().y);
	nodes.push_back(node_2);


	sf::CircleShape node3(10.f);
	node3.setFillColor(sf::Color::Yellow);
	node3.setPosition(700.f, 100.f);
	node3.setOrigin(10.f, 10.f);
	CVector node_3(node3.getPosition().x, node3.getPosition().y);
	nodes.push_back(node_3);

	sf::CircleShape node4(10.f);
	node4.setFillColor(sf::Color::Yellow);
	node4.setPosition(900.f, 900.f);
	node4.setOrigin(10.f, 10.f);
	CVector node_4(node4.getPosition().x, node4.getPosition().y);
	nodes.push_back(node_4);

	float delta = 0.0f;

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		float deltaTime = clock.restart().asSeconds();

		delta += deltaTime;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			target.move(-1.f, 0.f);
			targetRadius.move(-1.f, 0.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// left key is pressed: move our character
			target.move(1.f, 0.f);
			targetRadius.move(1.f, 0.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// left key is pressed: move our character
			target.move(0.f, -1.f);
			targetRadius.move(0.f, -1.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// left key is pressed: move our character
			target.move(0.f, 1.f);
			targetRadius.move(0.f, 1.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}


		/********************************UPDATE**********************************/

		steeringForce = boid_1.patrol(nodes, false, patrolForce);
		boid_1.Update(deltaTime, steeringForce);

		/************************************************************************/
		window.clear();

		/********************************DRAW************************************/
		window.draw(text);
		window.draw(node1);
		window.draw(node2);
		window.draw(node3);
		window.draw(node4);
		boid_1.Draw(window, actor);

		/************************************************************************/
		window.display();
	}
}

void CProgram::followPathScene()
{

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "FollowPath");

	sf::Font font;
	if (!font.loadFromFile("C:/Proyectos/AI_1/AI_1/A.Casual.Handwritten.Pen.Noncommercial.ttf"))
	{
		std::cout << "error" << std::endl;
	}
	sf::Text text;

	// select the font
	text.setFont(font);

	// set the string to display
	text.setString("PRESS ESC TO RETURN");

	// set the character size
	text.setCharacterSize(50);

	// set the color
	text.setFillColor(sf::Color::White);
	text.setPosition(1550.f, 20.f);


	//Clock for delta time
	sf::Clock clock;

	//Forces
	CVector steeringForce;
	float seekForce = 10.f;

	//Boid_1 object
	CBoid boid_1;
	CVector StartDir(1.f, 1.f);
	boid_1.setPosition(400.f, 300.f);
	boid_1.setDirection(StartDir);

	//Actor object
	sf::CircleShape actor(10.f);
	actor.setFillColor(sf::Color::Green);
	actor.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actor.setOrigin(sf::Vector2f(10.f, 10.f));
	//Actor Radius
	sf::CircleShape actorRadius(100.f);
	actorRadius.setFillColor(sf::Color::Black);
	actorRadius.setOutlineColor(sf::Color::White);
	actorRadius.setOutlineThickness(3.f);
	actorRadius.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actorRadius.setOrigin(100.f, 100.f);

	//Target object
	sf::CircleShape target(20.f);
	target.setFillColor(sf::Color::Red);
	target.setPosition(920.f, 500.f);
	CVector targetVect(target.getPosition().x, target.getPosition().y);
	target.setOrigin(20, 20);
	//Target Radius
	sf::CircleShape targetRadius(200.f);
	targetRadius.setFillColor(sf::Color::Black);
	targetRadius.setOutlineColor(sf::Color::Black);
	targetRadius.setOutlineThickness(3.f);
	targetRadius.setPosition(920.f, 500.f);
	targetRadius.setOrigin(200.f, 200.f);
	CVector targetRadiusVec(targetRadius.getPosition().x, targetRadius.getPosition().y);

	std::vector<CVector> nodes;

	sf::CircleShape node1(10.f);
	node1.setFillColor(sf::Color::Yellow);
	node1.setPosition(100.f, 100.f);
	node1.setOrigin(10.f, 10.f);
	CVector node_1(node1.getPosition().x, node1.getPosition().y);
	nodes.push_back(node_1);

	sf::CircleShape node2(10.f);
	node2.setFillColor(sf::Color::Yellow);
	node2.setPosition(550.f, 600.f);
	node2.setOrigin(10.f, 10.f);
	CVector node_2(node2.getPosition().x, node2.getPosition().y);
	nodes.push_back(node_2);


	sf::CircleShape node3(10.f);
	node3.setFillColor(sf::Color::Yellow);
	node3.setPosition(700.f, 100.f);
	node3.setOrigin(10.f, 10.f);
	CVector node_3(node3.getPosition().x, node3.getPosition().y);
	nodes.push_back(node_3);

	sf::CircleShape node4(10.f);
	node4.setFillColor(sf::Color::Yellow);
	node4.setPosition(900.f, 500.f);
	node4.setOrigin(10.f, 10.f);
	CVector node_4(node4.getPosition().x, node4.getPosition().y);
	nodes.push_back(node_4);


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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		float deltaTime = clock.restart().asSeconds();


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			target.move(-1.f, 0.f);
			targetRadius.move(-1.f, 0.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// left key is pressed: move our character
			target.move(1.f, 0.f);
			targetRadius.move(1.f, 0.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// left key is pressed: move our character
			target.move(0.f, -1.f);
			targetRadius.move(0.f, -1.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// left key is pressed: move our character
			target.move(0.f, 1.f);
			targetRadius.move(0.f, 1.f);
			targetVect.setValueX(target.getPosition().x);
			targetVect.setValueY(target.getPosition().y);
			targetRadiusVec.setValueX(target.getPosition().x);
			targetRadiusVec.setValueX(target.getPosition().y);
		}


		/********************************UPDATE**********************************/

		steeringForce = boid_1.followPath(nodes, seekForce);
		boid_1.Update(deltaTime, steeringForce);

		/************************************************************************/
		window.clear();

		/********************************DRAW************************************/
		window.draw(text);
		window.draw(node1);
		window.draw(node2);
		window.draw(node3);
		window.draw(node4);
		boid_1.Draw(window, actor);

		/************************************************************************/
		window.display();
	}
}

void CProgram::wanderRandomScene()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Wander Random");

	sf::Font font;
	if (!font.loadFromFile("C:/Proyectos/AI_1/AI_1/A.Casual.Handwritten.Pen.Noncommercial.ttf"))
	{
		std::cout << "error" << std::endl;
	}
	sf::Text text;

	// select the font
	text.setFont(font);

	// set the string to display
	text.setString("PRESS ESC TO RETURN");

	// set the character size
	text.setCharacterSize(50);

	// set the color
	text.setFillColor(sf::Color::White);
	text.setPosition(1550.f, 20.f);


	//Clock for delta time
	sf::Clock clock;

	//Forces
	CVector steeringForce;
	float wanderForce = 10.f;

	//Boid_1 object
	CBoid boid_1;
	CVector StartDir(1.f, 1.f);
	boid_1.setPosition(400.f, 300.f);
	boid_1.setDirection(StartDir);

	//Actor object
	sf::CircleShape actor(10.f);
	actor.setFillColor(sf::Color::Green);
	actor.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actor.setOrigin(sf::Vector2f(10.f, 10.f));
	//Actor Radius
	sf::CircleShape actorRadius(100.f);
	actorRadius.setFillColor(sf::Color::Black);
	actorRadius.setOutlineColor(sf::Color::White);
	actorRadius.setOutlineThickness(3.f);
	actorRadius.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actorRadius.setOrigin(100.f, 100.f);

	float delta = 0.0f;
	steeringForce = boid_1.wanderRandom(0, 0, 1920, 1080, wanderForce);

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		float deltaTime = clock.restart().asSeconds();

		delta += deltaTime;

		

		/********************************UPDATE**********************************/

		if (delta > 2.0f)
		{
			delta = 0;
			steeringForce = boid_1.wanderRandom(0,0,1920,1080,wanderForce);
		}

		boid_1.Update(deltaTime, steeringForce);

		/************************************************************************/
		window.clear();

		/********************************DRAW************************************/
		window.draw(text);
		boid_1.Draw(window, actor);

		/************************************************************************/
		window.display();
	}
}

void CProgram::obstacleAvoidanceScene()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Obstacle Avoidance");

	sf::Font font;
	if (!font.loadFromFile("C:/Proyectos/AI_1/AI_1/A.Casual.Handwritten.Pen.Noncommercial.ttf"))
	{
		std::cout << "error" << std::endl;
	}
	sf::Text text;

	// select the font
	text.setFont(font);

	// set the string to display
	text.setString("PRESS ESC TO RETURN");

	// set the character size
	text.setCharacterSize(50);

	// set the color
	text.setFillColor(sf::Color::White);
	text.setPosition(1550.f, 20.f);


	//Clock for delta time
	sf::Clock clock;

	//Forces
	CVector steeringForce;
	float seekForce = 10.f;

	//Boid_1 object
	CBoid boid_1;
	CVector StartDir(1.f, 1.f);
	boid_1.setPosition(100.f, 500.f);
	boid_1.setDirection(StartDir);

	//Actor object
	sf::CircleShape actor(10.f);
	actor.setFillColor(sf::Color::Green);
	actor.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actor.setOrigin(sf::Vector2f(10.f, 10.f));
	//Actor Radius
	sf::CircleShape actorRadius(100.f);
	actorRadius.setFillColor(sf::Color::Black);
	actorRadius.setOutlineColor(sf::Color::White);
	actorRadius.setOutlineThickness(3.f);
	actorRadius.setPosition(boid_1.getPosition().X, boid_1.getPosition().Y);
	actorRadius.setOrigin(100.f, 100.f);

	//Obstacle object
	sf::CircleShape Obstacle(20.f);
	Obstacle.setFillColor(sf::Color::Yellow);
	Obstacle.setPosition(920.f, 500.f);
	CVector obstacleVec(Obstacle.getPosition().x, Obstacle.getPosition().y);
	Obstacle.setOrigin(20, 20);

	//Obstacle Radius
	sf::CircleShape obstacleRadius(50.f);
	obstacleRadius.setFillColor(sf::Color::Black);
	obstacleRadius.setOutlineColor(sf::Color::White);
	obstacleRadius.setOutlineThickness(3.f);
	obstacleRadius.setPosition(920.f, 500.f);
	obstacleRadius.setOrigin(50, 50);
	CVector obstacleRadiusVec(obstacleRadius.getPosition().x, obstacleRadius.getPosition().y);

	//Target object
	sf::CircleShape target(20.f);
	target.setFillColor(sf::Color::Red);
	target.setPosition(1350.f, 500.f);
	CVector targetVect(target.getPosition().x, target.getPosition().y);
	target.setOrigin(20, 20);

	float delta = 0.0f;

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		float deltaTime = clock.restart().asSeconds();
		delta += deltaTime;

		/********************************UPDATE**********************************/
		
		steeringForce = boid_1.obstacleAvoidance(obstacleVec, 50.f);
		boid_1.Update(deltaTime, steeringForce);
		steeringForce = boid_1.arrive(targetVect, 20.f, seekForce);
		boid_1.Update(deltaTime, steeringForce);

		/************************************************************************/
		window.clear();

		/********************************DRAW************************************/
		window.draw(text);
		window.draw(obstacleRadius);
		window.draw(Obstacle);
		window.draw(target);
		boid_1.Draw(window, actor);

		/************************************************************************/
		window.display();
	}
}

