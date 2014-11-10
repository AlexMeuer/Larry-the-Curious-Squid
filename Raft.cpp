// Raft.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "include\Force.h"
#include "include\Level.h"
#include "include\Ball.h"



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
//#include <iostream>
//#define _USE_MATH_DEFINES
//#include <math.h> 

#include <windows.h>



int _tmain(int argc, _TCHAR* argv[])
{
	
	 // Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Test Scenario"); 
	sf::Clock clock = Clock();
	sf::Time elapsedTime;


	//load textures
	sf::Texture ballTex;
	ballTex.loadFromFile("res/img/ball.png");
	
	//create an instance of ball

	Ball ball(&ballTex, Vector2f(300, 0), Vector2f(0,0), Vector2f(0.1,0.1));


	//create an instance of force
	Force force(Vector2f(250, 400), 100);
	
	 // Start game loop
	while (window.isOpen()){
		// Process events
		sf::Event Event;
		while (window.pollEvent(Event)){
			// Close window : exit
			if (Event.type == sf::Event::Closed)
			window.close();
			// Escape key : exit
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
			window.close();
		}

		elapsedTime = clock.getElapsedTime();

		ball.Update(elapsedTime, Vector2f(0,9.81));

#ifdef _DEBUG
		force.Apply(&ball, window);
#else
		force.Apply(&ball);
#endif

		//prepare frame
		window.clear();
		
		ball.Draw(window);

		
		// Finally, display rendered frame on screen
		window.display();
		clock.restart();
	} //loop back for next frame

	return EXIT_SUCCESS;

}
// This comment is False
