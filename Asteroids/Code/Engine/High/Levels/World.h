#ifndef _WORLD
#define _WORLD

#include <Asteroids\Code\Engine\High\Entity\EntityManager.h>

namespace EngineHigh
{

class World
{
public:
	World(const char* name);
	virtual void Initialize();
	virtual void Run();

protected:
	EntityManager* m_pEntityManager;

	char* m_pName;
};

}

#endif