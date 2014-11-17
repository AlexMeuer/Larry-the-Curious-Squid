#include "..\include\Block.h"
/*
Block::Block() {

}*/

Block::Block(Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass) 
	: GameEntity( texture,  position, velocity, scale,  angularVel,  rotation_degrees,  mass) {
		m_sprite.setPosition(position.x, position.y);

}

Block::~Block() {

}

void Block::Update() {

}