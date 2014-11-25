#include "Level.h"

int Level::getID() const {
	return id;
}

bool Level::handleEvent( Event &event ) {
	if ( event.type == Event::KeyPressed )
		if ( event.key.code == Keyboard::Escape )
			return true;

	return false;
}

void Level::update(Time const &elapsedTime) {
	std::vector<GameEntity*>::iterator itr;

	//update all entities in vector
	for(itr = m_entities.begin();
		itr != m_entities.end();
		itr++)
	{
		(*itr)->Update(elapsedTime, m_gravity);
	}
}

void Level::draw(RenderWindow &w) {
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
	return Level();
}