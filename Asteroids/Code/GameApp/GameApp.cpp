#include <Asteroids\Code\GameApp\GameApp.h>

CreateSingleton(Asteroids::GameApp);

namespace Asteroids
{

s32 GameApp::Initialize(void* param)
{
	m_pRenderer = new Renderer::CRenderer();

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
}

}