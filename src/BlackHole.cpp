#include "BlackHole.h"

BlackHole::BlackHole(Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass) 
	: GameEntity( texture,  position, velocity, scale,  angularVel,  rotation_degrees,  mass) , m_force(Vector2f(position.x + this->getSprite().getGlobalBounds().width/2.0f,position.y + this->getSprite().getGlobalBounds().height/2.0f), -200){
		m_sprite.setPosition(position.x, position.y);
		m_sprite.setOrigin((2/texture->getSize().x) * scale.x, (2/texture->getSize().y) * scale.y);
}

BlackHole::~BlackHole() {

}

void BlackHole::Update(Time const &elapsedTime, GameEntity* entity ) {
	//m_rotation_degrees += 0.05f;
	//m_sprite.setRotation(m_rotation_degrees);
	m_force.Apply(entity, elapsedTime);
}
