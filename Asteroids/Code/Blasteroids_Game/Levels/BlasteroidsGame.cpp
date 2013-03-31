#include <Asteroids\Code\Blasteroids_Game\Levels\BlasteroidsGame.h>

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
	EngineHigh::World* mainWorld = new EngineHigh::World("Game");
	EngineHigh::LevelManager::Initialize(mainWorld);
}

}