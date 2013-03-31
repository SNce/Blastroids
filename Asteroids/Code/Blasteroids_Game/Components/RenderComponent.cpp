#include <Asteroids\Code\Blasteroids_Game\Components\RenderComponent.h>
#include <Asteroids\ThirdParty\glm-0.9.3.4\glm\gtc\matrix_transform.hpp>

namespace Blasteroids
{

void RenderComponent::Setup()
{
	glm::vec3 cameraLookat = glm::vec3(0.0f, 0.0f, -3.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 15.0f);
		
	_modelMat = glm::mat4(1.0f);
	_viewMat = glm::lookAt(cameraPos, cameraLookat, cameraUp);
	_projectionMat = glm::perspective(90.0f, 16.0f / 9.0f, 0.1f, 100.0f); 

	_mvMat = _viewMat * _modelMat;
}

void RenderComponent::Render()
{

}

}