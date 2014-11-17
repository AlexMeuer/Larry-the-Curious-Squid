#include "..\include\Ball.h"


Ball::Ball(Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass)
	: GameEntity( texture,  position, velocity, scale,  angularVel,  rotation_degrees,  mass), coefficentOfRestitution(1) {
	
	//create a circle
	/*circle.setRadius(20);
	circle.setPosition(position);
	circle.setFillColor(sf::Color::White);*/
		time = 0;
}

Ball::~Ball(){

}

void Ball::Update(const Time &elapsedTime, const Vector2f gravity) {
	if(time != 0){
		time -= elapsedTime.asSeconds();
	}
	else{
		time = elapsedTime.asSeconds();
	}

 	m_position.x += (m_velocity.x) * (time) + (0.5f) * (gravity.x) * (time * time);
	m_position.y += (m_velocity.y) * (time) + (0.5f) * (gravity.y) * (time * time);

	m_rotation_degrees += m_angular_velocity;

	m_sprite.setPosition(m_position);
	m_sprite.setRotation(m_rotation_degrees);
}

void Ball::Colision(RenderWindow &w){
	//gose off edges
	//****Needs to add in the change of the sprite pos being centred not top left coner.******
	if((m_position.x < 0)||(m_position.x > 800)||(m_position.y < 0)||(m_position.y > 600)){
		Death_Reset();
	}
	//hit gameEntity

}

void Ball::Death_Reset(){
	m_position = Vector2f(20,50);
	m_sprite.setPosition(m_position);
	time = 0;
}

