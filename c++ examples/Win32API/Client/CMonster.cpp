#include "pch.h"
#include "CMonster.h"
#include "CTimeMgr.h"

CMonster::CMonster()
    :m_speed(100.f), m_centerPos(Vec2(0.f, 0.f)), m_maxDistance(50.f), m_dir(1)
{
}

CMonster::~CMonster()
{
}

void CMonster::update()
{
    Vec2 curPos = GetPos();

    // 진행 방향으로 시간당 m_speed만큼 이동
    curPos.x += fDT * m_speed * m_dir;


    // 배회 거리 기준량을 넘어섰는지 확인
    float dist = abs(m_centerPos.x - curPos.x) - m_maxDistance;
    if (dist > 0.f)
    {
        m_dir *= -1; // 방향 변경
        curPos.x += dist * m_dir; // 초과한 거리만큼 (기존 범위쪽으로) 이동

    }

    SetPos(curPos);
}


