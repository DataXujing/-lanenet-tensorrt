#pragma once
#ifndef MYTIMER_H
#define MYTIMER_H
#include <windows.h>

class MyTimer
{
private:
	LONGLONG _freq;
	LARGE_INTEGER _begin;
	LARGE_INTEGER _end;

public:
	long costTime;            // ���ѵ�ʱ��(��ȷ��΢��)

public:
	MyTimer()
	{
		LARGE_INTEGER tmp;
		QueryPerformanceFrequency(&tmp);
		_freq = tmp.QuadPart;
		costTime = 0;
	}

	void Start()            // ��ʼ��ʱ
	{
		QueryPerformanceCounter(&_begin);
	}

	void End()                // ������ʱ
	{
		QueryPerformanceCounter(&_end);
		costTime = (long)((_end.QuadPart - _begin.QuadPart) * 1000000 / _freq);
	}

	void Reset()            // ��ʱ��0
	{
		costTime = 0;
	}
};
#endif
