// Raft.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "include\Force.h"
#include "include\Level.h"
#include "include\Ball.h"
#include "include\Block.h"
#include "include\BlackHole.h"
#include "include\CollisionManager.h"

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
	CollisionManager collisionManager;


	//load textures
	sf::Texture ballTex;
	ballTex.loadFromFile("res/img/ball.png");
	sf::Texture blockTex;
	blockTex.loadFromFile("res/img/Block.png");
	sf::Texture blackholeTex;
	blackholeTex.loadFromFile("res/img/Blackhole.png");
	//create an instance of ball

	Ball ball(&ballTex, Vector2f(300, 0), Vector2f(0,0), Vector2f(0.1,0.1));

	std::vector<Block*> crystalChandelier;

	BlackHole blackHole(&blackholeTex, Vector2f(500, 400));

	for (int i = 0; i < 10; i ++ ) {
		crystalChandelier.push_back(new Block(&blockTex, Vector2f(i * 50,567), Vector2f(0,0), Vector2f(1,1)));
	}
	
	//create an instance of force
	Force force(Vector2f(250, 400), 200);
	
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

		if(collisionManager.OffScreen(window, &ball))
			ball.Death_Reset();
		for (int i = 0; i < 10; i++)
		{
			collisionManager.SquareCircle(&crystalChandelier[i]->getSprite(),&ball);
		}

		blackHole.Update();

		if ( Mouse::isButtonPressed(Mouse::Button::Left) ) {
			force.setPower( 200 );
			force.setPosition( Vector2f(Mouse::getPosition().x - window.getPosition().x, Mouse::getPosition().y  - window.getPosition().y) );
		}
		else {
			force.setPower( 10 );
		}

		force.Apply(&ball, elapsedTime);

		//prepare frame
		window.clear();

		//draw the area affected by the test force
		CircleShape shape = CircleShape(force.getPower());
		shape.setPosition(force.getPosition().x - force.getPower(), force.getPosition().y - force.getPower());
		shape.setFillColor(Color::Red);
		window.draw(shape);

		
		ball.Draw(window);
		for ( int i = 0; i < 10; i ++ ) {
			crystalChandelier[i]->Draw(window);
		}
		blackHole.Draw(window);

		// Finally, display rendered frame on screen
		window.display();
		clock.restart();
	} //loop back for next frame

	return EXIT_SUCCESS;

}
// This comment is False
