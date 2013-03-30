#ifndef _THREAD
#define _THREAD

namespace Core
{

class Thread
{
public:
	virtual void Create() = 0;
	virtual void Start() = 0;
	virtual void Stop() = 0;
};

}

#endif