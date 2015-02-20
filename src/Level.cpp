#include "../include/Level.h"
#ifdef _DEBUG
#include <assert.h>
#endif

using namespace tinyxml2;

std::map<String, Texture> Level::textures = std::map<String, Texture>();

int Level::getID() const {
	return id;
}

bool Level::handleEvent( Event &event ) {
	static bool mouseDown;
	if ( event.type == Event::MouseButtonPressed ) {
		mouseDown = true;
	}
	else if ( event.type == Event::MouseButtonReleased ) {
		mouseDown = false;
		playerForce.setPosition( Vector2f(FLT_MAX, FLT_MAX) );
	}

	if (mouseDown) {
		//get the current mouse position relative to the screen. (we can get the window by asking the collision manager what window its checking again for offscreen stuff, etc)
		Vector2i mousePos = Mouse::getPosition(*(CollisionManager::instance()->getContext()));

		playerForce.setPosition(Vector2f(mousePos.x, mousePos.y));
	}

	return false;
}

void Level::update(Time const &elapsedTime)/*, RenderWindow &w)*/ {
	std::vector<GameEntity*>::iterator itr;
	std::vector<GameEntity*>::iterator itrToCheckBlock;
	//update all entities in vector
	for(itr = m_entities.begin(); itr != m_entities.end(); itr++)
	{
		playerForce.Apply(*itr, elapsedTime);

		
		//blackhole.ApplyForce(itr);

		//Child *p = dynamic_cast<Child *>(pParent)
		Ball *p = dynamic_cast<Ball *>(*itr);

		if(p != NULL){

			p->Update(elapsedTime, m_gravity);

			for(itrToCheckBlock = m_entities.begin(); itrToCheckBlock != m_entities.end(); itrToCheckBlock++) {

				Block *b = dynamic_cast<Block *>(*itrToCheckBlock);

				if(b != NULL){
					//b->ResistanceForce(elapsedTime);
					CollisionManager::instance()->SquareCircle(b,p);
				}//end if (b != NULL)

				BlackHole *black = dynamic_cast<BlackHole *>(*itrToCheckBlock);

				if(black != NULL){
					CollisionManager::instance()->CircleCircle(black,p);
				}

				if(CollisionManager::instance()->OffScreen(p)){
					p->Death_Reset();
				}//end if (CollisionManager::instance()->OffScreen(p))

			}//end for everything in entities
		}//end if (p != NULL)
		else {
			(*itr)->Update(elapsedTime, m_gravity);
			(*itr)->ResistForces(elapsedTime);
		}
	}//end for everything in entities
}//end update

void Level::draw(RenderWindow &w) {
	std::vector<GameEntity*>::iterator itr;

	//draw all entities in vector
	for(auto itr = m_entities.begin();
		itr != m_entities.end();
		itr++)
	{
		(*itr)->Draw(w);
	}
}


void Level::LoadTexture(String name, String ext) {
	if ( textures.find(name) == textures.end() ) {
		//load the texture and add it to the map
		textures[name].loadFromFile("./res/img/" + name + "." + ext);
		}
}

