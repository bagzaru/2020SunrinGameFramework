#include "stdafx.h"
#include "PlatformerScene.h"
#include "Ground.h"
#include "JumpingObject.h"

void PlatformerScene::Initialize()
{
	Ground* g1 = new Ground(L"resources/background.jpg");
	g1->transform->SetPosition(-100.0f, -100.0f);
	g1->transform->SetScale(0.2f, 0.2f);
	Push(g1);

	Ground* g2 = new Ground(L"resources/background.png");
	g2->transform->SetPosition(100.0f, 50.0f);
	g2->transform->SetScale(0.2f, 0.2f);
	Push(g2);

	JumpingObject* player = new JumpingObject();
	player->transform->SetPosition(00.0f, 300.0f);
	Push(player);
}
