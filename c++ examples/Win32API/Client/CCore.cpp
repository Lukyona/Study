#include "pch.h"
#include "CCore.h"
#include "CObject.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CPathMgr.h"


//CCore* CCore::pInst = nullptr;



CCore::CCore()
    :m_hWnd(0), m_ptResolution{}, m_hDC(0), m_hBit(0), m_memDC(0)
{
}

CCore::~CCore()
{
    ReleaseDC(m_hWnd, m_hDC);

    // CreateComapatibleDC�� ���� �� Delete�� �����
    DeleteDC(m_memDC);
    DeleteObject(m_hBit);
}


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

    // ���� ���۸� �뵵�� ��Ʈ�ʰ� DC �����
    m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
    m_memDC = CreateCompatibleDC(m_hDC);

    HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_memDC, m_hBit);
    DeleteObject(hOldBitmap);

    // �Ŵ����� �ʱ�ȭ
    CPathMgr::GetInst()->init();
    CTimeMgr::GetInst()->init();
    CKeyMgr::GetInst()->init();
    CSceneMgr::GetInst()->init();


    // FAILED(E_FAIL); // = true
    //return E_FAIL; // ����
    return S_OK;  // 0
}


void CCore::progress()
{
    CTimeMgr::GetInst()->update();
    CKeyMgr::GetInst()->update();
    CSceneMgr::GetInst()->update();


    // Rendering
    //ȭ�� Clear
    Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.x + 1);


    CSceneMgr::GetInst()->render(m_memDC);

    //     ������,                                          ������ DC, 
    BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);

    //CTimeMgr::GetInst()->render();
}


