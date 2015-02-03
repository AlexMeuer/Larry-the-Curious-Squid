#include "../include/HeadsUpDisplay.h"

HeadsUpDisplay* HeadsUpDisplay::m_instance = NULL;

void HeadsUpDisplay::lifeLost() {
	m_livesLost = m_livesLost + 1;
	if (m_livesLost == 4)  
		m_livesLost = 0;
}

void HeadsUpDisplay::Update( Time const &elapsedTime ) {
	
}

void HeadsUpDisplay::Draw( RenderWindow &w ) {
	//these variables need to be in the header. file io should be in constructor.
	//sf::Texture lifeTex;
	//lifeTex.loadFromFile("res/img/life.png");
	//Life tempLife(&lifeTex, Vector2f(20, 300));
	//tempLife.Draw(w);
}
