#pragma once
#include "framework.h"


//싱글톤 패턴 : 디자인패턴 (포폴에 적용해보는 것이 좋음
//객체 단 한 개만 생성
// 1. 생성자를 private로 만들기
// 2. GetInstance()를 통해 접근하도록

#define MAIN MainWindow::GetInstance()

class S01_Basic; // 전방 선언
class S02_Bee; // 전방 선언

class MainWindow
{
private:
    HINSTANCE m_hInstance = nullptr;
    HWND m_hWnd = nullptr;
    HDC m_hDC = nullptr;

    MainWindow();

    int m_width = 0;
    int m_height = 0;
    
    int m_char = NULL;

public:
    ~MainWindow();

    void CrateInstance(HINSTANCE hInst, int width, int height);
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void Render();
    void Update();

    void CreateBufferDC();
    int GetCharacter() {return m_char;}
    int GetWidth() { return m_width; }
    int GetHeight() { return m_height; }
    HWND GetWindowHandle() { return m_hWnd; }

    void OnChar(int c) { m_char = c; }


    static MainWindow* GetInstance()
    {
        static MainWindow singleton;
        return &singleton;
    }

    HDC GetHDC() { return m_hDC; }

public:

};

