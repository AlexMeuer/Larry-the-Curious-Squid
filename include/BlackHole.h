#ifndef _BLACKHOLE_
#define _BLACKHOLE_

#include "GameEntity.h"
#include "Force.h"

class BlackHole: public GameEntity {
private:
	Force m_force;
};

#endif