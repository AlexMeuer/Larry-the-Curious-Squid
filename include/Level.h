#ifndef _LEVEL_
#define _LEVEL_

#include <vector>
#include "SFML\Graphics.hpp"
#include "GameEntity.h"
#include "Force.h"
#include "Ball.h"
#include "Scene.h"

class Level : public I_Scene{
private:

	std::vector<GameEntity*> m_entities;

	Vector2f m_gravity;

	int id;
	
public:

	Level(Texture ballTex);
	~Level() {
		//delete the vector of pointers and avoid a memory leak
		while ( !m_entities.empty() ) { delete m_entities.back(); m_entities.pop_back(); }

		I_Scene::~I_Scene();
	}

	int getID() const;
	
	bool I_Scene::handleEvent( Event &Event );
	void I_Scene::update(Time const &elapsedTime);
	void I_Scene::draw(RenderWindow &w);

	static Level LoadFromXML(String path);
};
#endif