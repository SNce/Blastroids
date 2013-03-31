#include <Asteroids\Code\GameApp\GameApp.h>

CreateSingleton(Asteroids::GameApp);

namespace Asteroids
{

s32 GameApp::Initialize(void* param)
{
	m_pRenderer = new Renderer::CRenderer();
	m_pTimer = new Core::Timer();

	if(!m_pRenderer->IsInitialized())
	{
		m_pRenderer->Initialize(param);
	}

	return 0;
}

Renderer::CRenderer* GameApp::GetRenderer()
{
	return m_pRenderer;
}

void GameApp::Run()
{
	static unsigned long ticks = 0;

	m_pTimer->Start();

		m_pRenderer->PreRender();
		m_pRenderer->Render();
		m_pRenderer->PostRender();

	ticks = m_pTimer->Stop();
}

}