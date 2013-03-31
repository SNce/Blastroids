#ifndef _ENTITY
#define _ENTITY

namespace EngineHigh
{

// Entity is the container for Components
// Components define the behaviour of an entity

class Entity
{
public:
	unsigned int GetID();
private:
	unsigned int m_ID;
};

}

#endif