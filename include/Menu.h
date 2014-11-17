#ifndef _MENU_H
#define _MENU_H

#include "SFML\Graphics.hpp"
#include <vector>

using namespace sf;

//Vertical menu class. Does not currently support horizontal arbitrary layouts.
class Menu {
private:

	std::vector<Text> m_items;

	const int m_itemSpacing;

	std::vector<Text>::iterator m_selected;

	const Font m_font;

	//Vector2i m_position;

	Color m_mainColor, m_hiliteColor;

public:

	//creates a menu with one item
	Menu(String const &text, Font const &font, Vector2f position, Color mainColor = Color::White, Color hiliteColor = Color::Yellow, int item_Spacing = 10);

	//adds a text item to a menu.
	void addItem(String const &text);

	Text getItemAtIndex(unsigned int const index) const;

	Text moveUp();

	Text moveDown();

	void Draw(RenderWindow &w) const;

	Text getSelected() const;
	//Vector2i getPosition() const;
	Color getMainColor() const;
	Color getHiliteColor() const;

	//void setPosition( Vector2i const &newPos );
	void setMainColor( Color const &color );
	void setHiliteColor( Color const &color );
};
#endif