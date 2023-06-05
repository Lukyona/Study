#include "framework.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
    for (auto a : m_objects)
    {
        delete a.second;
    }

    m_objects.clear();
}

void ObjectManager::AddObject(string name, GameObject* obj)
{
    m_objects.insert(make_pair(name, obj));
}

GameObject* ObjectManager::FindObject(string name)
{
    GameObject* pObject = nullptr;

    if (m_objects.count(name))
        return m_objects[name];

    return pObject;
}

void ObjectManager::SetPosition(string name, POINT pos)
{
    GameObject* pObject = FindObject(name);
    if (!pObject)
    {
        return;
    }
    else
    {
        //pObject->SetPosition(name,pos);
    }
}

void ObjectManager::Update(string name)
{
    GameObject* pObject = FindObject(name);
    if (!pObject)
    {
        return;
    }
    else
    {
        pObject->Render();
    }
}
