// Raft.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#include "include\Force.h"
//#include "include\Level.h"
//#include "include\Ball.h"
#include "include\Menu.h"
#include "include\SceneManager.h"
#include "include\Block.h"
#include "include\BlackHole.h"
#include "include\CollisionManager.h"
#include "include\HeadsUpDisplay.h"

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

//#include "SFML/Graphics.hpp"
//#include "SFML/OpenGL.hpp"
#include <iostream>
//#define _USE_MATH_DEFINES
//#include <math.h> 

//#include <windows.h>

#include "include\MenuFunctions.h"

//FMOD includes
#pragma comment(lib,"fmodex_vc.lib")
#include "fmod.hpp"
#include "fmod_errors.h"

void testFunc(sf::String string) {
	if (string == "START")
		SceneManager::instance()->navigateToScene("OPTIONS_MENU");

	//std::cout << string.toAnsiString() << " activated!" << std::endl;
	else if (SceneManager::instance()->getCurrentScene() == "MAIN_MENU") {
		SceneManager::instance()->navigateToScene("OPTIONS_MENU");
	}
	else if (SceneManager::instance()->getCurrentScene() == "OPTIONS_MENU") {
		SceneManager::instance()->navigateToScene("MAIN_MENU");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

#pragma region Setup_Scenes
	Font menuFont = Font();
	menuFont.loadFromFile("res/font/kenvector_future.ttf");

	//Create our main menu scene and add items to that scene. Each item takes a function pointer that will be called when the item is selected.
	SceneManager::instance()->createScene("MAIN_MENU", new Menu("Start", menuFont, MenuFunctions::changeScene, sf::Vector2f(100, 200)));

	Menu* menu = dynamic_cast<Menu*>(SceneManager::instance()->getEditableScene());
	menu->addItem("Load",  MenuFunctions::changeScene);
	menu->addItem("Options",  MenuFunctions::changeScene);
	menu->addItem("Exit", MenuFunctions::exitProgram);

	//Create our options menu scene and populate it.
	SceneManager::instance()->createScene("OPTIONS_MENU", new Menu("Graphics", menuFont, MenuFunctions::output, sf::Vector2f(100, 200)));

	menu = dynamic_cast<Menu*>(SceneManager::instance()->getEditableScene());
	menu->addItem("Audio", MenuFunctions::output);
	menu->addItem("Controls", MenuFunctions::output);
	menu->addItem("Back", MenuFunctions::changeScene);


	//Create our first level scene from an xml file
	SceneManager::instance()->createScene("LEVEL_1", Level::LoadFromXML("res/xml/test.xml"));

	SceneManager::instance()->navigateToScene("MAIN_MENU");
#pragma endregion


#pragma region Setup_FMOD
	//setup FMOD
	FMOD::System *FMODsys; //will point to the FMOD system
	FMOD_RESULT result;
	result = FMOD::System_Create(&FMODsys);         // Create the main system object.
	if (result != FMOD_OK)
	{
		std::cout << "FMOD error!" <<result << FMOD_ErrorString(result);
		exit(-1);
	}



	result = FMODsys->init(100, FMOD_INIT_NORMAL, 0);   // Initialize FMOD.



	if (result != FMOD_OK)

	{

		std::cout << "FMOD error!" << result << FMOD_ErrorString(result);

		exit(-1);

	}  
#pragma endregion


	//create a sound with FMOD
	FMOD::Sound *sound;

	result = FMODsys->createSound(
		"res/mus/Ove - Earth Is All We Have 1.ogg",
		FMOD_DEFAULT,
		0,
		&sound);

	if (result != FMOD_OK)
	{
		std::cout << "FMOD error! (%d) %s\n" << result;
		exit(-1);
	}

	//play a sound with a channel (updateable, looping, etc)
	FMOD::Channel *channel;
	FMODsys->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
	channel->set3DMinMaxDistance(10, 500);	//below min, sound wont get any louder. after max, sound is not audible.
	channel->setMode(FMOD_LOOP_NORMAL);

	//play a sound without a channel (not updateable, one-shot, etc)
	//FMODsys->playSound(
 //   FMOD_CHANNEL_FREE, //find a free channel
 //   sound,                  // sound to play
 //   true,              //start playing/paused
 //   0);                 //channel reference
	
	 // Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Test Scenario"); 
	sf::Clock clock = Clock();
	sf::Time elapsedTime;

	//Level myLevel = Level::LoadFromXML("res/xml/test.xml");
	//CollisionManager collisionManager;

	//load textures
	sf::Texture ballTex;
	ballTex.loadFromFile("res/img/ball.png");
	sf::Texture blockTex;
	blockTex.loadFromFile("res/img/Block.png");
	sf::Texture blackholeTex;
	blackholeTex.loadFromFile("res/img/Blackhole.png");
	
	//create an instance of ball
	//Ball ball(&ballTex, Vector2f(300, 0), Vector2f(0,0), Vector2f(0.1,0.1));

	std::vector<Block*> crystalChandelier;
	
	//BlackHole blackHole(&blackholeTex, Vector2f(500, 400));

	/*for (int i = 0; i < 10; i ++ ) {
		crystalChandelier.push_back(new Block(&blockTex, Vector2f(i * 50,567), Vector2f(0,0), Vector2f(1,1)));
	}*/
	
	//create an instance of force
	//Force force(Vector2f(250, 400), 200);
	
	 // Start game loop
	while (window.isOpen()){

		// Process events
		sf::Event Event;
		while (window.pollEvent(Event)){

			switch ( Event.type ) {

			// Close window : exit
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				SceneManager::instance()->passEventToCurrentScene(Event);
				break;

			default:
				break;
			}//end switch
		}//end while
					
		//FMODsys->set3DListenerAttributes(0, ball.getFMOD_POS(), ball.getFMOD_VEL(), 0, 0);
		FMODsys->update();	//run this once per frame ONLY


		elapsedTime = clock.getElapsedTime();
		
		SceneManager::instance()->updateCurrentScene( elapsedTime);
		
		//if(CollisionManager::instance()->OffScreen(window, &ball))
		//	ball.Death_Reset();
			
		//for (int i = 0; i < 10; i++)
		//{
		//	CollisionManager::instance()->SquareCircle(&crystalChandelier[i]->getSprite(),&ball);
		//}

		//myLevel.update(elapsedTime);

		//prepare frame
		window.clear();
	

		//myLevel.draw( window );

		//blackHole.Update();

		/*if ( Mouse::isButtonPressed(Mouse::Button::Left) ) {
			force.setPower( 200 );
			force.setPosition( Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y) );
		}
		else {
			force.setPower( 10 );
		}*/

		//prepare frame
		window.clear();

		SceneManager::instance()->drawCurrentScene( window );
		
		//ball.Draw(window);
		
		/*for ( int i = 0; i < 10; i ++ ) {
			crystalChandelier[i]->Draw(window);
		}*/
		
		//blackHole.Draw(window);

		// Finally, display rendered frame on screen
		window.display();
		clock.restart();
	} //loop back for next frame

	return EXIT_SUCCESS;

}
// This comment is False
