#include <Asteroids\Code\GameApp\GameApp.h>

CreateSingleton(Application::GameApp);

namespace Application
{

s32 GameApp::Initialize(void* param)
{
	m_pRenderer = new Renderer::CRenderer();
	m_pTimer = new Core::Timer();

	if(!m_pRenderer->IsInitialized())
	{
		m_pRenderer->Initialize(param);
	}

	game = new Blasteroids::BlasteroidsGame();
	game->Initialize();

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
		
		game->Run();

		m_pRenderer->PreRender();

		EngineHigh::ComponentEntityMap* renderables = game->GetRenderables();
		EngineHigh::ComponentEntityMap::const_iterator itr;

		for(itr = renderables->begin(); itr != renderables->end(); itr++)
		{
			Renderer::CommandBuffer cbuf;
			game->Present(itr, cbuf);

			m_pRenderer->Render(&cbuf);
		}

		m_pRenderer->PostRender();

	ticks = m_pTimer->Stop();
}

}