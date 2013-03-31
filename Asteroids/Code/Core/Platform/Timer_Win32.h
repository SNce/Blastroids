#ifndef _TIMER_WIN32
#define _TIMER_WIN32

#include <Asteroids\Code\Utils\UtilsPCH.h>
#include <Windows.h>

namespace Core
{

class TimerImpl
{
public:
	TimerImpl();
	~TimerImpl() {};

	void Start();
	unsigned long Stop();

private:
	bool m_bUsePerformanceTimer;

	LARGE_INTEGER _counterFreq;
	LARGE_INTEGER _before_p;
	LARGE_INTEGER _after_p;

	LONGLONG _lastTime_p;

	DWORD _before;
	DWORD _after;
	DWORD _lastTime;
};

}

#endif