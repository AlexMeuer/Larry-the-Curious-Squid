#ifndef _LIFE_
#define _LIFE_

#include "GameEntity.h"

class Life : public GameEntity {
public:
	Life(Texture* texture, Vector2f position, Vector2f velocity = Vector2f(0,0), Vector2f scale = Vector2f(1,1), float angularVel = 0, float rotation_degrees = 0, float mass = 0);
	~Life();
};

#endif