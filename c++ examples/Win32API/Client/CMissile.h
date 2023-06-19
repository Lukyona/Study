#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
private:
    float m_theta; // �̵� ����
    int shapeNum = 0;
    int typeNum = 0;
    Vec2 m_dir;

public:

    virtual void update();
    virtual void render(HDC _dc);

    void SetDir(float _theta) // ������ ���� ����, �������� �� �����. 180���� ���ϸ� ���̰��� �����
    {
        m_theta = _theta;
        typeNum = 1;
    }

    void SetDir(Vec2 _vec) // ��ǥ�� ���� ����
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

