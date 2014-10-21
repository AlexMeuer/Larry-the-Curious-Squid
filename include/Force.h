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
	
	void Apply(GameEntity * e) const;
};
#endif