Level* Level::LoadFromXML(const char *path) {
	tinyxml2::XMLDocument doc;	//empty xml document

	XMLError result = doc.LoadFile(path);	//try to load the xml from file
	if ( result != XML_NO_ERROR )
		throw result;	//throw an error if one occured

	Level tmp_lvl = Level();	//create a temporary level to hold loaded elements

	//query the level id and assign it to the temporary level
	XMLElement* node = doc.FirstChildElement( "LEVEL" )->FirstChildElement( "ID" );
	tmp_lvl.id = atoi(node->GetText());	//atoi converts c string to integer

	//query the gravity force and assign it to the temporary level
	node = doc.FirstChildElement( "LEVEL" )->FirstChildElement( "GRAVITY" );
	//Force f = Force( Vector2f(0,0), atof(node->GetText()) );	//atof converts c string to float
	//tmp_lvl.m_gravity = Force(f);
	tmp_lvl.m_gravity = Vector2f( 0, atof(node->GetText()) );

	//iterate through all ENTITY elements, creating and adding objects as necessary
	for(XMLElement* node = doc.FirstChildElement( "LEVEL" )->FirstChildElement("ENTITY");
		node != NULL;
		node=node->NextSiblingElement("ENTITY")){

			//Get the type of entity to be loaded
			std::string value = std::string( node->FirstChildElement()->Value() );

			if (value == "BLOCK_MAP") {
#pragma region LoadBlockTextures
				//get the number of block types/textures
				int blockTypes = atoi(node->FirstChildElement("NUMBER_OF_BLOCK_TYPES")->GetText());

				/*
				//split the given texture arguement into its name and extension
				char * baseStr;
				strcpy(baseStr, node->FirstChildElement("TEXTURE")->GetText());
				baseStr = strtok(baseStr, ".");
				char * ext = strtok(NULL, ".");
				*/

				const char * texName = node->FirstChildElement("TEXTURE")->GetText();
				const char * ext = node->FirstChildElement("TEXTURE")->Attribute("EXT");

				//for each type of block, load the appropriate texture
				for (int i = 1; i <= blockTypes; ++i) {
					char buffer[3];	//buffer for converting int to string

					//set the finalTexName to be the base name (e.g. "block")
					char finalTexName[64];
					strcpy_s(finalTexName, sizeof(finalTexName), texName);

					//add the block type to the base name (e.g. "1" so that finalTexName becomes "block1")
					_itoa_s(i, buffer, sizeof(buffer), 10);
					strcat_s(finalTexName, sizeof(finalTexName), buffer);

					//add the dot and the extension (e.g. ".png" so that finalTexName becomes "block1.png")
					//strcat(finalTexName, ".");
					//strcat(finalTexName, ext);


					LoadTexture(finalTexName, ext);

				}
				////delete[] texName;
				//delete[] ext;
				//delete[] finalTexName;
				//delete[] buffer;
#pragma endregion


				/*
				unsigned int width = atoi(node->FirstChildElement("WIDTH")->GetText());
				unsigned int height = atoi(node->FirstChildElement("HEIGHT")->GetText());

				const char * blockMap = node->FirstChildElement("MAP")->GetText();

				for(unsigned int x = 0; x < width; ++x) {
					for(unsigned int y = 0; y < height; ++y) {
					}
				}*/

				//get the spacing between blocks
				float spacing = atof(node->FirstChildElement("MAP")->Attribute("SPACING"));

#pragma region CreateBlocksFromMap
				//Get the map from the xml file
				char str[1024];
				strcpy_s(str, sizeof(str), node->FirstChildElement("MAP")->GetText());

				//get the first line of the map
				char * context = NULL;
				char * line = strtok_s(str, " ,.\|/!:;\n\t", &context);

				for(int y = 0; line != NULL; ++y) {

#ifdef _DEBUG
					assert(line != NULL);
#endif

					int len = strlen(line);	//for(length of line) { create a block }
					for(int x = 0; x < len; ++x) {

						//convert the char at x to an int, assuming it's between 0 and 9
						//int blockType = line[x] - '0';

						//if(blockType > 0) {
						if(line[x] - '0' > 0) {
							char buffer[128];
							std::string bT_buffer = std::string(1, line[x]);
							//strcpy_s(buffer, 127, reinterpret_cast<const char *>(texName));
							strcpy_s(buffer, sizeof(buffer), texName);
							strcat_s(buffer, sizeof(buffer), bT_buffer.c_str());
							//cout << buffer << endl;
							tmp_lvl.m_entities.push_back(new Block(&textures[buffer], Vector2f(x * spacing + (spacing / 2), y * spacing + (spacing / 2))));
						}
					}

					//get the next line of the map (using NULL instead of str just re-uses context)
					line = strtok_s(NULL, " ,.\|/!:;\n\t", &context);
				}
				//delete[] str;  
#pragma endregion
			}
			else if (value == std::string("BALL").c_str()) {
				//load the ball's texture
				const char * texName = node->FirstChildElement("TEXTURE")->GetText();
				const char * ext = node->FirstChildElement("TEXTURE")->Attribute("EXT");
				LoadTexture( texName, ext );
				
				//get the position of the ball
				XMLElement* positionNode = node->FirstChildElement( "POSITION" );
				float x = atof( positionNode->FirstChildElement( "X" )->GetText() );
				float y = atof( positionNode->FirstChildElement( "Y" )->GetText() );

				float scale = atof( node->FirstChildElement("SCALE")->GetText());

				tmp_lvl.m_entities.push_back( new Ball(Vector2i(0,0), &textures.find(texName)->second, Vector2f(x,y), Vector2f(0,0), Vector2f(scale, scale) ) );
			}
			else if (value == std::string("LEVEL_END").c_str()) {
				//get the black hole's texture
				const char * texName = node->FirstChildElement("TEXTURE")->GetText();
				const char * ext = node->FirstChildElement("TEXTURE")->Attribute("EXT");
				LoadTexture( texName, ext );

				//get the position of the black hole
				XMLElement* positionNode = node->FirstChildElement("POSITION");
				float x = atof(positionNode->FirstChildElement("X")->GetText());
				float y = atof(positionNode->FirstChildElement("Y")->GetText());

				//get the angular velocity of the black hole
				//float angVel = atof( node->FirstChildElement("ANGULAR_VELOCITY")->GetText() );

				//get the force of the black hole
				//Force f = Force(Vector2f(x, y), atof(node->FirstChildElement("POWER")->GetText()));

				//get the scene to change to when the player reaches the end
				String scene = String(node->FirstChildElement("TARGET_SCENE")->GetText());

				tmp_lvl.m_entities.push_back( new BlackHole( scene, &textures.find(texName)->second, Vector2f(x,y)));
			}
			else if (value == std::string("POWERUP").c_str()) {
				//get the black hole's texture
				const char * texName = node->FirstChildElement("TEXTURE")->GetText();
				const char * ext = node->FirstChildElement("TEXTURE")->Attribute("EXT");
				LoadTexture( texName, ext );

				//get the position of the black hole
				XMLElement* positionNode = node->FirstChildElement("POSITION");
				float x = atof(positionNode->FirstChildElement("X")->GetText());
				float y = atof(positionNode->FirstChildElement("Y")->GetText());

				//get the angular velocity of the powerup
				float angVel = atof( node->FirstChildElement("ANGULAR_VELOCITY")->GetText() );

				//tmp_lvl.m_entities.push_back( PowerUp() );
			}
	}//end for loop

	return new Level(tmp_lvl);	//return a copy of tmp_lvl (tmp_lvl goes out of scope after this)
}