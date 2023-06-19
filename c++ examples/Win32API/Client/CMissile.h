#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
private:
    float m_theta; // 이동 방향
    int shapeNum = 0;
    int typeNum = 0;
    Vec2 m_dir;

public:

    virtual void update();
    virtual void render(HDC _dc);

    void SetDir(float _theta) // 각도로 방향 설정, 라디안으로 값 줘야함. 180도를 원하면 파이값을 줘야함
    {
        m_theta = _theta;
        typeNum = 1;
    }

    void SetDir(Vec2 _vec) // 좌표로 방향 설정
    {
        m_dir = _vec;
        m_dir.Normalize();
        typeNum = 2;

    }


    void SetShape(int n)
    {
        shapeNum = n;
    }


public:
    CMissile();
    ~CMissile();
};

