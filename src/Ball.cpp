#include "..\include\Ball.h"


Ball::Ball(Texture* texture, Vector2f gravity, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass)
	: GameEntity( texture,  position, velocity, scale,  angularVel,  rotation_degrees,  mass), coefficentOfRestitution(1) {
	
	//create a circle
	/*circle.setRadius(20);
	circle.setPosition(position);
	circle.setFillColor(sf::Color::White);*/

		m_gravity = gravity;
}

Ball::~Ball(){

}

void Ball::Update() {
	GameEntity::Update();	//call base class update method
}

