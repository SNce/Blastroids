#ifndef _GAMEAPP
#define _GAMEAPP

#include <Asteroids\Code\Utils\UtilsPCH.h>
#include <Asteroids\Code\Renderer\Renderer.h>
#include <Asteroids\Code\Core\Timer.h>

namespace Application
{

class GameApp : public Util::Singleton<GameApp>
{
public:
	s32 Initialize(void* param);
	void Run();
	Renderer::CRenderer* GetRenderer();

private:
	Renderer::CRenderer *m_pRenderer;
	Core::Timer *m_pTimer;
};

}

#define g_GameApp Application::GameApp::instance()

#endif