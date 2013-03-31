#ifndef _MAIN_WORLD
#define _MAIN_WORLD

#include <Asteroids\Code\Engine\High\Levels\World.h>

namespace Blasteroids
{

class MainWorld : public EngineHigh::World
{
public:
	MainWorld(const char* name) : World(name) { Initialize(); }
	virtual void Initialize();
	virtual void Run();

private:
	EngineHigh::Entity* m_pPlayerEntity;
};

}

#endif