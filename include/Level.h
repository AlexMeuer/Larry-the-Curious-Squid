#ifndef _LEVEL_
#define _LEVEL_

#include <vector>
#include "SFML\Graphics.hpp"
#include "GameEntity.h"
#include "Force.h"
#include "Ball.h"
#include "Scene.h"
#include "HeadsUpDisplay.h"

class Level : public I_Scene{
private:

	std::vector<GameEntity> m_entities;

	static std::map<String, Texture> textures;
	static void LoadTexture(String name);

	Vector2f m_gravity;

	int id;

	//HeadsUpDisplay::instance();

	Level() : id(-1), m_gravity(Vector2f(0,0)) {}
	
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