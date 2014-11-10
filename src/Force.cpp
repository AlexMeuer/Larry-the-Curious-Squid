#include "../include//Force.h"

// Returns a vector that represents the euclidean distance from one vector to another
//Vector2f getVectorDistance(Vector2f const &A, Vector2f const &B) {
//	return Vector2f(sqrtf(powf(B.x - A.x, 2)), sqrtf(powf(B.y - A.y, 2)));
//}

float getLength(Vector2f const &V) {
	return sqrtf((V.x * V.x) + (V.y * V.y));
}

//Applies the force to a GameEntity (assuming linear falloff)
void Force::Apply(GameEntity * e) const {

	Vector2f displacement =  e->getPosition() - m_position;
	float distance = getLength( displacement );

	//if the distance between the two vectors is less than the force... (force is made positive to allow for black holes/pulling forces with negative power)
	if ( distance < sqrtf(m_power * m_power) ) {
		Vector2f direction = displacement / distance;

		//...apply velocity to the entity in the appropriate direction and accounting for linear falloff
		e->setVelocity( e->getVelocity() + direction * (m_power/distance ));//- distance) );
	}

}