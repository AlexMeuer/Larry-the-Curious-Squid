#include "../include/Menu.h"

Menu::Menu(Text item, int item_spacing) : itemSpacing( item_spacing ) {
	items.push_back( item );
	selected = items.begin();
}

void Menu::addItem(Text const &item) {
	items.push_back(item);

	int thisItem, lastItem;
	thisItem = items.size() - 1;
	lastItem = thisItem - 1;
	
	//TODO: account for text/font scale
	items[thisItem].setPosition( items[lastItem].getPosition().x, items[lastItem].getPosition().y + itemSpacing);
}

Text Menu::getItemAtIndex(unsigned int const index) const {
	return items.at(index);
}

Text Menu::moveDown() {
	selected->setStyle( Text::Regular );

	if( ++selected == items.end() )
		selected = items.begin();

	selected->setStyle( Text::Bold );

	return *selected;
}

Text Menu::moveUp() {
	selected->setStyle( Text::Regular );

	if ( selected == items.begin() )
		selected-- = items.end();

	selected->setStyle( Text::Bold );

	return *selected;
}

Text Menu::getSelected() const {
	return *selected;
}

void Menu::Draw( RenderWindow &w ) const {
	for( auto itr = items.begin();
		itr != items.end();
		itr++ )
	{
		w.draw( *itr );
	}
}