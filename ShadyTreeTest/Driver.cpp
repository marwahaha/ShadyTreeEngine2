#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include "MathLib.h"

#include "GraphicsDevice.h"
#include "GraphicsDeviceFactory.h"

#include "GraphicsTestUser.h"
#include "WindowFactory.h"
#include "ShadyTree_DLLAPI.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

ST_API HWND ghMainWnd;
ST_API HINSTANCE ghInstance;

GraphicsDevice* device;
GraphicsTestUser* puser;

void update();
void draw();

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    //_CrtSetBreakAlloc(172);

    if(!GenerateWindow(hInstance, nShowCmd, WndProc))
        return 0;

    device = generateGraphicsDevice(DeviceAPI::DirectX11);
    if( device->Init() )
        return 1;

    GraphicsTestUser user(device);
    user.init();
    puser = &user;

    // Main message loop
    MSG msg = {0};
    while( WM_QUIT != msg.message )
    {
        if( PeekMessage( &msg, nullptr, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
        {
            update();
            draw();
        }
    }

    device->Free();
    delete device;

    return ( int )msg.wParam;

    return 0;
}

void update()
{

}
void draw()
{
    puser->testdraw();
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

    switch(msg)
    {
        case WM_LBUTTONDOWN:
            MessageBox(0, L"Hello, World", L"Hello", MB_OK);
            break;

        case WM_KEYDOWN:
            if(wParam == VK_ESCAPE)
            DestroyWindow(ghMainWnd);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}