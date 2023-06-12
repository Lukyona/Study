#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
private:
    float m_theta; // �̵� ����
    int shapeNum = 0;
    Vec2 m_dir;

public:

    virtual void update();
    virtual void render(HDC _dc);

    void SetDir(float _theta) // ������ ���� ����
    {
        m_theta = _theta;
    }

    void SetDir(Vec2 _vec) // ��ǥ�� ���� ����
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

