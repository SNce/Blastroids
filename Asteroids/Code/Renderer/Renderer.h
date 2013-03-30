#ifndef _RENDERER
#define _RENDERER

#include <Asteroids\Code\Utils\UtilsPCH.h>
#include <Asteroids\Code\Renderer\Driver.h>

#ifdef _WIN32
	#ifdef _OGL
		#include <Asteroids\Code\Renderer\Platform\Win32\Driver_WOGL.h>
	#endif
#endif

namespace Renderer
{

template <typename DriverType>
class CRenderer
{
public:
	CRenderer() : m_bInitialized(false) 
	{
		m_pDriver = 0;
	}

	s32 Initialize(void* params); 
	void ReshapeWindow(u32 w, u32 h);
	void SetupScene();
	bool IsInitialized() { return m_bInitialized; }

private:
	DriverType* m_pDriver;
	bool m_bInitialized;
};

#include "Renderer.inl"

}

#ifdef _WIN32
	#ifdef _OGL
		typedef Renderer::CRenderer<Renderer::Driver_WOGL> TRenderer;
	#endif
#endif

#endif