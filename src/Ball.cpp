#include "..\include\Ball.h"

Ball::Ball(Texture* texture, Vector2f position, Vector2f velocity, Vector2f scale, float angularVel, float rotation_degrees, float mass)
: GameEntity( texture,  position,  velocity,  scale,  angularVel,  rotation_degrees,  mass), coefficentOfRestitution(1){
}

Ball::~Ball(){

}

void Ball::Update() {
	
}