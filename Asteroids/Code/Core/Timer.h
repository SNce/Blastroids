#ifndef _TIMER
#define _TIMER

#ifdef _WIN32
	#include <Asteroids\Code\Core\Platform\Timer_Win32.h>
#endif

namespace Core
{

class Timer : public TimerImpl
{
public:
	Timer() {}
	~Timer() {}
};

}

#endif