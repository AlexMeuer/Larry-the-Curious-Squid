#ifndef _GAME_ENTITY_
#define _GAME_ENTITY_

#include "SFML\Graphics.hpp"
#include "fmod.hpp"

using namespace sf;

class GameEntity {
protected:
	Vector2f m_position, m_velocity, m_scale;

	FMOD_VECTOR fmod_pos, fmod_vel;

	float m_angular_velocity, m_rotation_degrees, m_mass;

	Sprite m_sprite;

	sf::ConvexShape shape;


public:

	GameEntity(); //**

	GameEntity(Texture *texture, Vector2f position, Vector2f velocity = Vector2f(0,0), Vector2f scale = Vector2f(1,1),
		float angularVel = 0, float rotation_degrees = 0, float mass = 1);
	~GameEntity();
	
	//-- GET -------------------------
	Sprite getSprite() const;
	Vector2f getPosition() const;
	Vector2f getVelocity() const;	//linear velocity
	Vector2f getScale() const;
	float getVelocityAngular() const;	//angular velocity
	float getRotation() const;	//degrees
	float getMass() const;

	const FMOD_VECTOR* getFMOD_POS() const;
	const FMOD_VECTOR* getFMOD_VEL() const;
	
	//-- SET -------------------------
	void setPosition(Vector2f const &newPos);
	void setVelocity(Vector2f const &newVel);
	void setScale(Vector2f const &newScale);
	void setVelocityAngular(float const newVel);
	void setRotation(float const degrees);
	void setMass(float const newMass);
	

	virtual void Update( const Time &elapsedTime, const Vector2f gravity );
	virtual void Draw( sf::RenderWindow &w );

}; //end GameEntity class
#endif