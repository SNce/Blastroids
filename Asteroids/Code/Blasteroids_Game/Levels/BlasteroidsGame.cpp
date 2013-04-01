#include <Asteroids\Code\Blasteroids_Game\Levels\BlasteroidsGame.h>
#include <Asteroids\Code\Blasteroids_Game\Levels\Worlds\MainWorld.h>
#include <Asteroids\Code\Engine\High\Entity\EntityManager.h>
#include <Asteroids\Code\Blasteroids_Game\Components\RenderComponent.h>
#include <Asteroids\Code\Renderer\CommandBuffer.h>

namespace Blasteroids
{

BlasteroidsGame::BlasteroidsGame()
{
}

void BlasteroidsGame::Run()
{
	m_pCurrentLevel->Run();
}

void BlasteroidsGame::Initialize()
{
	Blasteroids::MainWorld* mainWorld = new Blasteroids::MainWorld("MainWorld");
	EngineHigh::LevelManager::Initialize(mainWorld);
}

bool BlasteroidsGame::Present(EngineHigh::ComponentEntityMap::const_iterator& itr, Renderer::CommandBuffer& cbuf)
{
	Blasteroids::RenderComponent* rcomp = static_cast<RenderComponent*>((*itr).second);

	if(rcomp)
	{
		rcomp->PresentCommandBuf(cbuf);
		return true;
	}

	return false;
}

EngineHigh::ComponentEntityMap* BlasteroidsGame::GetRenderables()
{
	EngineHigh::EntityManager* entityManager = m_pCurrentLevel->GetEntityManager();

	return entityManager->GetComponents<RenderComponent>();
}

}