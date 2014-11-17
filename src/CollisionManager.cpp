#include "..\include\CollisionManager.h"

bool SquareCircle(Sprite* square, GameEntity* circle){
	sf::Rect<float> Rect = square->getGlobalBounds();
	float circleRadius = circle->getSprite().getGlobalBounds().width/2;
	return ! (Rect.left > circle->getPosition().x + circleRadius
		|| Rect.width + Rect.left < circle->getPosition().x - circleRadius 
		|| Rect.top < circle->getPosition().y + circleRadius
		|| Rect.height + Rect.top > circle->getPosition().y - circleRadius);
}

bool SquareSquare(Sprite* squareOne, Sprite* squareTwo){
	sf::Rect<float> RectOne = squareOne->getGlobalBounds();
	sf::Rect<float> RectTwo = squareTwo->getGlobalBounds();
	return ! ( RectTwo.left > RectOne.width + RectOne.left 
		|| RectTwo.width + RectTwo.left < RectOne.left 
		|| RectTwo.top < RectOne.height + RectOne.top
		|| RectTwo.height + RectTwo.top > RectOne.top);
}