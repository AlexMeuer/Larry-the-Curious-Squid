#include "../include/Menu.h"

Menu::Menu(String const &text, Font const &font, Vector2f position, Color mainColor, Color hiliteColor, int item_spacing)
	: m_itemSpacing( item_spacing ), m_font( font ), m_mainColor( mainColor ), m_hiliteColor( hiliteColor ) {

	//push first item onto list and initialise selected iterator
	m_items.push_back( Text( text, font ) );
	m_selected = m_items.begin();

	m_selected->setPosition( position );
	m_selected->setColor( hiliteColor );
}

void Menu::addItem(String const &text) {
	m_items.push_back( Text( text, m_font ) );

	auto thisItem = m_items.rbegin();
	auto lastItem = thisItem + 1;
	
	//place this item below the last item
	thisItem->setPosition( lastItem->getPosition().x, lastItem->getPosition().y + lastItem->getCharacterSize() + m_itemSpacing);

	m_selected = m_items.begin();
}

Text Menu::getItemAtIndex(unsigned int const index) const {
	return m_items.at(index);
}

Text Menu::moveDown() {
	m_selected->setColor( m_mainColor );

	//move to top of list if trying to move past bottom
	if( ++m_selected == m_items.end() )
		m_selected = m_items.begin();

	m_selected->setColor( m_hiliteColor );

	return *m_selected;
}

Text Menu::moveUp() {
	m_selected->setColor( m_mainColor );

	//move to bottom of list if trying to move past top
	if ( m_selected == m_items.begin() )
		m_selected = m_items.end();

	m_selected--;

	m_selected->setColor( m_hiliteColor );

	return *m_selected;
}

Text Menu::getSelected() const {
	return *m_selected;
}

void Menu::Draw( RenderWindow &w ) const {
	for( auto itr = m_items.begin();
		itr != m_items.end();
		itr++ )
	{
		w.draw( *itr );
	}
}

//Vector2i Menu::getPosition() const {
//	return m_position;
//}

Color Menu::getMainColor() const {
	return m_mainColor;
}

Color Menu::getHiliteColor() const {
	return m_hiliteColor;
}

//void Menu::setPosition( Vector2i const &newPos ) {
//	m_position = newPos;
//}

void Menu::setMainColor( Color const &color ) {
	m_mainColor = color;
}

void Menu::setHiliteColor( Color const &color) {
	m_hiliteColor = color;
}