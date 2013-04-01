#ifndef _BLASTEROIDS_GAME
#define _BLASTEROIDS_GAME

#include <Asteroids\Code\Engine\High\Levels\LevelManager.h>
#include <Asteroids\Code\Renderer\CommandBuffer.h>

namespace Blasteroids
{

class BlasteroidsGame : public EngineHigh::LevelManager
{
public:
	BlasteroidsGame();
	~BlasteroidsGame();

	void Initialize();

	void Run();

	EngineHigh::ComponentEntityMap* GetRenderables();
	bool Present(EngineHigh::ComponentEntityMap::const_iterator& itr, Renderer::CommandBuffer& cbuf);
};

}

#endif