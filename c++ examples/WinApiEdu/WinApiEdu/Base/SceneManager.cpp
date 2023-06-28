#include "framework.h"
#include "SceneManager.h"
#include "Scene/S01_Basic.h"
#include "Scene/S02_Bee.h"
#include "Scene/S01_Momodora.h"

SceneManager::SceneManager()
{

    Scene* pScene = new S01_Momodora();
    pScene->SetActive(true);
    m_scenes.push_back(pScene);
    
    thread t(bind(&SceneManager::ThreadStart, this));
    t.detach(); // 백그라운드 수행

    //thread t2(bind(&SceneManager::CreateObject, this));
    //t.detach(); // 백그라운드 수행
}

SceneManager::~SceneManager()
{
    for (UINT i = 0; i < m_scenes.size(); i++)
    {
        delete m_scenes[i];
    }
    m_scenes.erase(m_scenes.begin(), m_scenes.end());
}

void SceneManager::Update()
{
    CAMERA->Update();

    for (UINT i = 0; i < m_scenes.size(); i++)
    {
        if (m_scenes[i]->isActive())
        {
            m_curScene = m_scenes[i];
            m_scenes[i]->Update();
        }
    }

}

void SceneManager::Render()
{
    for (UINT i = 0; i < m_scenes.size(); i++)
    {
        if (m_scenes[i]->isActive())
        {
            m_curScene = m_scenes[i];
            m_scenes[i]->Render();
        }
    }
}

Scene* SceneManager::GetScene(string name)
{
    Scene* Value = nullptr;
    for (UINT i = 0; i < m_scenes.size(); i++)
    {
        if (m_scenes[i]->GetName() != name)
        {
            continue;
        }
        Value = m_scenes[i];
        break;
    }

    return Value;
}

void SceneManager::ThreadStart()
{
    m_scenes.push_back(new S01_Basic());
}

void SceneManager::ChangeScene(string name)
{
    for (UINT i = 0; i < m_scenes.size(); i++)
    {
        m_scenes[i]->SetActive(false);
        if (m_scenes[i]->GetName() == name)
        {
            m_scenes[i]->SetActive(true);
            m_scenes[i]->ChangeScene();

        }
        else
            m_scenes[i]->SetActive(false);

    }
    
}

void SceneManager::CreateObject()
{
    /*if (!OBJECTMANAGER->FindObject("test"))
    {
        GameObject* p = new GameObject();
        OBJECTMANAGER->AddObject("test", p);
    }*/
}