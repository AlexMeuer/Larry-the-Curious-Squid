#include "FMOD_DEMO.h"

FMOD_DEMO::FMOD_DEMO( Vector2f reverbCentre, FMOD::System* sys ) : listenerTex(), reverbArea(100), fmod_sys(sys) {
	//load texture for listener
	listenerTex.loadFromFile("./res/img/listener.png");

	listener = Sprite(listenerTex);

	//set listener origin to centre of sprite
	listener.setOrigin( listenerTex.getSize().x / 2.0f, listenerTex.getSize().y / 2.0f);

	//set reverbArea origin to centre of circle
	reverbArea.setOrigin( reverbArea.getRadius(), reverbArea.getRadius() );

	//show only the outline
	reverbArea.setOutlineColor( Color::Green );
	reverbArea.setOutlineThickness(5);
	reverbArea.setFillColor( Color::Transparent );

	reverbArea.setPosition( reverbCentre );

	listenerPos = new FMOD_VECTOR();
	listenerPos->z = 0;
	listenerVel = new FMOD_VECTOR();
	listenerVel->z = 0;
}

FMOD_DEMO::~FMOD_DEMO() {
}

bool FMOD_DEMO::handleEvent( Event &Event ) {
	bool handled = false;

	//update fmod listener velocity
	listenerVel->x = listenerPos->x - listener.getPosition().x;
	listenerVel->y = listenerPos->y - listener.getPosition().y;
	
	//update fmod lister position
	listenerPos->x = listener.getPosition().x;
	listenerPos->y = listener.getPosition().y;

	//if click, play sound effect and return true



	return handled;
}

void FMOD_DEMO::update( Time const &ElapsedTime ) {
}

void FMOD_DEMO::draw( RenderWindow &w ) {
	//bind the listener's position to the mouse
	listener.setPosition( Mouse::getPosition(w).x, Mouse::getPosition(w).y );

	w.draw( reverbArea );
	w.draw( listener );
}