#ifndef _GAME_ENTITY_
#define _GAME_ENTITY_

#import sfml_stuff

using namespace sf;

class GameEntity {
private:
	Vector2f m_position, m_velocity, m_scale;
	float m_angular_velocity, m_rotation_radians, m_mass;
	Sprite m_sprite;
public:
	GameEntity(Vector2f position, Vector2f velocity = 0, Vector2f scale = 0,
				float angularVel = 0, float rotation_radians = 0, float mass = 0);
	~GameEntity();
	
	//-- GET -------------------------
	Vector2f getPosition() const;
	Vector2f getVelocity() const;	//linear velocity
	Vector2f getScale() const;
	float getVelocityAngular() const;	//angular velocity
	float getRotation() const;	//radians
	float getMass() const;
	
	//-- SET -------------------------
	//void setPosition(Vector2f const &newPos);
	void setVelocity(Vector2f const &newVel);
	void setScale(Vector2f const &newScale);
	void setVelocityAngular(float const newVel);
	//float setRotation(float const radians);
	float setMass(float const newMass);
	
	void Update();
	void Draw(RenderWindow &w);
}; //end GameEntity class
#endif