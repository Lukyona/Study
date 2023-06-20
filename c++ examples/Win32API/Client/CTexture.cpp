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
    //���Ϸκ��� �ε��� �����͸� ��Ʈ������ ����
    m_bit = (HBITMAP)LoadImage(nullptr, _filePath.c_str(), IMAGE_BITMAP, 0,0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

    //m_bit�� null�̸� ����
    assert(m_bit);


    m_dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

    HBITMAP prevBit = (HBITMAP)SelectObject(m_dc, m_bit);
    DeleteObject(prevBit);

    //��Ʈ�� ����
    GetObject(m_bit, sizeof(BITMAP), &m_bitInfo);



}
