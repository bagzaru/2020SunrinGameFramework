#include "stdafx.h"
#include "TestScene.h"

void TestScene::Initialize()
{
	testObject = new AnimationObject(new AnimationInfo());
	PushBackGameObject(testObject);
	testObject->transform->SetPosition(300.0f, 300.0f);

	GameObject* test = new GameObject(L"resources/a.png");
	PushBackGameObject(test);
	test->transform->SetPosition(500.0f, 500.0f);
	test->transform->SetScale(0.3f, 0.3f);


}
