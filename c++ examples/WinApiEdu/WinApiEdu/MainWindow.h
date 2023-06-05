#pragma once
#include "framework.h"


//�̱��� ���� : ���������� (������ �����غ��� ���� ����
//��ü �� �� ���� ����
// 1. �����ڸ� private�� �����
// 2. GetInstance()�� ���� �����ϵ���

#define MAIN MainWindow::GetInstance()

class S01_Basic; // ���� ����
class S02_Bee; // ���� ����

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

