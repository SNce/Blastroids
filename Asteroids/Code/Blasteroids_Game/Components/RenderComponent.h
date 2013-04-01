#ifndef _RENDER_COMPONENT
#define _RENDER_COMPONENT

#include <Asteroids\Code\Engine\High\Component\Component.h>
#include <Asteroids\Code\Renderer\CommandBuffer.h>

// Using platform specific libs here, since time is limited.
// clean this!
#include <Asteroids\ThirdParty\glm-0.9.3.4\glm\glm.hpp>
#include <Asteroids\ThirdParty\glew-1.9.0\include\GL\glew.h>
#include <Asteroids\ThirdParty\glew-1.9.0\include\GL\wglew.h>
#include <fstream>
#include <vector>

namespace Blasteroids
{

class RenderComponent : public EngineHigh::Component
{
public:
	void Setup();
	void Render();
	void SetShaders(const char* vsh, const char* fsh);
	void SetVertexBuffer(float* vb, int length);
	void LoadMesh(const char* meshFile);
	unsigned int GetProgID() { return m_uiProgID; }
	glm::mat4* GetMvMat() { return &_mvMat; }
	glm::mat4* GetProjectionMat() { return &_projectionMat; }
	unsigned int GetVertexArrayID() { return m_uiVertexArrayID; }
	unsigned int GetPolyCount() { return m_uiPolyCount; }

	void PresentCommandBuf(Renderer::CommandBuffer& cbuf);

private:

	struct AgVertex
	{
		glm::vec3 position;
		glm::vec3 normal;
	};

	glm::mat4 _modelMat;
	glm::mat4 _viewMat;
	glm::mat4 _projectionMat;
	glm::mat4 _mvMat;

	// Hack: for now use opengl here! :/
	// @TODO: Write a shader and material system that
	// abstracts underlying driver.
	//.............................................
	// Ideally this place should only have handles to resources.
	// actual resource loading should be done by the engine.
	char* m_pVertexShader;
	char* m_pFragmentShader;

	GLuint m_uiProgID;

	GLfloat* m_pVertexBuffer;
	unsigned int m_vertexCount;

	GLuint m_uiVertexArrayID;
	GLuint m_uiIndexBuffer;

	unsigned int m_uiVertexCount;
	unsigned int m_uiPolyCount;

	void* m_pVertexNormalBuffer;
	GLuint* m_pPolyBuffer;
	GLuint m_uiVertexBuffer;
	AgVertex* m_pVertices;


};

}

#endif