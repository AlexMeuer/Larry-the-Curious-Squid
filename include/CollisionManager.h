#ifndef _COLLISIONMANAGER_
#define _COLLISIONMANAGER_

#include "Ball.h"

class CollisionManager{
private:
	static CollisionManager* m_instance;
	CollisionManager() {}
public:
	~CollisionManager() {}

	//get the instance of the manager (creates a new one if none exists)
	static CollisionManager* instance() {	return instance == NULL ? m_instance = new CollisionManager() : m_instance;	}

	void SquareCircle(Sprite* square, Ball* circle);
	bool SquareSquare(Sprite* squareOne, Sprite* squareTwo);
	bool OffScreen(RenderWindow &w, Ball* circle);
};
#endif