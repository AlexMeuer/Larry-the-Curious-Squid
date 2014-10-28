#include "..\include\Ball.h"

Ball::Ball(Texture* texture, Vector2f position, float scale, float angularVel, float rotation_degrees, float mass)
: GameEntity( texture,  position,  angularVel,  rotation_degrees,  mass), coefficentOfRestitution(1), m_scale(scale) {
	
	
	//create a circle
	sf::CircleShape circle(20);
	circle.setPosition(position);
}

Ball::~Ball(){

}

void Ball::Update() {
	
}


//void Ball::Update() {
//
//
//
//	m_position += m_position;
//	m_rotation_degrees += m_angular_velocity;
//
//	m_sprite.setPosition(m_position);
//	m_sprite.setRotation(m_rotation_degrees);
//}