#include "pch.h"
#include "CCore.h"

//CCore* CCore::pInst = nullptr;



CCore::CCore()
{
}

CCore::~CCore()
{
}


int CCore::init(HWND _hwnd, POINT _ptRes)
{
    m_hWnd = _hwnd;
    m_ptResolution = _ptRes;

    // 해상도에 맞게 윈도우 크기 조정


    // FAILED(E_FAIL); // = true
    //return E_FAIL; // 음수
    return S_OK;  // 0
}

void CCore::progress()
{
}
