#include "..\include\Ball.h"

Ball::Ball() : coefficentOfRestitution(1), circle(20) {
	circle.setPosition(400, 10);
	circle.setFillColor(sf::Color::White);
}

Ball::Ball(Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass)
: GameEntity( texture,  position,  scale,  angularVel,  rotation_degrees,  mass), coefficentOfRestitution(1) {
	//create a circle
	
	circle.setRadius(20);
	circle.setPosition(position);
	circle.setFillColor(sf::Color::White);
}

Ball::~Ball(){

}

void Ball::Update() {
	
}

void Ball::Draw(sf::RenderWindow &w) {
	w.draw(circle);
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