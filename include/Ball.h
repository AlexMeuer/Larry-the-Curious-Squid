#ifndef _BALL_
#define _BALL_

#include "GameEntity.h"


class Ball : public GameEntity {
private:
	const float coefficentOfRestitution;
<<<<<<< HEAD
	float m_scale;
	
public:
	Ball(Texture* texture, Vector2f position, float scale, float angularVel, float rotation_degrees, float mass);
=======

	sf::CircleShape circle;	//**
public:
	Ball();
	Ball(Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass);
>>>>>>> 437a3b48b3814e0bc27b93595eef20f2983696b0
	~Ball();
	void Update();
	void Draw(sf::RenderWindow &w); //**
};
#endif