#include <Asteroids\Code\Engine\High\Levels\LevelManager.h>

namespace EngineHigh
{

void LevelManager::Initialize(World* world)
{
	_levelList.push_back(world);
	_levelItr = _levelList.begin();
	m_pCurrentLevel = world;
}

void LevelManager::AddLevel(World* world)
{
	_levelList.push_back(world);
}

World* LevelManager::GetNextLevel()
{
	return *(++_levelItr);
}

World* LevelManager::CurrentLevel()
{
	return m_pCurrentLevel;
}


}