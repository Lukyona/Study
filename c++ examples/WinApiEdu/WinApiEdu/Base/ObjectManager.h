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
    void Render(string name);
};

// 추상화 팩토리 pattern

template <typename T>
class ObjectFactory {
public:
    static GameObject* Create(string name)
    {
        GameObject* obj = OBJECTMANAGER->FindObject(name);
        if (obj != NULL)
            return obj;

        obj = new T;
        OBJECTMANAGER->AddObject(name, obj);
        return obj;
    }
};