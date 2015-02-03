#include "../include/HeadsUpDisplay.h"

HeadsUpDisplay* HeadsUpDisplay::m_instance = NULL;

bool HeadsUpDisplay::addElement( sf::String name, sf::Sprite sprite, float x, float y, bool visible ) {
	Element newElement;
	newElement.Name = name;
	newElement.Sprite = sprite;
	newElement.Sprite.setPosition(x,y);
	newElement.IsVisible = visible;
	m_elements.push_back(newElement);
	for (int i = 0; i < m_elements.size(); i ++ ) {
		if ( name == m_elements[i].Name)
			return true;
		else
			return false;
	}
}