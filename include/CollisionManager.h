#ifndef _COLLISIONMANAGER_
#define _COLLISIONMANAGER_

#include "Ball.h"

class CollisionManager{
public:
	
	void SquareCircle(Sprite* square, Ball* circle);
	bool SquareSquare(Sprite* squareOne, Sprite* squareTwo);
	bool OffScreen(RenderWindow &w, Ball* circle);
};
#endif