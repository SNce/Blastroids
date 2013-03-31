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