#ifndef _DRIVER
#define _DRIVER

#include <Asteroids\Code\Utils\UtilsPCH.h>

namespace Renderer
{

class Driver
{
public:
	virtual s32 CreateDriverContext(void* params) = 0;
	virtual void SetupScene() = 0;
	virtual void ReshapeWindow(u32 width, u32 height) = 0;
	virtual void SwapTargetBuffers() = 0;

	virtual ~Driver() {};
};

}

#endif