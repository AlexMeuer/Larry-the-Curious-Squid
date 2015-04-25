#ifndef _GUI_H
#define _GUI_H

/** NOTE: tree.hh
\mainpage tree.hh
\author   Kasper Peeters
\version  2.81
\date     23-Aug-2011
\see      http://tree.phi-sci.com/
\see      http://tree.phi-sci.com/ChangeLog

The tree.hh library for C++ provides an STL-like container class
for n-ary trees, templated over the data stored at the
nodes. Various types of iterators are provided (post-order,
pre-order, and others). Where possible the access methods are
compatible with the STL or alternative algorithms are
available.
*/
#include "../tree.hh"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

struct GUI_Element {
	virtual void draw(sf::RenderWindow &w) = 0;
};

struct Button : GUI_Element{
	sf::Text text;
	sf::Sprite sprite;
	void(*onPress)(Button*);
	void(*onRelease)(Button*);
	void GUI_Element::draw(sf::RenderWindow &w) { w.draw(sprite); w.draw(text); }
};

struct Label : GUI_Element {
	sf::Text text;
	void(*onClick)(Label*);
	void GUI_Element::draw(sf::RenderWindow &w) { w.draw(text); }
};

// A graphical border element
class Frame : GUI_Element {
	sf::Sprite edge, corner;
	sf::Text title;
	//TODO:
	// - write the rest of this class
	// - draw method using only edge, corner, and brainpower
};

class GraphicalUserInterface {
private:
	GraphicalUserInterface();

public:
	~GraphicalUserInterface();
};
#endif