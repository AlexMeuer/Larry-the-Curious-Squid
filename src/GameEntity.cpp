#include "..\include\GameEntity.h"

<<<<<<< HEAD
GameEntity::GameEntity(Texture* texture, Vector2f position, float angularVel, float rotation_degrees, float mass)
=======
GameEntity::GameEntity() {

}

GameEntity::GameEntity(Texture* texture, Vector2f position, Vector2f scale, float angularVel, float rotation_degrees, float mass)
>>>>>>> 437a3b48b3814e0bc27b93595eef20f2983696b0
	: m_position(position),
	m_angular_velocity(angularVel),
	m_rotation_degrees(rotation_degrees),
	m_mass(mass)
{
	m_sprite = Sprite(*texture);
	m_sprite.setScale(m_scale.x, m_scale.y);
}

GameEntity::~GameEntity(){
};


void GameEntity::Update() {

	m_position += m_velocity;
	m_rotation_degrees += m_angular_velocity;

	m_sprite.setPosition(m_position);
	m_sprite.setRotation(m_rotation_degrees);
}

void GameEntity::Draw(RenderWindow &w) {
	w.draw(m_sprite);
}


//Getters ------------------------------

Vector2f GameEntity::getPosition() const {
	return m_position;
}

Vector2f GameEntity::getVelocity() const {
	return m_velocity;
}



float GameEntity::getVelocityAngular() const {
	return m_angular_velocity;
}

float GameEntity::getRotation() const {
	return m_rotation_degrees;
}

float GameEntity::getMass() const {
	return m_mass;
}


//Setters ----------------------------

void GameEntity::setPosition(Vector2f const &newPos) {
	m_position = newPos;
}

void GameEntity::setVelocity(Vector2f const &newVel) {
	m_velocity = newVel;
}

//void GameEntity::setScale(Vector2f const &newScale) {
//	m_scale = newScale;
//	m_sprite.setScale(m_scale.x, m_scale.y);
//}

void GameEntity::setVelocityAngular(float const newVel) {
	m_angular_velocity = newVel;
}

void GameEntity::setRotation(float const degrees) {
	m_rotation_degrees = degrees;
}

void GameEntity::setMass(float const newMass) {
	m_mass = newMass;
}