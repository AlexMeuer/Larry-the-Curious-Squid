#ifndef _BLOCK_
#define _BLOCK_

#include "GameEntity.h"

class Block: public GameEntity {
	Block();
	Block(Texture* texture, Vector2f position, Vector2f velocity = Vector2f(0,0), Vector2f scale = Vector2f(0.2,0.2), float angularVel = 0, float rotation_degrees = 0, float mass = 1);

	~Block();
	void Update();
};
#endif