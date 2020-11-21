#pragma once
#include "stdafx.h"

//������ ������ ���� Ŭ�����Դϴ�.
class WinApp
{
public:
	WinApp();
private:
	//������ �ڵ�
	HWND hWnd;
	
	//����, ����
	static int width;
	static int height;
	static float widthF;
	static float heightF;

	//â��� ����
	bool isFullScreen;
public:
	//������ �ڵ� ���� �޾ƿɴϴ�.
	HWND GetHWND();

	//ȭ���� ����,���θ� �޾ƿɴϴ�.
	static int GetScreenWidth();
	static int GetScreenHeight();
	static float GetScreenWidthF();
	static float GetScreenHeightF();

	//â���� ���θ� �޾ƿɴϴ�.
	bool GetFullScreened();
public:
	//Window�� �ʱ�ȭ�մϴ�.
	//â�� ����, ȭ�� �� �����ϴ� ���� ������ �մϴ�.
	bool Initialize(const wchar_t* title, int width, int height, bool isFullScreen);

	
public:
	//������ ���ν��� �Լ��Դϴ�.
	//������ �޽��� �Է¿� ���� ó���� �̷����ϴ�.
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};

