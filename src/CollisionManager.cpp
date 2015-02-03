#include "CollisionManager.h"
#include <cmath>

//Cout includes
#include <iostream>
using std::cout;
using std::endl;

CollisionManager* CollisionManager::m_instance = NULL;

void CollisionManager::SquareCircle(GameEntity* square, Ball* circle){
<<<<<<< HEAD
	bool colide = false;
	float rectLength = (square->getSprite().getTexture()->getSize().x * square->getScale().x) / 2;
	float circleRadius = circle->GetRadius();
=======
	sf::Rect<float> Rect = square->getSprite().getLocalBounds();
//	float circleRadius = circle->getSprite();


	/*// clamp(value, min, max) - limits value to the range min..max
>>>>>>> 01cb1217dd024ffbd61b8d9896ff606a19bfd2dd

	// Find the closest point to the circle within the rectangle
	float closestX = clamp(circle->getPosition().x, square->getPosition().x - rectLength, square->getPosition().x + rectLength);
	float closestY = clamp(circle->getPosition().y, square->getPosition().y - rectLength, square->getPosition().y + rectLength);

	// Calculate the distance between the circle's center and this closest point
	float distanceX = circle->getPosition().x - closestX;
	float distanceY = circle->getPosition().y - closestY;

	//is the distance less than the radius
	if(circleRadius >= sqrtf(powf((distanceX),2) + powf(distanceY,2))){
		//colide = true;
		circle->Death_Reset();
		//cout << "DeathReset()";
	

	////vector between points
	////Vector2f normMTV(closestX - circle->getPosition().x , closestY - circle->getPosition().y);

	////get the components of the velocity vectors which are parallel to the collision
	////float magnitude = sqrtf((normMTV.x * normMTV.x) + (normMTV.y * normMTV.y));
	////normMTV = (normMTV / magnitude);

	////dot product
	////float aci = (square->getVelocity().x * normMTV.x) + (square->getVelocity().y * normMTV.y);
	////float bci = (circle->getVelocity().x * normMTV.x) + (circle->getVelocity().y * normMTV.y);
	////square->setVelocity(Vector2f(square->getVelocity().x + (bci - aci) * normMTV.x, square->getVelocity().y + (bci - aci) * normMTV.y));
	////circle->setVelocity(Vector2f(circle->getVelocity().x + (aci - bci) * normMTV.x, circle->getVelocity().y + (aci - bci) * normMTV.y));
	}
}

bool CollisionManager::SquareSquare(GameEntity* squareOne, GameEntity* squareTwo){
	sf::Rect<float> RectOne = squareOne->getSprite().getLocalBounds();
	sf::Rect<float> RectTwo = squareTwo->getSprite().getLocalBounds();
	return RectOne.intersects( RectTwo );
}


bool CollisionManager::OffScreen(GameEntity* circle){
	//goes off edges
	return ((circle->getPosition().x < 0)||(circle->getPosition().x > contextWindow->getSize().x)||(circle->getPosition().y < 0)||(circle->getPosition().y > contextWindow->getSize().y));
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


void CollisionManager::setContext( RenderWindow * window) {
	contextWindow = window;
}

const RenderWindow* CollisionManager::getContext() const {
	return contextWindow;
}

