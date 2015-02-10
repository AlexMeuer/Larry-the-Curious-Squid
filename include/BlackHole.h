#ifndef _BLACKHOLE_
#define _BLACKHOLE_

#include "GameEntity.h"
#include "Force.h"
#include <string>

class BlackHole: public GameEntity {
private:
	//Force m_force;
	std::string m_targetScene;
public:
	BlackHole(std::string targetScene, Texture* texture, Vector2f position, Vector2f velocity = Vector2f(0, 0), Vector2f scale = Vector2f(1, 1), float angularVel = 0, float rotation_degrees = 0, float mass = 1);

	~BlackHole();

	std::string getNextScene() const;

	void Update( Time const &elapsedTime, GameEntity* entity );
};

#endif