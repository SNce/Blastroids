#ifndef _RENDER_COMPONENT
#define _RENDER_COMPONENT

#include <Asteroids\Code\Engine\High\Component\Component.h>

#include <Asteroids\ThirdParty\glm-0.9.3.4\glm\glm.hpp>

namespace Blasteroids
{

class RenderComponent : public EngineHigh::Component
{
public:
	void Setup();
	void Render();
private:
	glm::mat4 _modelMat;
	glm::mat4 _viewMat;
	glm::mat4 _projectionMat;
	glm::mat4 _mvMat;
};

}

#endif