#include "FMOD_DEMO.h"

FMOD_DEMO::FMOD_DEMO( Vector2f reverbCentre, Vector2f emitterCentre, FMOD::System* sys ) : listenerTex(), emitterTex(), reverbArea(100), fmod_sys(sys) {
	//load textures
	listenerTex.loadFromFile("./res/img/listener.png");
	emitterTex.loadFromFile("./res/img/speaker.png");

	listener = Sprite(listenerTex);
	emitter = Sprite(emitterTex);

	//set listener origin to centre of sprite
	listener.setOrigin( listenerTex.getSize().x / 2.0f, listenerTex.getSize().y / 2.0f);

	emitter.setOrigin( emitterTex.getSize().x / 2.0f, listenerTex.getSize().y / 2.0f );

	emitter.setPosition( emitterCentre );

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

	emitterPos = new FMOD_VECTOR();
	emitterPos->z = 0;
	emitterVel = new FMOD_VECTOR();
	emitterVel->z = 0;
	emitterVel->x = 0;
	emitterVel->y = 0;

	dronePos = new FMOD_VECTOR();
	dronePos->z = 0;
	dronePos->x = 0;
	dronePos->y = 0;

	droneVel = new FMOD_VECTOR();
	droneVel->z = 0;
	droneVel->x = 0;
	droneVel->y = 0;

	//create a sound with FMOD
	bool result = fmod_sys->createSound(
		"res/sfx/laser1.wav",
		FMOD_SOFTWARE | FMOD_LOOP_OFF | FMOD_3D,
		0,
		&sound);

	if (result != FMOD_OK)
	{
		std::cout << "FMOD error! (%d) %s\n" << result;
		exit(-1);
	}

	result = fmod_sys->createSound(
		"res/mus/Ove - Earth Is All We Have 1.ogg",
		FMOD_SOFTWARE | FMOD_LOOP_NORMAL | FMOD_3D,
		0,
		&drone);

	if (result != FMOD_OK)
	{
		std::cout << "FMOD error! (%d) %s\n" << result;
		exit(-1);
	}

	//play a sound with a channel (updateable, looping, etc)
	fmod_sys->playSound(FMOD_CHANNEL_FREE, drone, true, &droneChannel);
	droneChannel->set3DMinMaxDistance(10, 500);	//below min, sound wont get any louder. after max, sound is not audible.

	//prop1 = FMOD_PRESET_MOUNTAINS;
	//fmod_sys->setReverbAmbientProperties(&prop1);
}

FMOD_DEMO::~FMOD_DEMO() {
	delete sound;
	delete drone;
	delete emitterChannel;
	delete droneChannel;
	delete listenerPos;
	delete listenerVel;
	delete emitterPos;
	delete emitterVel;
	delete dronePos;
	delete droneVel;
}

bool FMOD_DEMO::handleEvent( Event &Event ) {
	bool handled = false;

	//update fmod listener velocity
	listenerVel->x = listener.getPosition().x - listenerPos->x;
	listenerVel->y = listener.getPosition().y - listenerPos->y;
	
	//update fmod lister position
	listenerPos->x = listener.getPosition().x;
	listenerPos->y = listener.getPosition().y;

	emitterPos->x = emitter.getPosition().x;
	emitterPos->y = emitter.getPosition().y;

	emitterChannel->set3DAttributes(emitterPos, emitterVel);
	emitterChannel->set3DMinMaxDistance(100 , 400);

	droneChannel->set3DAttributes( dronePos, droneVel );
	droneChannel->set3DMinMaxDistance(10, 100);

	fmod_sys->set3DListenerAttributes(0, listenerPos, listenerVel, 0, 0);

	//if click, play sound effect and return true
	if(Event.type == sf::Event::EventType::MouseButtonPressed) {

		//play a sound without a channel (not updateable, one-shot, etc)
		fmod_sys->playSound(
		FMOD_CHANNEL_FREE, //find a free channel
		sound,                  // sound to play
		false,              //start playing/paused
		&emitterChannel);                 //channel reference

		handled = true;
	}

	bool result;
	droneChannel->getPaused(&result);
	if ( result == true )
		droneChannel->setPaused(false);

	

	return handled;
}

void FMOD_DEMO::update( Time const &ElapsedTime ) {
}

void FMOD_DEMO::draw( RenderWindow &w ) {
	//bind the listener's position to the mouse
	listener.setPosition( Mouse::getPosition(w).x, Mouse::getPosition(w).y );

	w.draw( reverbArea );
	w.draw( emitter );
	w.draw( listener );

	system("CLS");
	std::cout << "Listener | " << listener.getPosition().x << " " << listener.getPosition().y << std::endl;
	std::cout << "Listener FMOD Pos | " << listenerPos->x << " " << listenerPos->y << std::endl;
	std::cout << "Listener FMOD Vel | " << listenerVel->x << " " << listenerVel->y << std::endl;
	std::cout << "Emitter | " << emitter.getPosition().x << " " << emitter.getPosition().y << std::endl;
	std::cout << "Emitter FMOD Pos | " << emitterPos->x << " " << emitterPos->y << std::endl;
	std::cout << "Emitter FMOD Vel | " << emitterVel->x << " " << emitterVel->y << std::endl;
}