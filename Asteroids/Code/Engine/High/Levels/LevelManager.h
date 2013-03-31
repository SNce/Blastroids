#ifndef _LEVEL_MANAGER
#define _LEVEL_MANAGER

#include <list>
#include <Asteroids\Code\Engine\High\Levels\World.h>

namespace EngineHigh
{

class LevelManager
{
public:
	void Initialize(World* world);
	void AddLevel(World* world);
	World* GetNextLevel();
protected:
	// Just a temp container for worlds.
	// List are bad because we dont have random access.
	std::list<World*> _levelList;
	std::list<World*>::const_iterator _levelItr;
};

}

#endif