#ifndef _BLASTEROIDS_GAME
#define _BLASTEROIDS_GAME

#include <Asteroids\Code\Engine\High\Levels\LevelManager.h>

namespace Blasteroids
{

class BlasteroidsGame : public EngineHigh::LevelManager
{
public:
	BlasteroidsGame();
	~BlasteroidsGame();

	void Initialize();

	void Run();
};

}

#endif