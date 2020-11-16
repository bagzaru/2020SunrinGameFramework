#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <random>

//���̷�Ʈx ���� ���
#include <d2d1.h>
#include <d2d1helper.h>

//COM
#include <wincodec.h>

//FONT
#include <dwrite.h>

//SOUND
#include <xaudio2.h>
#include <mfapi.h>		//wmf
#include <mfidl.h>
#include <mfreadwrite.h>

//�޸� ���� üũ��
//main �Լ� �������� _CrtDumpMemoryLeaks(); �߰����ָ� Ȯ�� ����
//#include "CheckMemoryLeak.h"

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "WindowsCodecs.lib")
#pragma comment(lib, "Winmm.lib")//�̰�

//Font
#pragma comment(lib, "Dwrite.lib")

//SOUND
#pragma comment (lib, "Xaudio2.lib")
#pragma comment (lib, "mfreadwrite.lib")
#pragma comment (lib, "mfplat.lib")
#pragma comment (lib, "mfuuid")


#ifndef _DEBUG
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#else
#    pragma comment(linker, "/SUBSYSTEM:CONSOLE /ENTRY:mainCRTStartup")
#endif


#define SAFE_RELEASE(p) { if(p){p->Release();} p=NULL; }
#define SAFE_DELETE(p) {if(p!=nullptr){delete(p);} p=nullptr; }
#define PI 3.141592653589793f
#define RADTOEULER -180.0f/PI

typedef D2D1_POINT_2F Point;