#ifndef _WORLD
#define _WORLD

#include <Asteroids\Code\Engine\High\Entity\EntityManager.h>

namespace EngineHigh
{

class World
{
public:
	World(const char* name);
	void Initialize();
	virtual void Run();

private:
	EntityManager* m_pEntityManager;

	char* m_pName;
};

}

#endif