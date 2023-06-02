#include "pch.h"
#include "CKeyMgr.h"
#include "CCore.h"

// enum KEY와 실제 가상 키 값을 매치시키려고 만든 배열
int g_arrVK[(int)KEY::LAST] =
{
    VK_LEFT,
    VK_RIGHT,
    VK_UP,
    VK_DOWN,
    'Q',
    'W',
    'E',
    'R',
    'T',
    'Y',
    'U',
    'I',
    'O',
    'P',
    'A',
    'S',
    'D',
    'F',
    'G',
    'Z',
    'X',
    'C',
    'V',
    'B',
    
    VK_MENU, //ALT
    VK_CONTROL,// CTRL
    VK_LSHIFT,
    VK_SPACE,
    VK_RETURN, //ENTER
    VK_ESCAPE, //ESC
};


CKeyMgr::CKeyMgr()
{
}

CKeyMgr::~CKeyMgr()
{
}

void CKeyMgr::init()
{
    for (int i = 0; i < (int)KEY::LAST; ++i)
    {
        // 벡터에 요소 추가
        m_vecKey.push_back(KeyInfo{ KEY_STATE::NONE,false });
    }


}

void CKeyMgr::update()
{
    // 윈도우 포커싱 알아내기
    //HWND hMainWnd = CCore::GetInst()->GetMainHwnd();
    HWND hWnd = GetFocus(); // 포커싱된 창이 있다/없다

    if (hWnd != nullptr) // 윈도우 포커싱 중일 때
    {
        for (int i = 0; i < (int)KEY::LAST; ++i)
        {
            // 키가 눌려있는지
            if (GetAsyncKeyState(g_arrVK[i]) & 0x8000) // 비트 연산, 결과값이 true면 지금 눌린 거
            {
                if (m_vecKey[i].prevPush) // 이전에도 눌려있었음
                {
                    m_vecKey[i].state = KEY_STATE::HOLD;
                }
                else
                {
                    m_vecKey[i].state = KEY_STATE::TAP;
                }
                m_vecKey[i].prevPush = true;
            }
            else // 키 안 눌려있음
            {
                if (m_vecKey[i].prevPush) // 이전에는 눌려있었음
                {
                    m_vecKey[i].state = KEY_STATE::AWAY;
                }
                else
                {
                    m_vecKey[i].state = KEY_STATE::NONE;
                }
                m_vecKey[i].prevPush = false;
            }

        }

    }
    else // 윈도우 포커싱 해제 상태
    {
        for (int i = 0; i < (int)KEY::LAST; ++i)
        {
            m_vecKey[i].prevPush = false;
            
            if (m_vecKey[i].state == KEY_STATE::TAP || m_vecKey[i].state == KEY_STATE::HOLD)
            {
                m_vecKey[i].state = KEY_STATE::AWAY;
            }
            else if (m_vecKey[i].state == KEY_STATE::AWAY)
            {
                m_vecKey[i].state = KEY_STATE::NONE;
            }
        }
    }
}
