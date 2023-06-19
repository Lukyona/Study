#pragma once
class CRes
{
private:
    wstring m_key;          // ���ҽ� Ű ��
    wstring m_relativePath;  // ���ҽ� ��� ���
    
public:
    CRes();
    ~CRes();

    void SetKey(const wstring& key) { m_key = key; }
    void SetRelativePath(const wstring& path) { m_relativePath = path; }

    const wstring& GetKey() { return m_key; }
    const wstring& GetRelativePath() { return m_relativePath; }


};

