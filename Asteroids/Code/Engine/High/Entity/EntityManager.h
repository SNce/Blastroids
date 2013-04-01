#ifndef _ENTITY_MANAGER
#define _ENTITY_MANAGER

#include <unordered_map>
#include <Asteroids\Code\Engine\High\Entity\Entity.h>
#include <Asteroids\Code\Engine\High\Component\Component.h>

namespace EngineHigh
{

typedef std::unordered_map<unsigned int, Component*> ComponentEntityMap;
typedef std::unordered_map<size_t, ComponentEntityMap*> ComponentMap;
typedef std::unordered_map<unsigned int, Entity*> EntityMap;

class EntityManager
{
public:

	void AddEntity(Entity* e);

	template <typename C>
	void AddComponent(Entity& e, Component* c);
	
	Component* GetComponent(Entity& e, Component* c);

	template <typename C>
	ComponentEntityMap* GetComponents();

	template <typename C>
	Component* GetComponent(Entity& e);

	void RemoveComponent(Entity& e, Component* c);

	template <typename C>
	void RemoveComponent(Entity& e);

	bool HasComponent(Entity& e, Component* c);

	template <typename C>
	bool HasComponent(Entity& e);

private:

	Component* _GetComponent(Entity& e, size_t hash);
	void _RemoveComponent(Entity& e, size_t hash);
	bool _HasComponent(Entity& e, size_t hash);

	// @ CHANGE THIS SOON!!
	// Using STL containers :o
	ComponentMap _components;
	EntityMap _activeEntities;
	EntityMap _removedEntities;
};

#include <Asteroids\Code\Engine\High\Entity\EntityManager.inl>

}

#endif