#include "pch.h"
#include "CTimeMgr.h"
#include <cstdio>
#include "CCore.h"

CTimeMgr::CTimeMgr()
    :m_curCount{}, m_preCount{}, m_frequency{}, m_DT(0.), m_callCount(0), m_acc(0.)
{

}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
    //현재 카운트
    QueryPerformanceCounter(&m_preCount);

    //초당 카운트 횟수
    QueryPerformanceFrequency(&m_frequency);
}

void CTimeMgr::update()
{
    QueryPerformanceCounter(&m_curCount);

    m_DT = (double)(m_curCount.QuadPart - m_preCount.QuadPart) / (double)m_frequency.QuadPart;

    m_preCount = m_curCount;

}

void CTimeMgr::render()
{
    ++m_callCount;
    m_acc += m_DT; // DT 누적

    if (m_acc >= 1.) // 1초가 되면
    {
        m_fps = m_callCount;

        m_acc = 0.;
        m_callCount = 0;

        wchar_t buffer[255] = {};
        swprintf_s(buffer, L"FPS: %d, DT : %f", m_fps, m_DT);
        SetWindowText(CCore::GetInst()->GetMainHwnd(), buffer);
    }
}
