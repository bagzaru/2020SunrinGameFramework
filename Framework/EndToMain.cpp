#include "stdafx.h"
#include "EndToMain.h"
#include "StartScene.h"
#include "InputManager.h"

void EndToMain::Update()
{
	if (InputManager::GetKeyDown(VK_RETURN))
	{
		Scene::ChangeScene(new StartScene());
	}
	if (InputManager::GetKeyDown(VK_ESCAPE))
	{
		Scene::ChangeScene(new StartScene());
	}
}
