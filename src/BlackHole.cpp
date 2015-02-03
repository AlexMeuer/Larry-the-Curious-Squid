#include "BlackHole.h"

BlackHole::BlackHole(String targetScene, Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass) 
	: GameEntity( texture,  position, velocity, scale,  angularVel,  rotation_degrees,  mass) {//, m_force(Vector2f(position.x + this->getSprite().getGlobalBounds().width/2.0f,position.y + this->getSprite().getGlobalBounds().height/2.0f), -200){
		m_sprite.setPosition(position.x, position.y);
		m_sprite.setOrigin(71.5f, 71.5f);

		m_targetScene = targetScene;
}

BlackHole::~BlackHole() {

}

String BlackHole::getNextScene() const {
	return m_targetScene;
}

void BlackHole::Update(Time &elapsedTime, GameEntity entity ) {
	m_rotation_degrees += 0.05f;
	m_sprite.setRotation(m_rotation_degrees);
	//m_force.Apply(&entity, elapsedTime);
}
