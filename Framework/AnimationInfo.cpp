#include "stdafx.h"
#include "AnimationInfo.h"
#include "TimeManager.h"

AnimationInfo::AnimationInfo()
	:RenderInfo(), currentState(0), currentAnimation(nullptr)
{
	initialized = true;
}

AnimationInfo::~AnimationInfo()
{
	for (auto& i : animations)
		SAFE_DELETE(i);
	animations.clear();
}

void AnimationInfo::Render(D2DApp* d2dApp, Transform* transform, Vector2 screenPosition)
{
	if (!d2dApp)
	{
		printf("RenderInfo::Render: d2dApp�� �����ϴ�.\n");
		return;
	}
	ID2D1HwndRenderTarget* renderTarget = d2dApp->GetRenderTarget();
	if (!renderTarget)
	{
		printf("RenderingManger::Render ����, ����Ÿ���� �����ϴ�.\n");
		return;
	}
	UpdateRenderInfo();
	BasicRender(renderTarget, transform, GetSourceRect(),screenPosition);
}

void AnimationInfo::UpdateRenderInfo()
{
	if (!currentAnimation)
		return;
	currentSprite = currentAnimation->UpdateAnim();
}

void AnimationInfo::ChangeAnimation(int state)
{
	Animation* temp = FindAnimationByState(state);
	if (temp)
	{
		currentState = state;
		currentAnimation = temp;
		currentAnimation->Reset();
		currentSprite = currentAnimation->GetCurrentSprite();
	}
	else
	{
		printf("�������� �ʴ� Animation state�Դϴ�.\n");
	}
}

void AnimationInfo::PushBackAnimation(Animation* anim)
{
	animations.push_back(anim);
	if (!currentSprite)
	{
		ChangeAnimation(anim->state);
	}
}

Animation* AnimationInfo::FindAnimationByState(int state)
{
	for (auto& i : animations)
	{
		if (i->state == state)
			return i;				//ã���� ��� �ش� �ִϸ��̼� ��ȯ
	}
	return nullptr;		//���� ��� nullptr ��ȯ

}

D2D1_RECT_F* AnimationInfo::GetSourceRect()
{
	return currentAnimation->GetSourceRect();
}

int AnimationInfo::GetWidth()
{
	if (currentAnimation)
		return currentAnimation->GetAnimationWidth();
	else
		return 0;
}

int AnimationInfo::GetHeight()
{
	if (currentAnimation)
		return currentAnimation->GetAnimationHeight();
	else
		return 0;
}
