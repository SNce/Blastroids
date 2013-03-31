#include <Asteroids\Code\Engine\High\Entity\EntityManager.h>

namespace EngineHigh
{

void EntityManager::AddComponent(Entity& e, Component* c)
{
	ComponentMap::const_iterator cmi = _components.find(typeid(c).hash_code());

	// None of the entities have this component
	if(cmi == _components.end())
	{
		// Add it
		ComponentEntityMap* cem = new ComponentEntityMap();
		std::pair<unsigned int, Component*> cPair = std::make_pair(e.GetID(), c);
		cem->insert(cPair);

		std::pair<size_t, ComponentEntityMap*> cePair = std::make_pair(typeid(c).hash_code(), cem);
		_components.insert(cePair);

		return;
	}

	ComponentEntityMap* cem = (*cmi).second;
	ComponentEntityMap::const_iterator cemi = cem->find(e.GetID());

	// This entity does not have this component
	if(cemi == (*cmi).second->end())
	{
		// Add it.
		std::pair<unsigned int, Component*> cPair = std::make_pair(e.GetID(), c);
		cem->insert(cPair);

		return;
	}

	// @TODO
	// If the entity has this component, remove it and add it again.
}

void EntityManager::_RemoveComponent(Entity& e, size_t hash)
{
	ComponentMap::const_iterator cmi = _components.find(hash);

	// None of the entities have this component
	if(cmi == _components.end())
		return;

	ComponentEntityMap* cem = (*cmi).second;
	cem->erase(e.GetID());

	if(cem->empty())
	{
		// Not sure if explicit deletion is required. 
		// unordered_map::erase might take care of it
		delete (*cmi).second;
		_components.erase(hash);
	}
}

Component* EntityManager::_GetComponent(Entity& e, size_t hash)
{
	ComponentMap::const_iterator cmi = _components.find(hash);

	// None of the entities have this component
	if(cmi == _components.end())
		return 0;

	ComponentEntityMap* cem = (*cmi).second;

	ComponentEntityMap::const_iterator cemi = cem->find(e.GetID());

	// Entity does not have this component
	if(cemi == cem->end())
		return 0;

	return (*cemi).second;
}

bool EntityManager::_HasComponent(Entity& e, size_t hash)
{
	ComponentMap::const_iterator cmi = _components.find(hash);

	// Not found
	if(cmi == _components.end())
		return false;

	ComponentEntityMap* cem = (*cmi).second;

	ComponentEntityMap::const_iterator cemi = cem->find(e.GetID());

	if(cemi == cem->end())
		return false;

	return true;
}

void EntityManager::RemoveComponent(Entity& e, Component* c)
{
	_RemoveComponent(e, typeid(c).hash_code());
}

Component* EntityManager::GetComponent(Entity& e, Component* c)
{
	return _GetComponent(e, typeid(c).hash_code());
}

bool EntityManager::HasComponent(Entity& e, Component* c)
{
	return _HasComponent(e, typeid(c).hash_code());
}

}