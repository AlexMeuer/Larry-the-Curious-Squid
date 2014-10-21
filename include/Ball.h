#ifndef _BALL_
#define _BALL_

#include "GameEntity.h"


class Ball : public GameEntity {
private:
	const float coefficentOfRestitution;
	
public:
	Ball(Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass);
	~Ball();
	void Update();
}
#endif