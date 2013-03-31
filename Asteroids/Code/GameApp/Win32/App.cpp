#ifdef _WIN32

#include <Windows.h>
#include <Asteroids\Code\GameApp\GameApp.h>

bool running = true;

HINSTANCE hInstance;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
	switch (message) {
		case WM_SIZE:
		{
			g_GameApp.GetRenderer()->ReshapeWindow(LOWORD(lParam), HIWORD(lParam));
			break;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}


bool createWindow(LPCWSTR title, int width, int height) {
	WNDCLASS windowClass;
	HWND hWnd;
	DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

	hInstance = GetModuleHandle(NULL);

	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc = (WNDPROC) WndProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = NULL;
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = title;

	if (!RegisterClass(&windowClass)) {
		return false;
	}

	hWnd = CreateWindowEx(dwExStyle, title, title, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, width, height, NULL, NULL, hInstance, NULL);

	g_GameApp.Initialize(reinterpret_cast<void*>(hWnd));

	ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

	return true;
}

int WINAPI WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR    lpCmdLine,
                     int       nCmdShow) {
	MSG msg;

	char *orig = "Asteroids";
	size_t origsize = strlen(orig) + 1;
    const size_t newsize = 100;
    size_t convertedChars = 0;
    wchar_t wcstring[newsize];
    mbstowcs_s(&convertedChars, wcstring, origsize, orig, _TRUNCATE);

	createWindow(wcstring, 800, 600);

	g_GameApp.GetRenderer()->SetupScene();
	
	while (running)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		{ 
			if (msg.message == WM_QUIT) 
			{
				running = false;
			}
			else 
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else 
		{
			g_GameApp.Run();
		}
	}

	return (int) msg.wParam;
}

#endif