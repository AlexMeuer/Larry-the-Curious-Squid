#include "..\include\Ball.h"


Ball::Ball(Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass)
	: GameEntity( texture,  position, velocity, scale,  angularVel,  rotation_degrees,  mass), coefficentOfRestitution(1) {
	
	//create a circle
	/*circle.setRadius(20);
	circle.setPosition(position);
	circle.setFillColor(sf::Color::White);*/
}

Ball::~Ball(){

}

void Ball::Update(const Time &elapsedTime, const Vector2f &gravity) {
	GameEntity::Update(elapsedTime, gravity);	//call base class update method
}

