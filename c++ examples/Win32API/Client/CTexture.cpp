#include "pch.h"
#include "CTexture.h"
#include "CCore.h"

CTexture::CTexture()
    :m_bit(0), m_dc(0), m_bitInfo{}
{
}

CTexture::~CTexture()
{
    DeleteDC(m_dc);
    DeleteObject(m_bit);
}

void CTexture::Load(const wstring& _filePath)
{
    //파일로부터 로딩한 데이터를 비트맵으로 생성
    m_bit = (HBITMAP)LoadImage(nullptr, _filePath.c_str(), IMAGE_BITMAP, 0,0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

    //m_bit가 null이면 오류
    assert(m_bit);


    m_dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

    HBITMAP prevBit = (HBITMAP)SelectObject(m_dc, m_bit);
    DeleteObject(prevBit);

    //비트맵 정보
    GetObject(m_bit, sizeof(BITMAP), &m_bitInfo);



}
