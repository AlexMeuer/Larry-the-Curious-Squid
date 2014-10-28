// Raft.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "include\Force.h"
#include "include\Level.h"
#include "include\Ball.h"



//Ken's Includes
#include "stdafx.h"
#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h> 

//get game time
#include <windows.h>



int _tmain(int argc, _TCHAR* argv[])
{
	
	 // Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Test Senario"); 
	DWORD time;

<<<<<<< HEAD
	//Ball ball(NULL, Vector2f(100,0), 1,
=======

	Ball ball; //**
>>>>>>> 437a3b48b3814e0bc27b93595eef20f2983696b0
	
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

		//ball.Update();

		//prepare frame
		window.clear();
<<<<<<< HEAD
		time = GetTickCount();
		//ball::update(
=======
		
		ball.Draw(window);
>>>>>>> 437a3b48b3814e0bc27b93595eef20f2983696b0
		
		// Finally, display rendered frame on screen
		window.display();
	} //loop back for next frame

	return EXIT_SUCCESS;

}
// This comment is False
