#pragma once

class CObject; //�̷��� ���漱�� �� Ŭ���� ��ü�� �� ������ ������Ÿ�����δ� �� �� ����

class CScene
{
private:
    vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END]; // ������Ʈ�� ����/������ 32(�׷� ����)��¥�� ���� �迭    
    wstring m_name; // �� �̸�

public:
    CScene();
    virtual ~CScene(); // �ڽ� Ŭ������ �Ҹ��ڰ� ȣ��ǵ���

    void SetName(const wstring& _name) { m_name = _name; }
    const wstring& GetName() { return m_name; }
};

