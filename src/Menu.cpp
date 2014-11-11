#include "../include/Menu.h"

Menu::Menu(unsigned int item_spacing) : itemSpacing( item_spacing ) {
	//empty body
}

void Menu::addItem(Text const &item) {
	items.push_back(item);
}

Text Menu::getItemAtIndex(unsigned int const index) const {
	return items.at(index);
}