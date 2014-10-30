#ifndef _POWERUP_
#define _POWERUP_

#include "GameEntity.h"


class PowerUp {
private:
	//const enum Effect = "Grow";//value decided later

public:
	void Apply(GameEntity * e);
};
#endif