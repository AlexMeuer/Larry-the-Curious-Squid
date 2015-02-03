#ifndef _HEADSUPDISPLAY_
#define _HEADSUPDISPLAY_

#include "SFML\Graphics.hpp"
#include "SceneManager.h"
#include <vector>

using namespace sf;

class HeadsUpDisplay {
private:
	static HeadsUpDisplay *m_instance;
	HeadsUpDisplay() {}

	Texture m_gravityArrow; // an arrow sprite pointing in the direction of the gravity for that level
	Vector2f m_arrowPosition;

	int m_livesLost;
	
public:
	~HeadsUpDisplay() {}
	
	static HeadsUpDisplay* instance() { return instance == NULL ? m_instance = new HeadsUpDisplay() : m_instance; }
	
	void lifeLost();
	void Update( Time const &elapsedTime );
	void Draw( sf::RenderWindow &w );
};
#endif