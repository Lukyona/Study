#pragma once
#include "CRes.h"
class CTexture :
    public CRes
{
private:
    HDC m_dc;
    HBITMAP m_bit;

public:
    CTexture();
    ~CTexture();

    void Load(const wstring& _filePath);

};

