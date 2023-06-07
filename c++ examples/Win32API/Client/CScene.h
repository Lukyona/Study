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

    void update();
    void render(HDC _dc);

    void SetName(const wstring& _name) { m_name = _name; }
    const wstring& GetName() { return m_name; }

    virtual void Enter() = 0; // �ش� ���� ���� �� ȣ��
    virtual void Exit() = 0; //  �ش� �� Ż�� �� ȣ��

    //�ζ��� �Լ��̹Ƿ� ȣ�� ��� ����
    void AddObject(CObject* _obj, GROUP_TYPE _type)
    {
        m_arrObj[(UINT)_type].push_back(_obj);
    }
};

