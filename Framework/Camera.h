#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class Camera :
	public GameObject
{
private:
	int screenWidth;
	int screenHeight;
	float halfWidth;
	float halfHeight;

	AABBCollider* screenBox;
public:
	Camera();
	virtual ~Camera();

	inline Vector2 WorldPositionToScreen(const Vector2& worldPosition);
	inline Vector2 ScreenPositionToWorld(const Vector2& screenPosition);
	bool IsOnScreen(AABBCollider* col);

public:
	static Camera* GetCamera();//¹Ì¿Ï¼º
	void Update();

};

