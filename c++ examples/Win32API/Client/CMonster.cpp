#include "pch.h"
#include "CMonster.h"
#include "CTimeMgr.h"
#include "CMissile.h"
#include "CScene.h"
#include "CSceneMgr.h"
#include "CKeyMgr.h"



CMonster::CMonster()
    :m_speed(100.f), m_centerPos(Vec2(0.f, 0.f)), m_maxDistance(50.f), m_dir(1), isVertical(false)
{
}

CMonster::~CMonster()
{
}

void CMonster::update()
{
    Vec2 curPos = GetPos();

    if (isVertical)
    {
        // 진행 방향으로 시간당 m_speed만큼 이동
        curPos.x += fDT * m_speed * m_dir;

        // 배회 거리 기준량을 넘어섰는지 확인
        float dist = abs(m_centerPos.x - curPos.x) - m_maxDistance;
        if (dist > 0.f)
        {
            m_dir *= -1; // 방향 변경
            curPos.x += dist * m_dir; // 초과한 거리만큼 (기존 범위쪽으로) 이동
        }
    }
    else
    {
        curPos.y += fDT * m_speed * m_dir;

        // 배회 거리 기준량을 넘어섰는지 확인
        float dist = abs(m_centerPos.y - curPos.y) - m_maxDistance;
        if (dist > 0.f)
        {
            m_dir *= -1; // 방향 변경
            curPos.y += dist * m_dir; // 초과한 거리만큼 (기존 범위쪽으로) 이동
        }
    }

    if (KEY_TAP(KEY::SPACE))
    {
        //CreateMissile();
    }


    SetPos(curPos);
}

void CMonster::CreateMissile()
{
    Vec2 missilePos = GetPos();
    missilePos.y += GetScale().y / 2.f; // 미사일 나올 위치

    CMissile* missile = new CMissile;

    missile->SetPos(missilePos);
    missile->SetScale(Vec2(10.f, 20.f));
    missile->SetDir(false); // 적의 미사일은 아래로 나가야함
    missile->SetType(2);

    CScene* curScene = CSceneMgr::GetInst()->GetCurScene();
    curScene->AddObject(missile, GROUP_TYPE::DEFAULT);
}


