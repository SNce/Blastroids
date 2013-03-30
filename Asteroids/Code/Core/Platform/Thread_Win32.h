#ifndef _THREAD_WIN32
#define _THREAD_WIN32

#include <Windows.h>
#include <Asteroids\Code\Core\Thread.h>

#define THREAD_STACK_SIZE 256


namespace Core
{

class Thread_Win32 : public Thread
{
public:
	// Allow overrides for future
	virtual void Create();
	virtual void Start();
	virtual void Stop();

private:
	HANDLE m_threadHandle;
};

}

#define OSThread Core::Thread_Win32

#endif