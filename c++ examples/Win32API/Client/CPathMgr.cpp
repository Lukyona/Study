#include "pch.h"
#include "CPathMgr.h"
#include "CCore.h"

CPathMgr::CPathMgr()
    : m_contentPath{}
{

}

CPathMgr::~CPathMgr()
{

}

void CPathMgr::init()
{
    GetCurrentDirectory(255, m_contentPath);

    int len = wcslen(m_contentPath);

    for (int i = len - 1; i >= 0; --i)
    {
        if (m_contentPath[i] == '\\')
        {
            m_contentPath[i] = '\0';    
            break;
        }
    }

    // 문자열 이어붙이기
    wcscat_s(m_contentPath, 255, L"\\bin\\content");

    SetWindowText(CCore::GetInst()->GetMainHwnd(), m_contentPath);
}
