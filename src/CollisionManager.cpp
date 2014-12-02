#include "CollisionManager.h"

Vector2f CollisionManager::SquareCircle(Sprite* square, Ball* circle){

	sf::Rect<float> Rect = square->getLocalBounds();
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
	return Vector2f(closestX + circle->getPosition().x , closestY + circle->getPosition().y);
}

bool CollisionManager::SquareSquare(Sprite* squareOne, Sprite* squareTwo){
	sf::Rect<float> RectOne = squareOne->getLocalBounds();
	sf::Rect<float> RectTwo = squareTwo->getLocalBounds();
	return RectOne.intersects( RectTwo );
}


bool CollisionManager::OffScreen(RenderWindow &w, Ball* circle){
	//gose off edges
	return ((circle->getPosition().x < 0)||(circle->getPosition().x > 800)||(circle->getPosition().y < 0)||(circle->getPosition().y > 600));
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