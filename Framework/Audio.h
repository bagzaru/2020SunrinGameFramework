#pragma once
#include "stdafx.h"

class Audio
{
public:
	Audio();
	~Audio();

	IXAudio2* xaudio2;	//XAudio2 ���� �ν��Ͻ�
	IXAudio2MasteringVoice* masterVoice;	//������ ���̽�
	IMFAttributes* sourceReaderConfiguration;

	bool Initialize();
	void Uninitialize();
	bool LoadFile(const wchar_t* path, std::vector<BYTE>& audioData, WAVEFORMATEX** waveFormatEx, unsigned int& waveLength);

	static Audio* GetInstance();

};