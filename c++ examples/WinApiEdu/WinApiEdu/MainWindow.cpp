#include "MainWindow.h"
#include "resource.h"
#include <algorithm>
#include "Graphic2D.h"

MainWindow::MainWindow()
{

}

MainWindow::~MainWindow()
{
}

void MainWindow::CrateInstance(HINSTANCE hInst, int width, int height)
{
    // 클래스 등록
    {
        WNDCLASSEXW wcex;

        wcex.cbSize = sizeof(WNDCLASSEX);

        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = WndProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = hInst;
        wcex.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_WINAPIEDU));
        wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPIEDU);
        wcex.lpszClassName = L"WinAPI";
        wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

        RegisterClassExW(&wcex);
    }

    {
        m_hInstance = hInst; // 인스턴스 핸들을 멤버 변수에 저장합니다.

        m_hWnd = CreateWindowW(L"WinAPI", L"임수정", WS_OVERLAPPEDWINDOW,
            10, 10, width, height, nullptr, nullptr, hInst, nullptr);

        m_width = width;
        m_height = height;

        SCENEMANAGER->GetInstance();

        CreateBufferDC();

        ShowWindow(m_hWnd, SW_SHOWDEFAULT);
        UpdateWindow(m_hWnd);

    }
    
}

LRESULT MainWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_KEYDOWN:
            MAIN->OnChar((int)wParam);
            //printf("%c %c\n", wParam, lParam); //wParam이 누른 키 
            break;
        case WM_KEYUP:
            MAIN->OnChar(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;

        //case WM_PAINT:
        //{
        //    PAINTSTRUCT ps;
        //    HDC hdc = BeginPaint(hWnd, &ps);
        //    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        //    // 그리기, 비트맵, 텍스트

        //    MoveToEx(hdc, 10, 10, NULL);
        //    //LineTo(hdc, 500, 500);

        //    //Rectangle(hdc, 100, 100, 800, 600);

        //    //Ellipse(hdc, 300, 300, 400, 600);
        //    POINT tri[4];

        //    tri[0].x = 100;
        //    tri[0].y = 100;
        //    tri[1].x = 200;
        //    tri[1].y = 80;
        //    tri[2].x = 70;
        //    tri[2].y = 170;
        //    tri[3].x = 100;
        //    tri[3].y = 100;

        //    //Polygon(hdc, tri, 4); //3이든 4든 똑같, 안을 채움
        //        //Polyline(hdc, tri, 4); // 라인은 안을 채우지 않음, 점 4개

        //    //TextOut(hdc, 50, 50, L"ABCDEGFH", 8);

        //    //베지어 곡선, 점을 통해 곡선을 그려줌
        //    //PolyBezier(hdc, tri, 4);

        //    int cx = 300;
        //    int cy = 300;
        //    int r = 100;

        //    POINT pt[400];
        //    for (int i = 0; i < 360; i++) // 360도 원 그리기
        //    {
        //        pt[i].x = cx + r * (float)cosf(i * 180 * 3.14);
        //        pt[i].y = cy + r * (float)sinf(i * 180 * 3.14);

        //    }
        //    Polygon(hdc, pt, 360);

        //    EndPaint(hWnd, &ps);
        //}
        //break;
}

void MainWindow::Render()
{
    InvalidateRect(m_hWnd, NULL,false);
    PAINTSTRUCT ps;
    HDC hDC = BeginPaint(m_hWnd, &ps);
    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
    // 그리기, 비트맵, 텍스트

    Graphic2D::DrawRectangle(m_hDC, -2, -2, m_width+4, m_height+4, RGB(255, 255, 255));// 마젠타 배경 투명화함

    // 각 씬은 여기 사이에서만 렌더링
    SCENEMANAGER->Update();
    SCENEMANAGER->Render();

    BitBlt(hDC, 0, 0, m_width, m_height, m_hDC, 0, 0, SRCCOPY);




    EndPaint(m_hWnd, &ps);
    
}

void MainWindow::Update()
{
    MAIN->Update();
}

void MainWindow::CreateBufferDC()
{
    HDC hDC = GetDC(m_hWnd);

    m_hDC = CreateCompatibleDC(hDC);

    HBITMAP hBitmap = CreateCompatibleBitmap(hDC,m_width, m_height);

    SelectObject(m_hDC, hBitmap);

    ReleaseDC(m_hWnd, hDC);

}

