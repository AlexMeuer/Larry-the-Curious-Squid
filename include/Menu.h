#ifndef _MENU_H
#define _MENU_H

#include "SFML\Graphics.hpp"
#include <vector>

using namespace sf;

class Menu {
private:

	std::vector<Text> items;
	const unsigned int itemSpacing;

public:

	//creates an empty menu
	Menu(unsigned int item_Spacing = 10);

	//adds a text item to a menu
	void addItem(Text const &item);

	Text getItemAtIndex(unsigned int const index) const;

};
#endif