#include "../include/Level.h"
#include "../include/tinyxml2.h"
#include "../include/Ball.h"
#include "../include/Block.h"
#include "../include/BlackHole.h"
#include "../include/PowerUp.h"

using namespace tinyxml2;

int Level::getID() const {
	return id;
}

void Level::Update() {
	//update all entities in vector
	for(auto itr = m_entities.begin();
		itr != m_entities.end();
		itr++)
	{
		itr->Update();
	}
}

void Level::Draw(RenderWindow &w) {
	//draw all entities in vector
	for(auto itr = m_entities.begin();
		itr != m_entities.end();
		itr++)
	{
		itr->Draw(w);
	}
}

void Level::LoadTexture(String name) {
	if ( textures.find(name) == textures.end() ) {
		//load the texture and add it to the map
		textures[name].loadFromFile("../res/img/" + name);
		}
}


Level Level::LoadFromXML(const char *path) {
	XMLDocument doc;
	doc.LoadFile(path);
	Level tmp_lvl = Level();

	//query the level id and assign it to the temporary level
	XMLText* node = doc.FirstChildElement( "LEVEL" )->FirstChildElement( "ID" )->FirstChild()->ToText();
	tmp_lvl.id = atoi(node->Value());	//atoi converts c string to integer

	//query the gravity force and assign it to the temporary level
	node = doc.FirstChildElement( "LEVEL" )->FirstChildElement( "GRAVITY" )->FirstChild()->ToText();
	Force f = Force( Vector2f(0,0), atof(node->Value()) );	//atof converts c string to float
	tmp_lvl.m_gravity = Force(f);

	//iterate through all ENTITY elements, creating and adding objects as necessary
	for(XMLText* node = doc.FirstChildElement( "LEVEL" )->FirstChildElement("ENTITY")->ToText();
		node;
		node=node->NextSiblingElement("ENTITY")->ToText()){

			const char * string = node->Value();

			if (string == "BLOCK") {
				//load the block's texture
				String textureName(node->FirstChildElement("TEXTURE")->ToText()->Value());
				LoadTexture(textureName);

				//get the position of the block
				XMLNode* positionNode = node->FirstChildElement("POSITION");
				float x = atof(positionNode->FirstChildElement("X")->ToText()->Value());
				float y = atof(positionNode->FirstChildElement("Y")->ToText()->Value());

				tmp_lvl.m_entities.push_back( Block() );
			}
			else if (string == "BALL") {
				//load the ball's texture
				String textureName( node->FirstChildElement( "TEXTURE" )->ToText()->Value() );
				LoadTexture( textureName );
				
				//get the position of the ball
				XMLNode* positionNode = node->FirstChildElement( "POSITION" );
				float x = atof( positionNode->FirstChildElement( "X" )->ToText()->Value() );
				float y = atof( positionNode->FirstChildElement( "Y" )->ToText()->Value() );

				tmp_lvl.m_entities.push_back( Ball( &textures.find(textureName)->second, Vector2f(x,y) ) );
			}
			else if (string == "BLACKHOLE") {
				//get the black hole's texture
				String textureName(node->FirstChildElement("TEXTURE")->ToText()->Value());
				LoadTexture(textureName);

				//get the position of the black hole
				XMLNode* positionNode = node->FirstChildElement("POSITION");
				float x = atof(positionNode->FirstChildElement("X")->ToText()->Value());
				float y = atof(positionNode->FirstChildElement("Y")->ToText()->Value());

				//get the angular velocity of the black hole
				float angVel = atof( node->FirstChildElement("ANGULAR_VELOCITY")->ToText()->Value() );

				//get the force of the black hole
				Force f = Force(Vector2f(x, y), atof(node->FirstChildElement("POWER")->ToText()->Value()));

				tmp_lvl.m_entities.push_back( BlackHole() );
			}
			else if (string == "POWERUP") {
				//get the black hole's texture
				String textureName(node->FirstChildElement("TEXTURE")->ToText()->Value());
				LoadTexture(textureName);

				//get the position of the black hole
				XMLNode* positionNode = node->FirstChildElement("POSITION");
				float x = atof(positionNode->FirstChildElement("X")->ToText()->Value());
				float y = atof(positionNode->FirstChildElement("Y")->ToText()->Value());

				//get the angular velocity of the powerup
				float angVel = atof( node->FirstChildElement("ANGULAR_VELOCITY")->ToText()->Value() );

				tmp_lvl.m_entities.push_back( PowerUp() );
			}
	}//end for loop

	return Level(tmp_lvl);	//return a copy of tmp_lvl (tmp_lvl goes out of scope after this)
}