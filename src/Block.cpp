#include "Block.h"

Block::Block(Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass) 
	: GameEntity( texture,  position, velocity, scale,  angularVel,  rotation_degrees,  mass)
	, m_force(Vector2f(250 , 400), 200){
		m_sprite.setPosition(position.x, position.y);

}

Block::~Block() {

}

void Block::Update() {

}

void Block::KeepOnOriginalPosForce(Time elapsedTime){
	//apply a force that sucks in like the Black whole,
	//to the point on the map the block is assigined.
	//Eg when the body is effected by a force it will move
	//but there will be a stronger force pulling the object
	//back to its start Pos.
	m_force.Apply(this, elapsedTime, false);
}

