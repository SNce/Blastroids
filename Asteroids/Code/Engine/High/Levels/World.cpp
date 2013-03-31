#include <Asteroids\Code\Engine\High\Levels\World.h>
#include <string>

namespace EngineHigh
{

World::World(const char* name)
{
	// safe string copy
	size_t length = strlen(name);
	m_pName = new char[length+1];
	strcpy(m_pName, name);
}

void World::Initialize()
{
	m_pEntityManager = new EntityManager();
}

void World::Run()
{
}

}