#include <Asteroids\Code\GameApp\GameApp.h>

CreateSingleton(Asteroids::GameApp);

namespace Asteroids
{

s32 GameApp::Initialize(void* param)
{
	m_pRenderer = new TRenderer();

	if(!m_pRenderer->IsInitialized())
	{
		m_pRenderer->Initialize(param);
	}

	return 0;
}

TRenderer* GameApp::GetRenderer()
{
	return m_pRenderer;
}

void GameApp::Run()
{
}

}