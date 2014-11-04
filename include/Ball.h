#ifndef _BALL_
#define _BALL_

#include "GameEntity.h"


class Ball : public GameEntity {
private:
	const float coefficentOfRestitution;
	Vector2f m_gravity;
	
public:
	Ball(Texture* texture, Vector2f gravity, Vector2f position, Vector2f velocity = Vector2f(0,0), Vector2f scale = Vector2f(1,1), float angularVel = 0, float rotation_degrees = 0, float mass = 1);

	~Ball();
	//void Update();
	//void Draw(sf::RenderWindow &w);
};
#endif