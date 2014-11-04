#ifndef _LEVEL_
#define _LEVEL_

#include <vector>
#include "SFML\Graphics.hpp"
#include "GameEntity.h"
#include "Force.h"

class Level {
private:

	std::vector<GameEntity*> m_entities;

	Vector2f m_gravity;

	int id;
	
public:

	Level() : id(-1), m_gravity(Vector2f(0,0)) {}
	~Level() {}

	int getID() const;
	
	void Update(Time elapsedTime);
	void Draw(RenderWindow &w);

	static Level LoadFromXML(String path);
};
#endif