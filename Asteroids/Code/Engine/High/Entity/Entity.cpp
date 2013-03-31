#include <Asteroids\Code\Engine\High\Entity\Entity.h>

namespace EngineHigh
{

unsigned int Entity::ms_nextID = 0;

Entity::Entity()
{
	Initialize();
}

void Entity::Initialize()
{
	m_ID = ms_nextID;
	++ms_nextID;
}

unsigned int Entity::GetID()
{
	return m_ID;
}

}