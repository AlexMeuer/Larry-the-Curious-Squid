#ifndef _HEADSUPDISPLAY_
#define _HEADSUPDISPLAY_

#include "SFML\Graphics.hpp"
#include "SceneManager.h"

using namespace sf;

class HeadsUpDisplay {
private:
	static HeadsUpDisplay *m_instance;
	HeadsUpDisplay() {}

	Font m_font;
	Color m_colour;

	Texture m_lifeSprite;	// image to represent lives lost
	Texture m_gravityArrow; // an arrow sprite pointing in the direction of the gravity for that level
	Vector2f m_lifePosition;
	Vector2f m_arrowPosition;

	int m_lives;
	
	//time on level?
	//total time played?
public:
	~HeadsUpDisplay() {}
	// if an instance of HeadsUpDisplay already exists, return a refernce to it
	static HeadsUpDisplay* instance() { return instance == NULL ? m_instance = new HeadsUpDisplay() : m_instance; }

	void Update();
	void Draw( sf::RenderWindow &w );
};
#endif