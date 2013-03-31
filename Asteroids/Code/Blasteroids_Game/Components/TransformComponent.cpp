#include <Asteroids\Code\Blasteroids_Game\Components\TransformComponent.h>

namespace Blasteroids
{

glm::vec2& TransformComponent::GetPosition()
{
	return _position;
}

const glm::vec2& TransformComponent::GetConstPosition()
{
	return _position;
}

void TransformComponent::SetPosition(float x, float y)
{
	_position.x = x;
	_position.y = y;
}

}