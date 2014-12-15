#include "../include/HeadsUpDisplay.h"

HeadsUpDisplay* HeadsUpDisplay::m_instance = NULL;

//	void Update();
//	void Draw( sf::RenderWindow &w );



void HeadsUpDisplay::Update() {

}

void HeadsUpDisplay::Draw( RenderWindow &w ) {
	m_lifeSprite.loadFromFile("life.png");	// want to change the colour

}