#include <Asteroids\Code\Blasteroids_Game\Levels\BlasteroidsGame.h>
#include <Asteroids\Code\Blasteroids_Game\Levels\Worlds\MainWorld.h>

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
	mainWorld->Initialize();
	EngineHigh::LevelManager::Initialize(mainWorld);
}

}