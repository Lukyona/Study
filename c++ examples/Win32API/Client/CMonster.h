#pragma once
#include "CObject.h"
class CMonster :
    public CObject
{
private:
    Vec2 m_centerPos;

    float m_speed;
    float m_maxDistance;

    int m_dir; // -1 왼쪽(위쪽), 1 오른쪽(아래쪽)

    bool isVertical = false; // 세로로 움직일 거면 true

public:
    virtual void update();

    void CreateMissile();


public:
    CMonster();
    ~CMonster();

    float GetSpeed() { return m_speed; }
    void SetSpeed(float sp) { m_speed = sp; }

    void SetCenterPos(Vec2 _pos) { m_centerPos = _pos; }
    void SetMaxDistance(float _f) { m_maxDistance = _f; }

    void isMoveVertical(bool b) { isVertical = b; }

};

