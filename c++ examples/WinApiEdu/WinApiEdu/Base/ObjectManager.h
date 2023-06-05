#pragma once
#define OBJECTMANAGER ObjectManager::GetInstance() 

class ObjectManager
{
private:
    ObjectManager();

public:

    static ObjectManager* GetInstance()
    {
        static ObjectManager singleton;
        return &singleton;
    }

    ~ObjectManager();

    map<string, GameObject*> m_objects;

    void AddObject(string name, GameObject* obj);
    GameObject* FindObject(string name);
    void SetPosition(string name, POINT pos);

    void Update(string name);
};

