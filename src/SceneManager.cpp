#include "../include/SceneManager.h"

SceneManager* SceneManager::m_instance = NULL;

SceneManager* SceneManager::instance() {
	if ( m_instance == NULL ) {
		m_instance = new SceneManager();
	}

	return m_instance;
}

const string SceneManager::getCurrentScene() const {
	return currentScene;
}

//calls the current scene's update method
void SceneManager::updateCurrentScene( sf::Time const &elapsedTime ) {
	m_scenes[ currentScene ]->update( elapsedTime );
}

//calls the current scene's draw method
void SceneManager::drawCurrentScene( sf::RenderWindow &w ) {
	m_scenes[ currentScene ]->draw( w );
}

//returns true if no further processing should be done for the event (i.e. the event has been used up )
bool SceneManager::passEventToCurrentScene( sf::Event &theEvent ) {
	return m_scenes[ currentScene ]->handleEvent( theEvent );
}