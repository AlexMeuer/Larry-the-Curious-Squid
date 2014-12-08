#ifndef _SCENE_H
#define _SCENE_H

#include "SFML\Graphics.hpp"

//I_Scene derivatives should never be instantiated outside of SceneManager class
class I_Scene {
public:
	//void (*dispose)(std::string);	//pointer to function that will destroy an I_Scene instance (allows I_Scene derivatives to ask for deletion)
	//std::string name;

	//returns true if the event has been processed and no further handling is needed
	virtual bool handleEvent( sf::Event &Event ) = 0;

	virtual void update( sf::Time const &elapsedTime ) = 0;

	virtual void draw( sf::RenderWindow &w ) = 0;

	virtual ~I_Scene() {}
};
#endif

