#ifndef _LEVEL_
#define _LEVEL_

#import sfml_stuff
#import tiny_xml_stuff
#import <vector>
using namespace sf;

class Level {
private:

	std::vector<GameEntity> m_entities;
	Force m_gravity;
	int id;
	
	void LoadFromXML(string path);
	
public:

	Level(string xml_path);
	~Level;
	
	void Update();
	void Draw(RenderWindow &w);
};
#endif