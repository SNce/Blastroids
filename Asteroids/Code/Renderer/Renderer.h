#ifndef _RENDERER
#define _RENDERER

#include <Asteroids\Code\Utils\UtilsPCH.h>
#include <Asteroids\Code\Renderer\Driver.h>

namespace Renderer
{

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
	Driver* m_pDriver;
	bool m_bInitialized;
};

}

#endif