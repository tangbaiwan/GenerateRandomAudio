#include <iostream>
#include <fstream>
#include <Windows.h>
#include <Shlwapi.h>
const int SAMPLE_RATE = 11025;  // ������
const int NUM_SECONDS = 5;     // ��Ƶʱ�����룩
const int NUM_CHANNELS = 2;    // ������
const int BITS_PER_SAMPLE = 16; // ÿ��������λ��

#pragma comment(lib, "shlwapi.lib")  //Windows API   PathFileExists
void GenerateRandomAudio(short* buffer, int numSamples)
{
	for (int i = 0; i < numSamples; i++) {
		buffer[i] = rand() % (SHRT_MAX + 1) - SHRT_MAX / 2; // ���������Ƶ����
	}
}

int main()
{
	std::string dbgInfo;
	dbgInfo= "md5StrUp";
	OutputDebugStringA(dbgInfo.c_str());
	OutputDebugStringA("dsadsss");
	OutputDebugStringW(L"sdasdad");
	// ��.wav�ļ�
	//std::ofstream file("bxs_output.wav", std::ios::binary);

	//// WAV�ļ�ͷ
	//WAVEFORMATEX waveFormat;
	//waveFormat.wFormatTag = WAVE_FORMAT_PCM;
	//waveFormat.nChannels = NUM_CHANNELS;
	//waveFormat.nSamplesPerSec = SAMPLE_RATE;
	//waveFormat.nAvgBytesPerSec = SAMPLE_RATE * NUM_CHANNELS * BITS_PER_SAMPLE / 8;
	//waveFormat.nBlockAlign = NUM_CHANNELS * BITS_PER_SAMPLE / 8;
	//waveFormat.wBitsPerSample = BITS_PER_SAMPLE;
	//waveFormat.cbSize = 0;

	//file.write(reinterpret_cast<const char*>(&waveFormat), sizeof(waveFormat));

	//// ������Ƶ����
	//int numSamples = SAMPLE_RATE * NUM_SECONDS;
	//short* audioBuffer = new short[numSamples];
	//GenerateRandomAudio(audioBuffer, numSamples);

	//// д����Ƶ���ݵ��ļ�
	//file.write(reinterpret_cast<const char*>(audioBuffer), numSamples * sizeof(short));

	//file.close();

	//delete[] audioBuffer;

	std::cout << "Audio generation and file writing complete." << std::endl;

	return 0;
}
