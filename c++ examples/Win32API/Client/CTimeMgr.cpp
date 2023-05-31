#include "pch.h"
#include "CTimeMgr.h"

CTimeMgr::CTimeMgr()
    :m_curCount{}
{

}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
    QueryPerformanceCounter(&m_curCount);
    QueryPerformanceFrequency(&m_Frequency);
}
