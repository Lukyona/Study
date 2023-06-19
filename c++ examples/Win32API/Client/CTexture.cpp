#include "pch.h"
#include "CTexture.h"

CTexture::CTexture()
    :m_bit(0), m_dc(0)
{
}

CTexture::~CTexture()
{
    DeleteDC(m_dc);
    DeleteObject(m_bit);
}

void CTexture::Load(const wstring& _filePath)
{
    m_bit = (HBITMAP)LoadImage(nullptr, _filePath.c_str(), IMAGE_BITMAP, 0,0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

    //m_bit가 null이면 오류
    assert(m_bit);
}
