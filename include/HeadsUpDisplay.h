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
		sf::Sprite m_sprite;
		bool m_isVisible;
		void Draw( RenderWindow &w ){if (m_isVisible) w.draw(m_sprite);}
		};//end of Element

	std::vector<Element> m_elements;

	static HeadsUpDisplay * m_instance;
	HeadsUpDisplay();

public:
	void addElement(sf::String name, sf::Sprite sprite, bool visible = true) {
		Element newElement;
		newElement.Name = name;
		newElement.m_sprite = sprite;
		newElement.m_isVisible = visible;
		m_elements.push_back(newElement);
	}
	static HeadsUpDisplay* instance() { return instance == NULL ? m_instance = new HeadsUpDisplay() : m_instance; }
};
#endif