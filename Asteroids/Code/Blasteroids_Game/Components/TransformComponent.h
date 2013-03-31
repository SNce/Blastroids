#ifndef _TRANSFORM_COMPONENT
#define _TRANSFORM_COMPONENT

#include <Asteroids\Code\Engine\High\Component\Component.h>
#include <Asteroids\ThirdParty\glm-0.9.3.4\glm\glm.hpp>

namespace Blasteroids
{

class TransformComponent : public EngineHigh::Component
{
public:
	glm::vec2& GetPosition();
	const glm::vec2& GetConstPosition();
	void SetPosition(float x, float y);
private:
	glm::vec2 _position;
};

}

#endif