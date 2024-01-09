#include <iostream>
#include <fstream>
#include <Windows.h>

const int SAMPLE_RATE = 44100;  // 采样率
const int NUM_SECONDS = 5;     // 音频时长（秒）
const int NUM_CHANNELS = 1;    // 单声道
const int BITS_PER_SAMPLE = 16; // 每个样本的位数

void GenerateRandomAudio(short* buffer, int numSamples)
{
	for (int i = 0; i < numSamples; i++) {
		buffer[i] = rand() % (SHRT_MAX + 1) - SHRT_MAX / 2; // 生成随机音频数据
	}
}

int main()
{
	// 打开.wav文件
	std::ofstream file("output.wav", std::ios::binary);

	// WAV文件头
	WAVEFORMATEX waveFormat;
	waveFormat.wFormatTag = WAVE_FORMAT_PCM;
	waveFormat.nChannels = NUM_CHANNELS;
	waveFormat.nSamplesPerSec = SAMPLE_RATE;
	waveFormat.nAvgBytesPerSec = SAMPLE_RATE * NUM_CHANNELS * BITS_PER_SAMPLE / 8;
	waveFormat.nBlockAlign = NUM_CHANNELS * BITS_PER_SAMPLE / 8;
	waveFormat.wBitsPerSample = BITS_PER_SAMPLE;
	waveFormat.cbSize = 0;

	file.write(reinterpret_cast<const char*>(&waveFormat), sizeof(waveFormat));

	// 生成音频数据
	int numSamples = SAMPLE_RATE * NUM_SECONDS;
	short* audioBuffer = new short[numSamples];
	GenerateRandomAudio(audioBuffer, numSamples);

	// 写入音频数据到文件
	file.write(reinterpret_cast<const char*>(audioBuffer), numSamples * sizeof(short));

	file.close();

	delete[] audioBuffer;

	std::cout << "Audio generation and file writing complete." << std::endl;

	return 0;
}
