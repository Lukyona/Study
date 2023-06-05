#pragma once
#define SCENEMANAGER SceneManager::GetInstance() 
class SceneManager
{
public:
    static SceneManager* GetInstance()
    {
        static SceneManager singleton;
        return &singleton;
    }

    ~SceneManager();
    

private:
    SceneManager();

    vector<class Scene*> m_scenes;
    Scene* m_curScene = nullptr;

    bool m_threadEnd = false;

    string m_sceneName; // ÇöÀç ¾À
   
public:
    void Update();
    void Render();

    Scene* GetCurScene() { return m_curScene; }
    Scene* GetScene(string name);
    void ChangeScene(string name);

    void ThreadStart();

    void CreateObject();

};

