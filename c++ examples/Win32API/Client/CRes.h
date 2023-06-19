#pragma once
class CRes
{
private:
    wstring m_key;          // 리소스 키 값
    wstring m_relativePath;  // 리소스 상대 경로
    
public:
    CRes();
    ~CRes();

    void SetKey(const wstring& key) { m_key = key; }
    void SetRelativePath(const wstring& path) { m_relativePath = path; }

    const wstring& GetKey() { return m_key; }
    const wstring& GetRelativePath() { return m_relativePath; }


};

