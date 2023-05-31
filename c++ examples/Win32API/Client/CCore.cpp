#include "pch.h"
#include "CCore.h"
#include "CObject.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"


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
    CTimeMgr::GetInst()->init();
    CKeyMgr::GetInst()->init();

    g_obj.SetPos(Vec2((float)(m_ptResolution.x / 2), (float)(m_ptResolution.y /2)));
    g_obj.SetScale(Vec2( 100, 100 ));

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
    Vec2 vPos = g_obj.GetPos();

    if (GetAsyncKeyState(VK_LEFT) & 0x8000) // ��Ʈ ����, ������� true�� ���ݴ��� ��
    {
        vPos.x -= 0.01f;
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
    {
        vPos.x += 0.01f;
    }
    g_obj.SetPos(vPos);
}

void CCore::render()
{
    Vec2 vPos = g_obj.GetPos();
    Vec2 vScale = g_obj.GetScale();

    // �׸���
    Rectangle(m_hDC, int(vPos.x - vScale.x / 2.f), int(vPos.y - vScale.y / 2.f),
        int(vPos.x + vScale.x / 2.f), int(vPos.y + vScale.y / 2.f));
}