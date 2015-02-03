#include "Block.h"
#if(_DEBUG)
#include <assert.h>
#endif

Block::Block(Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass) 
	: GameEntity( texture,  position, velocity, scale,  angularVel,  rotation_degrees,  mass)
	, m_force(position, -100){
		m_sprite.setPosition(position.x, position.y);
		m_Width_Height = texture->getSize().x * scale.x;
#if(_DEBUG)
		assert(texture->getSize().x * scale.x == m_sprite.getTexture()->getSize().y * m_sprite.getScale().y);
#endif
}

Block::~Block() {

}

//void Block::Update() {
//
//}

//void Block::ResistanceForce(Time elapsedTime){
//	//apply a force that sucks in like the Black whole,
//	//to the point on the map the block is assigined.
//	//Eg when the body is effected by a force it will move
//	//but there will be a stronger force pulling the object
//	//back to its start Pos.
//
//	m_force.Apply(this, elapsedTime);
//}

float Block::GetWidth_Height(){
	return m_Width_Height;
}

