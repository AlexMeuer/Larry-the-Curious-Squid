#include "../include/Level.h"
#include "../include/tinyxml2.h"

using namespace tinyxml2;

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

Level Level::LoadFromXML(const char *path) {
	XMLDocument doc;
	doc.LoadFile(path);

	//TODO:
	//	read values from xml and and create objects with them

	return Level();
}