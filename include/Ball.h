#ifndef _BALL_
#define _BALL_

#include "GameEntity.h"


class Ball: public GameEntity {
private:
	const float coefficentOfRestitution = 0;//value decided later
	
public:
	Ball();
	~Ball();
	void Update();
}
#endif