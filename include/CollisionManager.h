#ifndef _COLLISIONMANAGER_
#define _COLLISIONMANAGER_

#include "GameEntity.h"

class CollisionManager{
public:
	
	bool SquareCircle(Sprite* square, GameEntity* circle);
	bool SquareSquare(Sprite* squareOne, Sprite* squareTwo);
};
#endif