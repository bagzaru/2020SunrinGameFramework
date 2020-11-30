#include "stdafx.h"
#include "SubScreen.h"
#include "InputManager.h"
#include "TimeManager.h"

SubScreen::SubScreen(Vector2 subScreenSize, D2DApp* d2dApp)
	:GameObject(subRenderer = new RenderInfo()), 
	subRenderTarget(subRenderTarget), d2dApp(d2dApp)
{
	subScreenSprite = new Sprite();
	subRenderTarget = d2dApp->CreateSubRenderTarget(subScreenSize.x, subScreenSize.y);
	subRenderTarget->GetBitmap(&subScreenSprite->bitmap);
	D2D1_SIZE_F s = subRenderTarget->GetSize();
	this->subScreenSize.x = s.width;
	this->subScreenSize.y = s.height;

	subRenderer->currentSprite = subScreenSprite;
	subRenderer->initialized = false;
	subRenderer->width = s.width;
	subRenderer->height = s.height;

	transform->SetPosition(300.0f, 300.0f);
}

SubScreen::~SubScreen()
{
	SAFE_RELEASE(subRenderTarget);
	SAFE_RELEASE(subScreenSprite->bitmap);
	SAFE_DELETE(subScreenSprite);
}

void SubScreen::Update()
{
	//���������� �� ȭ���� ����ٴմϴ�.
	lookAtPosition = target->position;

	/*if (InputManager::GetKeyState('A'))
	{
		transform->position.x -= 100.0f * TimeManager::GetDeltaTime();
	}
	if (InputManager::GetKeyState('D'))
	{
		transform->position.x += 100.0f * TimeManager::GetDeltaTime();
	}

	if (InputManager::GetKeyState('W'))
	{
		transform->position.y += 100.0f * TimeManager::GetDeltaTime();
	}
	if (InputManager::GetKeyState('S'))
	{
		transform->position.y -= 100.0f * TimeManager::GetDeltaTime();
	}

	if (InputManager::GetKeyState(VK_UP))
	{
		lookAtPosition.y += 50.0f * TimeManager::GetDeltaTime();
	}
	if (InputManager::GetKeyState(VK_DOWN))
	{
		lookAtPosition.y -= 50.0f * TimeManager::GetDeltaTime();
	}
	if (InputManager::GetKeyState(VK_RIGHT))
	{
		lookAtPosition.x += 50.0f * TimeManager::GetDeltaTime();
	}
	if (InputManager::GetKeyState(VK_LEFT))
	{
		lookAtPosition.x -= 50.0f * TimeManager::GetDeltaTime();
	}*/
}

void SubScreen::BeginSubRender()
{
	//�ݵ�� EndSubRender�� ȣ���ؾ���
	subRenderTarget->BeginDraw();
	subRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	subRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
}

void SubScreen::EndSubRender()
{
	subRenderTarget->EndDraw();
}