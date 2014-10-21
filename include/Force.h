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
	Force(Vector2f position = Vector2f(0,0), float power = 0);
	~Force();
	
	void Apply(GameEntity * e) const;
};
#endif