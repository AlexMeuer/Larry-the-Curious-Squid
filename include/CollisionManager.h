#ifndef _COLLISIONMANAGER_
#define _COLLISIONMANAGER_

#include "Ball.h"
#include "Block.h"

class CollisionManager{
private:
	void clamp(Vector3f &v, const Vector3f &min, const Vector3f &max) const;
	float clamp(float value, const float min, const float max) const;
	

	static CollisionManager* m_instance;

	CollisionManager() {}
public:
	~CollisionManager() {}
	//get the instance of the manager (creates a new one if none exists)
	static CollisionManager* instance() {	return instance == NULL ? m_instance = new CollisionManager() : m_instance;	}
	void SetWindow();
	void SquareCircle(GameEntity* square, GameEntity* circle);
	bool SquareSquare(GameEntity* squareOne, GameEntity* squareTwo);
	bool OffScreen(GameEntity* circle);
	/*void clamp(const Vector3f &v, const Vector3f &min, const Vector3f &max);
	float clamp(float value, const float min, const float max);*/
};
#endif