#pragma once
class Scene
{

public:
    Scene() {} ;
    ~Scene() {};

    virtual void Update() = 0; // ���������Լ�
    virtual void Render() = 0;
    virtual void PostRender() {}; // 2D �ؽ�Ʈ ������
    virtual void PreRender() {}; // IMGUI 
    virtual void ChangeScene() = 0; // �� ���� �� �ʱ�ȭ

    void SetActive(bool val) { m_active = val; };
    void SetName(string name) { m_nextSceneName = name; };
    void SetNextName(string name) { m_nextSceneName = name; };
    void SetReset(bool val) { m_reset = val; };

    bool isActive() { return m_active; }
    string GetName() { return m_sceneName; }
    string GetNextName() { return m_nextSceneName; }


protected:
    string m_sceneName;
    string m_nextSceneName;
    bool m_active = false; // back���� ����, �� Ȱ��ȭ ����
    bool m_reset = true;    // true - ���� �� �ʱ�
    
    
};

