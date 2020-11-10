#include "stdafx.h"
#include "TestScene.h"

void TestScene::Initialize()
{
	testObject = new AnimationObject(new AnimationInfo());
	Push(testObject);
	testObject->transform->SetPosition(0.0f, 0.0f);


}
