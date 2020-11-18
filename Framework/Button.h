#pragma once
#include "GameScene.h"
class Button :
	public GameObject
{
public:
	AABBCollider* col;
	Button(const wchar_t* uri);
	~Button();
	void Update();
	virtual void OnClick(){}
};

