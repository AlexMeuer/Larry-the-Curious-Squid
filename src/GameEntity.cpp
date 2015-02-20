#include "GameEntity.h"

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
	m_sprite.setOrigin(Vector2f((texture->getSize().x * m_scale.x) / 2.0f, (texture->getSize().y * m_scale.y) / 2.0f));

	fmod_pos = FMOD_VECTOR();
	fmod_pos.x = position.x;
	fmod_pos.y = position.y;
	fmod_pos.z = 0;

	fmod_vel = FMOD_VECTOR();
	fmod_vel.x = velocity.x;
	fmod_vel.y = velocity.y;
	fmod_vel.z = 0;

	m_displacement = Vector2f(0,0);
}

GameEntity::~GameEntity(){
};


void GameEntity::Update(const Time &elapsedTime, const Vector2f &gravity) {

	//m_displacement += (m_velocity * (elapsedTime.asSeconds())) + (0.5f *  gravity * (elapsedTime.asSeconds() * elapsedTime.asSeconds()));
	m_displacement += m_velocity * elapsedTime.asSeconds() * 100.0f;

	//m_position += m_velocity;
	m_rotation_degrees += m_angular_velocity;

	fmod_pos.x = m_position.x;
	fmod_pos.y = m_position.y;

	fmod_vel.x = m_velocity.x;
	fmod_vel.y = m_velocity.y;

	m_sprite.setPosition(m_position + m_displacement);
	m_sprite.setRotation(m_rotation_degrees);
}

void GameEntity::Draw(RenderWindow &w) {
	w.draw(m_sprite);
}

void GameEntity::ResistForces(Time const &elapsedTime) {
	m_velocity *= 0.999f;
	m_displacement *= 0.999f;
}


//Getters ------------------------------
Sprite GameEntity::getSprite() const {
	return m_sprite;
}


Vector2f GameEntity::getPosition() const {
	return m_position + m_displacement + m_sprite.getOrigin();
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


const FMOD_VECTOR* GameEntity::getFMOD_POS() const {
	return &fmod_pos;
}

const FMOD_VECTOR* GameEntity::getFMOD_VEL() const {
	return &fmod_vel;
}


//Setters ----------------------------

void GameEntity::setPosition(Vector2f const &newPos) {
	m_displacement = newPos - m_position;
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