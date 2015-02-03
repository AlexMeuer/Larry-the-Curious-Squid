#ifndef _BLOCK_
#define _BLOCK_

#include "GameEntity.h"
#include "include\Force.h"

class Block: public GameEntity {
public:
	Block(Texture* texture, Vector2f position, Vector2f velocity = Vector2f(0,0), Vector2f scale = Vector2f(1,1), float angularVel = 0, float rotation_degrees = 0, float mass = 1);

	~Block();
	void Update();
	void ResistanceForce(Time elapsedTime);
	float GetWidth_Height();

protected:
	//vairbles
	Force m_force;
	float m_Width_Height;

};
#endif