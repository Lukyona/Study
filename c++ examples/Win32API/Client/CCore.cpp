#include "pch.h"
#include "CCore.h"
#include "CObject.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"


//CCore* CCore::pInst = nullptr;



CCore::CCore()
    :m_hWnd(0), m_ptResolution{}, m_hDC(0), m_hBit(0), m_memDC(0)
{
}

CCore::~CCore()
{
    ReleaseDC(m_hWnd, m_hDC);

    // CreateComapatibleDC로 만든 건 Delete로 지우기
    DeleteDC(m_memDC);
    DeleteObject(m_hBit);
}

CObject g_obj;

int CCore::init(HWND _hwnd, POINT _ptRes)
{
    m_hWnd = _hwnd;
    m_ptResolution = _ptRes;

    // 해상도에 맞게 윈도우 크기 조정
    RECT rt = { 0,0, _ptRes.x, _ptRes.y };
    AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW,true);
                                           //       가로,                세로
    SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

    m_hDC = GetDC(m_hWnd);

    // 이중 버퍼링 용도의 비트맵과 DC 만들기
    m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
    m_memDC = CreateCompatibleDC(m_hDC);

    HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_memDC, m_hBit);
    DeleteObject(hOldBitmap);


    CTimeMgr::GetInst()->init();
    CKeyMgr::GetInst()->init();
    CSceneMgr::GetInst()->init();

    g_obj.SetPos(Vec2((float)(m_ptResolution.x / 2), (float)(m_ptResolution.y /2)));
    g_obj.SetScale(Vec2( 100, 100 ));

    // FAILED(E_FAIL); // = true
    //return E_FAIL; // 음수
    return S_OK;  // 0
}


void CCore::progress()
{
    CTimeMgr::GetInst()->update();
    CKeyMgr::GetInst()->update();

    update();

    render();

}

void CCore::update()
{
    Vec2 vPos = g_obj.GetPos();

    if (CKeyMgr::GetInst()->GetKeyState(KEY::LEFT) == KEY_STATE::HOLD)   
    {
        vPos.x -= 100.f * CTimeMgr::GetInst()->GetfDT();
    }
    
    if (CKeyMgr::GetInst()->GetKeyState(KEY::RIGHT) == KEY_STATE::HOLD)
    {
        vPos.x += 100.f * CTimeMgr::GetInst()->GetfDT();

    }
    g_obj.SetPos(vPos);
}

void CCore::render()
{
    //화면 Clear
    Rectangle(m_memDC, -1,-1, m_ptResolution.x + 1, m_ptResolution.x + 1);

    Vec2 vPos = g_obj.GetPos();
    Vec2 vScale = g_obj.GetScale();

    // 그리기
    Rectangle(m_memDC, int(vPos.x - vScale.x / 2.f), int(vPos.y - vScale.y / 2.f),
        int(vPos.x + vScale.x / 2.f), int(vPos.y + vScale.y / 2.f));

    //     목적지,                                          전달할 DC, 
    BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);
}