#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
private:
    float m_theta; // 이동 방향
    int shapeNum = 0;
    Vec2 m_dir;

public:

    virtual void update();
    virtual void render(HDC _dc);

    void SetDir(float _theta) // 각도로 방향 설정
    {
        m_theta = _theta;
    }

    void SetDir(Vec2 _vec) // 좌표로 방향 설정
    {
        m_dir = _vec;
        m_dir.Normalize();
    }


    void SetType(int n)
    {
        shapeNum = n;
    }


public:
    CMissile();
    ~CMissile();
};

