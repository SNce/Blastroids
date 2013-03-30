#include <Asteroids\Code\Renderer\Renderer.h>

namespace Renderer
{

s32 CRenderer::Initialize(void* params)
{
	m_pDriver = new Driver();

	m_pDriver->CreateDriverContext(params);
	return 0;
}

void CRenderer::ReshapeWindow(u32 width, u32 height)
{

}

}

