#ifndef _DRIVER
#define _DRIVER

#include <Asteroids\Code\Utils\UtilsPCH.h>

#ifdef _WIN32
	#ifdef _OGL
		#include <Asteroids\Code\Renderer\Platform\Win32\Driver_WOGL.h>
	#endif
#endif

namespace Renderer
{

class DriverImpl;

class Driver : public DriverImpl
{
public:
	Driver() {};
	~Driver() {};
};

}

#endif