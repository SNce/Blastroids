#ifndef _COMMAND_BUFFER
#define _COMMAND_BUFFER

#include <Asteroids\ThirdParty\glm-0.9.3.4\glm\glm.hpp>

namespace Renderer
{

struct CommandBuffer
{
	unsigned int progID;
	glm::mat4* mvMat;
	glm::mat4* projectionMat;

	unsigned int vertexArrayID;
	unsigned int polyCount;
};

}

#endif