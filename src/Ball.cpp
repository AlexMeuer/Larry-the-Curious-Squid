#include "..\include\Ball.h"

Ball::Ball(Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass)
: GameEntity( texture,  position,  velocity,  scale,  angularVel,  rotation_degrees,  mass), coefficentOfRestitution(1) {
	//create a circle
	sf::CircleShape circle(20);
	circle.setPosition(position);
}

Ball::~Ball(){

}

void Ball::Update() {
	
}

//
//void GameEntity::Update() {
//
//	m_position += m_velocity;
//	m_rotation_degrees += m_angular_velocity;
//
//	m_sprite.setPosition(m_position);
//	m_sprite.setRotation(m_rotation_degrees);
//}