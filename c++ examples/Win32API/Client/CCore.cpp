#include "pch.h"
#include "CCore.h"
#include "CObject.h"

//CCore* CCore::pInst = nullptr;



CCore::CCore()
    :m_hWnd(0), m_ptResolution{}, m_hDC(0)
{
}

CCore::~CCore()
{
    ReleaseDC(m_hWnd, m_hDC);
}

CObject g_obj;

int CCore::init(HWND _hwnd, POINT _ptRes)
{
    m_hWnd = _hwnd;
    m_ptResolution = _ptRes;

    // �ػ󵵿� �°� ������ ũ�� ����
    RECT rt = { 0,0, _ptRes.x, _ptRes.y };
    AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW,true);
                                           //       ����,                ����
    SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

    m_hDC = GetDC(m_hWnd);

    g_obj.m_ptPos = POINT{ m_ptResolution.x / 2, m_ptResolution.y /2  };
    g_obj.m_ptScale = POINT{ 100, 100 };

    // FAILED(E_FAIL); // = true
    //return E_FAIL; // ����
    return S_OK;  // 0
}


void CCore::progress()
{

    update();

    render();

}

void CCore::update()
{
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) // ��Ʈ ����, ������� true�� ���ݴ��� ��
    {
        g_obj.m_ptPos.x -= 1;
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
    {
        g_obj.m_ptPos.x += 1;
    }
}

void CCore::render()
{
    // �׸���
    Rectangle(m_hDC, g_obj.m_ptPos.x - g_obj.m_ptScale.x / 2, g_obj.m_ptPos.x + g_obj.m_ptScale.x / 2,
        g_obj.m_ptPos.y - g_obj.m_ptScale.y / 2, g_obj.m_ptPos.y + g_obj.m_ptScale.y / 2);
}