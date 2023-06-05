// WinApiEdu.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WinApiEdu.h"
#include <algorithm>
#include "MainWindow.h"


#define MAX_LOADSTRING 100



// Line 그려보기

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

    MAIN->GetInstance();
    MAIN->CrateInstance(hInstance, 1000, 800);

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPIEDU));

    MSG msg;

    // 기본 메시지 루프입니다:
    /*while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        Sleep(10);
        MAIN->Render();
    }*/

    while (true)
    {
        if (PeekMessage(&msg,NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Sleep(5);

            MAIN->Render();
        }
    }

    return (int) msg.wParam;
}

