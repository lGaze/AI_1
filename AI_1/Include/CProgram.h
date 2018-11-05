#pragma once
#include <SFML/Graphics.hpp>

class CProgram
{
public:

	CProgram();
	~CProgram();
	void run();
	
private:

	void seekScene();
	void fleeScene();
	void arriveScene();
	void pursueScene();
	void patrolScene();
	void followPathScene();
	void wanderRandomScene();
	void obstacleAvoidanceScene();
};
