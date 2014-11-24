// Raft.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#include "include\Force.h"
//#include "include\Level.h"
//#include "include\Ball.h"
#include "include\Menu.h"
#include "include\SceneManager.h"



//Ken's Includes
//#include "stdafx.h"
//#ifdef _DEBUG
//#pragma comment(lib,"sfml-graphics-d.lib")
//#pragma comment(lib,"sfml-audio-d.lib")
//#pragma comment(lib,"sfml-system-d.lib")
//#pragma comment(lib,"sfml-window-d.lib")
//#pragma comment(lib,"sfml-network-d.lib")
//#else
//#pragma comment(lib,"sfml-graphics.lib")
//#pragma comment(lib,"sfml-audio.lib")
//#pragma comment(lib,"sfml-system.lib")
//#pragma comment(lib,"sfml-window.lib")
//#pragma comment(lib,"sfml-network.lib")
//#endif
//#pragma comment(lib,"opengl32.lib")
//#pragma comment(lib,"glu32.lib")
#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include <iostream>
//#define _USE_MATH_DEFINES
//#include <math.h> 

#include <windows.h>

void testFunc(sf::String string) {
	//std::cout << string.toAnsiString() << " activated!" << std::endl;
	if (SceneManager::instance()->getCurrentScene() == "MAIN_MENU") {
		SceneManager::instance()->navigateToScene("OPTIONS_MENU");
	}
	else if (SceneManager::instance()->getCurrentScene() == "OPTIONS_MENU") {
		SceneManager::instance()->navigateToScene("MAIN_MENU");
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	Font menuFont = Font();
	menuFont.loadFromFile("res/font/kenvector_future.ttf");

	SceneManager::instance()->createScene("MAIN_MENU", new Menu("Start", menuFont, testFunc, sf::Vector2f(100, 200)));

	Menu* menu = dynamic_cast<Menu*>(SceneManager::instance()->getEditableScene());
	menu->addItem("Load", testFunc);
	menu->addItem("Options", testFunc);
	menu->addItem("Exit", testFunc);

	SceneManager::instance()->createScene("OPTIONS_MENU", new Menu("Graphics", menuFont, testFunc, sf::Vector2f(100, 200)));

	menu = dynamic_cast<Menu*>(SceneManager::instance()->getEditableScene());
	menu->addItem("Audio", testFunc);
	menu->addItem("Controls", testFunc);
	menu->addItem("Back", testFunc);

	SceneManager::instance()->navigateToScene("MAIN_MENU");


	 // Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Test Scenario"); 
	sf::Clock clock = Clock();
	sf::Time elapsedTime;

	 // Start game loop
	while (window.isOpen()){

		// Process events
		sf::Event Event;
		while (window.pollEvent(Event)){

			SceneManager::instance()->passEventToCurrentScene(Event);

			switch ( Event.type ) {

			// Close window : exit
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}//end switch
		}//end while


		elapsedTime = clock.getElapsedTime();
		SceneManager::instance()->updateCurrentScene( elapsedTime );

		//prepare frame
		window.clear();

		SceneManager::instance()->drawCurrentScene( window );
		
		// Finally, display rendered frame on screen
		window.display();
		clock.restart();
	} //loop back for next frame

	return EXIT_SUCCESS;

}
// This comment is False
