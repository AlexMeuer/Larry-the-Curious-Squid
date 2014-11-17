#include "..\include\CollisionManager.h"

void CollisionManager::SquareCircle(Sprite* square, Ball* circle){
	sf::Rect<float> Rect = square->getLocalBounds();
	float circleRadius = circle->getSprite().getLocalBounds().width/2;

	if((Rect.top + Rect.height > circle->getPosition().y - circleRadius) && (Rect.top + Rect.height < circle->getPosition().y + circleRadius)
		|| (Rect.top < circle->getPosition().y + circleRadius) && (Rect.top > circle->getPosition().y - circleRadius)){
			circle->setVelocity(sf::Vector2f(circle->getVelocity().x, circle->getVelocity().y * -1));
	}
	if((Rect.left + Rect.width > circle->getPosition().x - circleRadius) && (Rect.left + Rect.width < circle->getPosition().x + circleRadius)
		|| (Rect.left < circle->getPosition().x + circleRadius) && (Rect.left > circle->getPosition().x - circleRadius)){
			circle->setVelocity(sf::Vector2f(circle->getVelocity().x * -1, circle->getVelocity().y));
	}

}

bool CollisionManager::SquareSquare(Sprite* squareOne, Sprite* squareTwo){
	sf::Rect<float> RectOne = squareOne->getLocalBounds();
	sf::Rect<float> RectTwo = squareTwo->getLocalBounds();
	return ! ( RectTwo.left > RectOne.width + RectOne.left 
		|| RectTwo.width + RectTwo.left < RectOne.left 
		|| RectTwo.top < RectOne.height + RectOne.top
		|| RectTwo.height + RectTwo.top > RectOne.top);
}


bool CollisionManager::OffScreen(RenderWindow &w, Ball* circle){
	//gose off edges
	return ((circle->getPosition().x < 0)||(circle->getPosition().x > 800)||(circle->getPosition().y < 0)||(circle->getPosition().y > 600));
}