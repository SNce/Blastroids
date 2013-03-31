#include <Asteroids\Code\Core\Platform\Timer_Win32.h>
#include <algorithm>

namespace Core
{

TimerImpl::TimerImpl() 
{
	m_bUsePerformanceTimer = false;
	if(QueryPerformanceFrequency(&_counterFreq))
	{
		m_bUsePerformanceTimer = true;
	}

	_before_p.HighPart = 0;
	_before_p.LowPart = 0;
	_before = 0;

	_after_p.HighPart = 0;
	_after_p.LowPart = 0;
	_after = 0;

	_lastTime = 0;
	_lastTime_p = 0;
}

void TimerImpl::Start()
{
	if(m_bUsePerformanceTimer)
	{
		QueryPerformanceCounter(&_before_p);
	}

	_before = GetTickCount();
}

unsigned long TimerImpl::Stop()
{
	LONGLONG perfTime = 0;
	unsigned long perfTicks;
	
	if(m_bUsePerformanceTimer)
	{
		QueryPerformanceCounter(&_after_p);
		perfTime = _after_p.QuadPart - _before_p.QuadPart;
		perfTicks = (unsigned long) (1000 * perfTime / _counterFreq.QuadPart);
	}

	_after = GetTickCount();
	unsigned long ticks = _after - _before;

	// if perf timer is being used check for a glitch.
	if(m_bUsePerformanceTimer)
	{
		long glitch = perfTicks - ticks;
		if(glitch > 100 || glitch < -100)
		{
			LONGLONG fix = (std::min)(glitch * _counterFreq.QuadPart / 1000, perfTime - _lastTime_p);
			_before_p.QuadPart += fix;
			perfTime -= fix;

			// Re-calculate milliseconds
			perfTicks = (unsigned long) (1000 * perfTime / _counterFreq.QuadPart);
		}

		_lastTime_p = perfTime;

		return perfTicks;
	}
	
	_lastTime = ticks;
	return ticks;
}

}