#include <Asteroids\Code\Engine\High\Levels\World.h>

namespace EngineHigh
{

void World::Initialize()
{
	m_pEntityManager = new EntityManager();
	m_pNextWorld = 0;
}

}