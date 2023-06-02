#include "pch.h"
#include "CKeyMgr.h"
#include "CCore.h"

// enum KEY�� ���� ���� Ű ���� ��ġ��Ű���� ���� �迭
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
        // ���Ϳ� ��� �߰�
        m_vecKey.push_back(KeyInfo{ KEY_STATE::NONE,false });
    }


}

void CKeyMgr::update()
{
    // ������ ��Ŀ�� �˾Ƴ���
    //HWND hMainWnd = CCore::GetInst()->GetMainHwnd();
    HWND hWnd = GetFocus(); // ��Ŀ�̵� â�� �ִ�/����

    if (hWnd != nullptr) // ������ ��Ŀ�� ���� ��
    {
        for (int i = 0; i < (int)KEY::LAST; ++i)
        {
            // Ű�� �����ִ���
            if (GetAsyncKeyState(g_arrVK[i]) & 0x8000) // ��Ʈ ����, ������� true�� ���� ���� ��
            {
                if (m_vecKey[i].prevPush) // �������� �����־���
                {
                    m_vecKey[i].state = KEY_STATE::HOLD;
                }
                else
                {
                    m_vecKey[i].state = KEY_STATE::TAP;
                }
                m_vecKey[i].prevPush = true;
            }
            else // Ű �� ��������
            {
                if (m_vecKey[i].prevPush) // �������� �����־���
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
    else // ������ ��Ŀ�� ���� ����
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
