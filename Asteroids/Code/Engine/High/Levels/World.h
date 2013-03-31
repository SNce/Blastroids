#ifndef _WORLD
#define _WORLD

#include <Asteroids\Code\Engine\High\Entity\EntityManager.h>

namespace EngineHigh
{

class World
{
public:
	void Initialize();
private:
	EntityManager* m_pEntityManager;
	World* m_pNextWorld;
};

}

#endif