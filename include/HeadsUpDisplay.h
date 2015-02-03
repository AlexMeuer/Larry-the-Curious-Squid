#ifndef _HEADSUPDISPLAY_
#define _HEADSUPDISPLAY_

#include "SFML\Graphics.hpp"
#include "SceneManager.h"
#include <vector>

using namespace sf;

class HeadsUpDisplay {
private:
	struct Element {
		sf::String Name;
		sf::Sprite Sprite;
		bool IsVisible;
		void Draw( RenderWindow &w ) {
			if (IsVisible) 
				w.draw(Sprite);
		}
	};

	std::vector<Element> m_elements;
	static HeadsUpDisplay *m_instance;
	//HeadsUpDisplay() {}
public:
	//~HeadsUpDisplay() {}
	bool addElement( sf::String name, sf::Sprite sprite, float x, float y, bool visible = true );
	static HeadsUpDisplay* instance() { return instance == NULL ? m_instance = new HeadsUpDisplay() : m_instance; }
};
#endif