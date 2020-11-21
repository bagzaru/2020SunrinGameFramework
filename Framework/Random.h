#pragma once
#include "stdafx.h"

//������ ������ �Լ��Դϴ�.
//C++���� �����ϴ� ����� �� ���� �������ϴ�.
class Random
{
public:
	std::random_device randomDevice;
	std::mt19937 mersenne;

	Random();
public:
	//���� ���� ���� �� ���� �Լ��Դϴ�.
	//���� ������Ʈ ��ü�� �޾ƿɴϴ�.
	static Random* GetInstance();

	//static �Լ��ν� ������ �����ϸ� �ش� ���� ���� ���� ���� �޾ƿɴϴ�.
	static float Range(float min, float max);
	static int Range(int min, int max);
};

