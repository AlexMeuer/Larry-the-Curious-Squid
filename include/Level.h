#ifndef _LEVEL_
#define _LEVEL_

#include <vector>
#include "SFML\Graphics.hpp"
#include "GameEntity.h"
#include "Force.h"
#include "Scene.h"
#include "HeadsUpDisplay.h"
#include "../include/tinyxml2.h"
#include "../include/Ball.h"
#include "../include/Block.h"
#include "../include/BlackHole.h"
#include "../include/PowerUp.h"
#include "include\CollisionManager.h"

class Level : public I_Scene{
private:

	std::vector<GameEntity*> m_entities;

	static std::map<String, Texture> textures;
	static void LoadTexture(String name, String ext);

	Vector2f m_gravity;

	Force playerForce;

	int id;

	//HeadsUpDisplay::instance();

	Level() : id(-1), m_gravity(Vector2f(0,0)), playerForce(Vector2f(FLT_MAX, FLT_MAX), 1000) {}
	
public:
	~Level() {}


	int getID() const;
	
	bool I_Scene::handleEvent( Event &Event );
	void I_Scene::update(Time const &elapsedTime);//, RenderWindow &w);
	void I_Scene::draw(RenderWindow &w);

	static Level* LoadFromXML(const char *path);
	//static Level LoadFromXML(const char *path, std::map<String, Texture> loadedTextures);
};
#endif