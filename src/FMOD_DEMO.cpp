#include "FMOD_DEMO.h"

FMOD_DEMO::FMOD_DEMO( Vector2f reverbCentre, Vector2f emitterCentre, FMOD::System* sys ) : listenerTex(), emitterTex(), reverbArea(100), fmod_sys(sys) {
	//load textures
	listenerTex.loadFromFile("./res/img/listener.png");
	emitterTex.loadFromFile("./res/img/speaker.png");

	listener = Sprite(listenerTex);
	emitter = Sprite(emitterTex);

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

	//create a sound with FMOD
	bool result = fmod_sys->createSound(
		"res/mus/sound.ogg",
		FMOD_DEFAULT,
		0,
		&sound);

	if (result != FMOD_OK)
	{
		std::cout << "FMOD error! (%d) %s\n" << result;
		exit(-1);
	}
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
	if(Event.type == sf::Event::EventType::MouseButtonPressed) {

		//play a sound without a channel (not updateable, one-shot, etc)
		fmod_sys->playSound(
		FMOD_CHANNEL_FREE, //find a free channel
		sound,                  // sound to play
		true,              //start playing/paused
		0);                 //channel reference

		handled = true;
	}

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