#ifndef _LEVEL_EDITOR_H
#define _LEVEL_EDITOR_H

#include "../Scene.h"
#include "../Level.h"

//SINGLETON
class LevelEditor : public I_Scene {
private:

	static LevelEditor* m_instance;

	//Private because LevelEditor is a singleton
	LevelEditor();

	//returns false if operation failed
	bool newLevel(std::string const &path);
	bool saveLevel(std::string const &path);
	bool openLevel(std::string const &path);
	bool deleteLevel(bool askForConfirmation = true);

	//opens the custom levels folder in explorer
	bool openCustomLevelFolder();

	//the level being edited
	Level currentLevel;
public:
	~LevelEditor();

	static LevelEditor* instance();

#pragma region I_SCENE
	//returns true if the event has been processed and no further handling is needed
	bool I_Scene::handleEvent(sf::Event &Event);

	void I_Scene::update(sf::Time const &elapsedTime);

	void I_Scene::draw(sf::RenderWindow &w);
#pragma endregion

#pragma region GET/SET
#pragma endregion


};
#endif