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

    // �ػ󵵿� �°� ������ ũ�� ����


    // FAILED(E_FAIL); // = true
    //return E_FAIL; // ����
    return S_OK;  // 0
}

void CCore::progress()
{
}
