#ifndef _DRIVER
#define _DRIVER

#include <Asteroids\Code\Utils\UtilsPCH.h>

#include <Asteroids\Code\Renderer\Platform\Win32\Driver_WOGL.h>

namespace Renderer
{

class DriverImpl;

class Driver : public DriverImpl
{
public:
	Driver() {};
	~Driver() {};

private:
	u32 dummy;
};

}

#endif