#include "..\include\GameEntity.h"

GameEntity::GameEntity(Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass)
	: m_position(position),
	m_velocity(velocity),
	m_scale(scale),
	m_angular_velocity(angularVel),
	m_rotation_degrees(rotation_degrees),
	m_mass(mass)
{
	m_sprite = Sprite(*texture);
	m_sprite.setScale(m_scale.x, m_scale.y);
}

GameEntity::~GameEntity(){
};


void GameEntity::Update(const Time elapsedTime, const Vector2f &gravity) {

	m_velocity = (m_velocity * (elapsedTime.asSeconds())) + (0.5f *  gravity * (elapsedTime.asSeconds() * elapsedTime.asSeconds()));

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

Vector2f GameEntity::getScale() const {
	return m_scale;
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


FMOD_VECTOR GameEntity::getFMOD_POS() const {
	FMOD_VECTOR pos;
	pos.x = m_position.x;
	pos.y = m_position.y;
	pos.z = 0;
	return pos;
}

FMOD_VECTOR GameEntity::getFMOD_VEL() const {
	FMOD_VECTOR vel;
	vel.x = m_velocity.x;
	vel.y = m_velocity.y;
	vel.z = 0;
	return vel;
}


//Setters ----------------------------

void GameEntity::setPosition(Vector2f const &newPos) {
	m_position = newPos;
}

void GameEntity::setVelocity(Vector2f const &newVel) {
	m_velocity = newVel;
}

void GameEntity::setScale(Vector2f const &newScale) {
	m_scale = newScale;
	m_sprite.setScale(m_scale.x, m_scale.y);
}

void GameEntity::setVelocityAngular(float const newVel) {
	m_angular_velocity = newVel;
}

void GameEntity::setRotation(float const degrees) {
	m_rotation_degrees = degrees;
}

void GameEntity::setMass(float const newMass) {
	m_mass = newMass;
}