#ifndef _FORCE_
#define _FORCE_

#include "GameEntity.h"

class Force {
private:
	Vector2f m_position;
	float m_power;
	//fall-off
public:
	Force(Vector2f position, float power);
	~Force();
	
	Apply(GameEntity * e) const;
}
#endif