#include <Asteroids\Code\Renderer\Platform\Win32\Driver_WOGL.h>

#include <Asteroids\ThirdParty\glew-1.9.0\include\GL\glew.h>
#include <Asteroids\ThirdParty\glew-1.9.0\include\GL\wglew.h>

namespace Renderer
{

s32 DriverImpl::CreateDriverContext(void* params)
{
	if(!params)
		return -1;

	m_pHwnd = reinterpret_cast<HWND>(params); 

	m_Hdc = GetDC(m_pHwnd); 

	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 32;
	pfd.iLayerType = PFD_MAIN_PLANE;

	s32 nPixelFormat = ChoosePixelFormat(m_Hdc, &pfd);
	if (nPixelFormat == 0)
			return -1;

	BOOL bResult = SetPixelFormat(m_Hdc, nPixelFormat, &pfd);
	if (!bResult)
		return -1;

	// Make a OpenGL 2.1 context as default.
	HGLRC tempOGLContext = wglCreateContext(m_Hdc);
	wglMakeCurrent(m_Hdc, tempOGLContext);

	GLenum error = glewInit();
	if (error != GLEW_OK)
		return -1;

	int attributes[] = 
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 2,
		WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		0
	};

	// Create and set an OpenGL 3.2 context if supported.
	if (wglewIsSupported("WGL_ARB_create_context") == 1) 
	{ 
		m_Hglrc = wglCreateContextAttribsARB(m_Hdc, 0, attributes);
		wglMakeCurrent(0, 0);
		wglDeleteContext(tempOGLContext);
		wglMakeCurrent(m_Hdc, m_Hglrc);
	}
	// If the 3.2 context is not supported revert back to 2.1
	else 
	{
		m_Hglrc = tempOGLContext;
	}

	int glVersion[2] = {-1, -1};
	glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
	glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);

	//std::cout << "Using OpenGL: " << glVersion[0] << "." << glVersion[1] << std::endl;

	return 0;
}

void DriverImpl::SetupScene()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set the clear color

	m_cameraLookat = glm::vec3(0.0f, 0.0f, -3.0f);
	m_cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	m_cameraPos = glm::vec3(0.0f, 0.0f, 15.0f);
		
	m_modelMat = glm::mat4(1.0f);
	m_viewMat = glm::lookAt(m_cameraPos, m_cameraLookat, m_cameraUp);
	m_projectionMat = glm::perspective(90.0f, 16.0f / 9.0f, 0.1f, 100.0f); 
	m_projectionMat = glm::ortho(0.0f, 400.0f, 0.0f, 400.0f, -1.0f, 1.0f);

	m_mvMat = m_viewMat * m_modelMat;
}

void DriverImpl::ReshapeWindow(u32 width, u32 height)
{
}

void DriverImpl::SwapTargetBuffers()
{
	SwapBuffers(m_Hdc);
}

}