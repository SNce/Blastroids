template <typename C>
Component* EntityManager::GetComponent(Entity& e)
{
	return _GetComponent(e, typeid(C).hash_code());
}

template <typename C>
void EntityManager::RemoveComponent(Entity& e)
{
	_RemoveComponent(e, typeid(C).hash_code());
}

template <typename C>
bool EntityManager::HasComponent(Entity& e)
{
	return _HasComponent(e, typeid(C).hash_code());
}

template <typename C>
void EntityManager::AddComponent(Entity& e, Component* c)
{
	size_t hash = typeid(C).hash_code();
	ComponentMap::const_iterator cmi = _components.find(hash);

	// None of the entities have this component
	if(cmi == _components.end())
	{
		// Add it
		EngineHigh::ComponentEntityMap* cem = new EngineHigh::ComponentEntityMap();
		std::pair<unsigned int, EngineHigh::Component*> cPair = std::make_pair(e.GetID(), c);
		cem->insert(cPair);

		std::pair<size_t, ComponentEntityMap*> cePair = std::make_pair(hash, cem);
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

template <typename C>
ComponentEntityMap* EntityManager::GetComponents()
{
	size_t hash = typeid(C).hash_code();
	ComponentMap::const_iterator cmi = _components.find(hash);

	// None of the entities have this component
	if(cmi == _components.end())
		return 0;

	return (*cmi).second;
}