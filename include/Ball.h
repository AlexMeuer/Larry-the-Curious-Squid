#ifndef _BALL_
#define _BALL_

#include "GameEntity.h"


class Ball : public GameEntity {
private:
	const float coefficentOfRestitution;
	float m_scale;
	
public:
	Ball(Texture* texture, Vector2f position, float scale, float angularVel, float rotation_degrees, float mass);
	~Ball();
	void Update();
};
#endif