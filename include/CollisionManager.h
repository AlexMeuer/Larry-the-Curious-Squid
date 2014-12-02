#ifndef _COLLISIONMANAGER_
#define _COLLISIONMANAGER_

#include "Ball.h"

class CollisionManager{
private:
	void clamp(Vector3f &v, const Vector3f &min, const Vector3f &max) const;
	float clamp(float value, const float min, const float max) const;
public:
	
	Vector2f SquareCircle(Sprite* square, Ball* circle);
	bool SquareSquare(Sprite* squareOne, Sprite* squareTwo);
	bool OffScreen(RenderWindow &w, Ball* circle);
	/*void clamp(const Vector3f &v, const Vector3f &min, const Vector3f &max);
	float clamp(float value, const float min, const float max);*/
};
#endif