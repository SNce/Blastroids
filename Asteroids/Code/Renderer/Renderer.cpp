#include <Asteroids\Code\Renderer\Renderer.h>

namespace Renderer
{

s32 CRenderer::Initialize(void* params)
{
	m_pDriver = new Driver();

	m_pDriver->CreateDriverContext(params);
	return 0;
}

void CRenderer::SetupScene()
{
	m_pDriver->SetupScene();
}

void CRenderer::ReshapeWindow(u32 width, u32 height)
{
	m_pDriver->ReshapeWindow(width, height);
}

void CRenderer::PreRender()
{
	m_pDriver->Clear();
}

void CRenderer::Render(CommandBuffer* cbuf)
{
	m_pDriver->RenderScene(cbuf);
}

void CRenderer::PostRender()
{
	m_pDriver->SwapTargetBuffers();
}

}

