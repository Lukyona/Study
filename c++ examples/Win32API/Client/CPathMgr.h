#pragma once
class CPathMgr
{
    SINGLE(CPathMgr);
private:
    wchar_t m_contentPath[255];

public:
    void init();

    const wchar_t* GetContentPath() { return m_contentPath; }
};

