#pragma once
#include "stdafx.h"

//������Ʈ ��ü���� �θ� Ŭ�����Դϴ�.
//������ �� �����ӿ�ũ �������� ���� ������ �ʽ��ϴ�.
class Component
{
public:
	Component();
	virtual ~Component();

public:

	virtual void Initialize() {};
	virtual void Update() {};
	virtual void Uninitialze() {};

public:
	bool isActive;
};

