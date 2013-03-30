#ifndef _DRIVERWOGL
#define _DRIVERWOGL

#include <Windows.h>
#include <Asteroids\Code\Renderer\Driver.h>

#include <Asteroids\ThirdParty\glm-0.9.3.4\glm\glm.hpp>
#include <Asteroids\ThirdParty\glm-0.9.3.4\glm\gtc\matrix_transform.hpp>

namespace Renderer
{

class Driver_WOGL : public Driver
{
public:
	Driver_WOGL() {};

	s32 CreateDriverContext(void* params);
	void SetupScene();
	void ReshapeWindow(u32 width, u32 height);
	void SwapTargetBuffers();

	~Driver_WOGL() {};

private:
	HWND m_pHwnd;
	HGLRC m_Hglrc;
	HDC m_Hdc;

	int m_width;
	int m_height;

	// HACK!
	// @TODO: Implement render states
	glm::mat4 m_modelMat;
	glm::mat4 m_viewMat;
	glm::mat4 m_projectionMat;
	glm::mat4 m_mvMat;

	// HACK!
	// @TODO: Abstract camera
	glm::vec3 m_cameraPos;
	glm::vec3 m_cameraLookat;
	glm::vec3 m_cameraUp;
};

}

#endif