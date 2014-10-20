#include "..\include\Level.h"

int Level::getID() const {
	return id;
}

void Level::Update() {
	std::vector<GameEntity*>::iterator itr;

	//update all entities in vector
	for(itr = m_entities.begin();
		itr != m_entities.end();
		itr++)
	{
		(*itr)->Update();
	}
}

void Level::Draw(RenderWindow &w) {
	std::vector<GameEntity*>::iterator itr;

	//draw all entities in vector
	for(itr = m_entities.begin();
		itr != m_entities.end();
		itr++)
	{
		(*itr)->Draw(w);
	}
}

Level Level::LoadFromXML(String path) {
	//TODO: Tiny-XML-2
}