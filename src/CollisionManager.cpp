#include "CollisionManager.h"

CollisionManager* CollisionManager::m_instance = NULL;

void CollisionManager::SquareCircle(GameEntity* square, GameEntity* circle){
	sf::Rect<float> Rect = square->getSprite().getLocalBounds();
	float circleRadius = circle->getSprite().getLocalBounds().width/2;

	// clamp(value, min, max) - limits value to the range min..max

	// Find the closest point to the circle within the rectangle
	float closestX = clamp(circle->getPosition().x, Rect.left, Rect.left + Rect.width);
	float closestY = clamp(circle->getPosition().y, Rect.top, Rect.top + Rect.height);

	// Calculate the distance between the circle's center and this closest point
	float distanceX = circle->getPosition().x - closestX;
	float distanceY = circle->getPosition().y - closestY;

	// If the distance is less than the circle's radius, an intersection occurs
	float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
	//return distanceSquared < (circleRadius + circleRadius);

	//vector between points
	Vector2f normMTV(closestX + circle->getPosition().x , closestY + circle->getPosition().y);

	//get the components of the velocity vectors which are parallel to the collision
	float magnitude = sqrtf((normMTV.x * normMTV.x) + (normMTV.y * normMTV.y));
	normMTV = (normMTV / magnitude);

	//dot product
	float aci = (square->getVelocity().x * normMTV.x) + (square->getVelocity().y * normMTV.y);
	float bci = (circle->getVelocity().x * normMTV.x) + (circle->getVelocity().y * normMTV.y);
	square->setVelocity(Vector2f(square->getVelocity().x + (bci - aci) * normMTV.x, square->getVelocity().y + (bci - aci) * normMTV.y));
	circle->setVelocity(Vector2f(circle->getVelocity().x + (aci - bci) * normMTV.x, circle->getVelocity().y + (aci - bci) * normMTV.y));

}

bool CollisionManager::SquareSquare(GameEntity* squareOne, GameEntity* squareTwo){
	sf::Rect<float> RectOne = squareOne->getSprite().getLocalBounds();
	sf::Rect<float> RectTwo = squareTwo->getSprite().getLocalBounds();
	return RectOne.intersects( RectTwo );
}


bool CollisionManager::OffScreen(GameEntity* circle){
	//gose off edges
	return ((circle->getPosition().x < 0)||(circle->getPosition().x > 600)||(circle->getPosition().y < 0)||(circle->getPosition().y > 800));
}


void CollisionManager::clamp(Vector3f &v, const Vector3f &min, const Vector3f &max) const
{
	v.x = clamp(v.x, min.x, max.x);
    v.y = clamp(v.y, min.y, max.y);
    v.z = clamp(v.z, min.z, max.z);
}

float CollisionManager::clamp(float value, const float min, const float max) const
{
    value = std::min(value, max);
	value = std::max(value, min);

    return value;
}
