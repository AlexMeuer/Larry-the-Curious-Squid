#ifndef _MENU_FUNCS_H
#define _MENU_FUNCS_H

#include "SFML/Graphics.hpp"
#include "SceneManager.h"

//class for defining methods to be called when a menun item is selected. Intended to keep Raft.cpp cleaner.
class MenuFunctions
{
public:
	//Output to console the name of the item followed by "activated!"
	static void output(sf::String string) {
		cout << string.toAnsiString() << " activated!" << endl;
	}

	//Navigate to a scene (if one has been set up for the item)
	static void changeScene(sf::String string) {
		output(string);

		if(string == "Start")
			SceneManager::instance()->navigateToScene("LEVEL_1");

		else if(string == "Start FMOD DEMO")
			SceneManager::instance()->navigateToScene("FMOD_DEMO");

		else if(string == "Options")
			SceneManager::instance()->navigateToScene("OPTIONS_MENU");

		else if(string == "Back")
			SceneManager::instance()->navigateToScene("MAIN_MENU");

		else
			cout << "No suitable scene to change to!\nDid you set one up in MenuFunctions.h?"<< endl;
	}
};
#endif

