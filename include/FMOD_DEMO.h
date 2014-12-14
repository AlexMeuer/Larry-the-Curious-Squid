#ifndef FMOD_DEMO_H
#define FMOD_DEMO_H

#include "Scene.h"
#include "fmod.hpp"
#include "fmod_errors.h"

using namespace sf;

//////////////////////////////////////////////////////////
//														//
//	check gitHub repo issues to check what needs doing	//
//														//
//////////////////////////////////////////////////////////

class FMOD_DEMO : public I_Scene {
private:
	Texture listenerTex;
	Sprite listener;
	FMOD_VECTOR *listenerPos, *listenerVel;
	CircleShape reverbArea;
	FMOD::System* fmod_sys;
public:
	FMOD_DEMO( Vector2f reverbCentre, FMOD::System* sys );
	~FMOD_DEMO();

	bool I_Scene::handleEvent( Event &Event );
	void I_Scene::update( Time const &ElapsedTime );
	void I_Scene::draw( RenderWindow &w );
};
#endif