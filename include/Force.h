#ifndef _FORCE_
#define _FORCE_

#include "SFML\Graphics.hpp"
#include "GameEntity.h"

class Force {
private:
	Vector2f m_position;
	float m_power;
	//fall-off implementation?
public:
	Force(Vector2f position, float power) : m_position(position), m_power(power) {}
	~Force() {}

	void Apply(GameEntity * e, Time elapsedTime) const;

	float getPower() const;
	Vector2f getPosition() const;

	void setPower(float const newPower);
	void setPosition(Vector2f const &newPos);
};
#endif