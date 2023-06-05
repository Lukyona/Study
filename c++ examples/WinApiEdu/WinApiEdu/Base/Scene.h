#pragma once
class Scene
{

public:
    Scene() {} ;
    ~Scene() {};

    virtual void Update() = 0; // 순수가상함수
    virtual void Render() = 0;
    virtual void PostRender() {}; // 2D 텍스트 렌더링
    virtual void PreRender() {}; // IMGUI 
    virtual void ChangeScene() = 0; // 씬 변경 시 초기화

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
    bool m_active = false; // back으로 생성, 씬 활성화 여부
    bool m_reset = true;    // true - 현재 씬 초기
    
    
};

