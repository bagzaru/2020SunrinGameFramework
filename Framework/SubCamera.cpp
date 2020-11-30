#include "stdafx.h"
#include "SubCamera.h"
#include "InputManager.h"
#include "TimeManager.h"

SubCamera::SubCamera(Vector2 subScreenSize, D2DApp* d2dApp)
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

SubCamera::~SubCamera()
{
	SAFE_RELEASE(subRenderTarget);
	SAFE_RELEASE(subScreenSprite->bitmap);
	SAFE_DELETE(subScreenSprite);
}

void SubCamera::Update()
{
	//예시적으로 이 화면을 따라다닙니다.
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

void SubCamera::BeginSubRender()
{
	//반드시 EndSubRender도 호출해야함
	subRenderTarget->BeginDraw();
	subRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	subRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
}

void SubCamera::EndSubRender()
{
	subRenderTarget->EndDraw();
}