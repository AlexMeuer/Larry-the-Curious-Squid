#ifndef _GAME_ENTITY_
#define _GAME_ENTITY_

#include "SFML\Graphics.hpp"

using namespace sf;

class GameEntity {
protected:
	Vector2f m_position, m_velocity, m_scale;

	float m_angular_velocity, m_rotation_degrees, m_mass;

	Sprite m_sprite;

	sf::ConvexShape shape;

public:
	GameEntity(Texture *texture, Vector2f position,
		float angularVel = 0, float rotation_degrees = 0, float mass = 0);
	~GameEntity();
	
	//-- GET -------------------------
	Vector2f getPosition() const;
	Vector2f getVelocity() const;	//linear velocity
	float getVelocityAngular() const;	//angular velocity
	float getRotation() const;	//degrees
	float getMass() const;
	
	//-- SET -------------------------
	void setPosition(Vector2f const &newPos);
	void setVelocity(Vector2f const &newVel);
	void setVelocityAngular(float const newVel);
	void setRotation(float const degrees);
	void setMass(float const newMass);
	

	virtual void Update();
	virtual void Draw(RenderWindow &w);

}; //end GameEntity class
#endif