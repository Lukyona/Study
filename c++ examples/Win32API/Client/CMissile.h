#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
private:
    float m_dir; //���Ʒ� ���� ����

public:

    virtual void update();
    virtual void render(HDC _dc);

    void SetDir(bool _up) 
    {
        if (_up) m_dir = -1;
        else m_dir = 1;
    }


public:
    CMissile();
    ~CMissile();
};

