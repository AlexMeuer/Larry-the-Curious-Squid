#ifndef _MENU_H
#define _MENU_H

#include "SFML\Graphics.hpp"
#include <vector>

using namespace sf;

class Menu {
private:

	std::vector<Text> items;
	const int itemSpacing;
	std::vector<Text>::iterator selected;

public:

	//creates a menu with one item
	Menu(Text item, int item_Spacing = 10);

	//adds a text item to a menu
	void addItem(Text const &item);

	Text getItemAtIndex(unsigned int const index) const;

	Text moveUp();

	Text moveDown();

	Text getSelected() const;

	void Draw(RenderWindow &w) const;
};
#endif