#pragma once

class CObject; //이렇게 전방선언 시 클래스 자체는 못 쓰지만 포인터타입으로는 쓸 수 있음

class CScene
{
private:
    vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END]; // 오브젝트를 저장/관리할 32(그룹 개수)개짜리 벡터 배열    
    wstring m_name; // 씬 이름

public:

    CScene();
    virtual ~CScene(); // 자식 클래스의 소멸자가 호출되도록

    void update();
    void render(HDC _dc);

    void SetName(const wstring& _name) { m_name = _name; }
    const wstring& GetName() { return m_name; }

    virtual void Enter() = 0; // 해당 씬에 진입 시 호출
    virtual void Exit() = 0; //  해당 씬 탈출 시 호출

    //인라인 함수이므로 호출 비용 없음
    void AddObject(CObject* _obj, GROUP_TYPE _type)
    {
        m_arrObj[(UINT)_type].push_back(_obj);
    }
};

