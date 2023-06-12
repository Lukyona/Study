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
        // ���� �������� �ð��� m_speed��ŭ �̵�
        curPos.x += fDT * m_speed * m_dir;

        // ��ȸ �Ÿ� ���ط��� �Ѿ���� Ȯ��
        float dist = abs(m_centerPos.x - curPos.x) - m_maxDistance;
        if (dist > 0.f)
        {
            m_dir *= -1; // ���� ����
            curPos.x += dist * m_dir; // �ʰ��� �Ÿ���ŭ (���� ����������) �̵�
        }
    }
    else
    {
        curPos.y += fDT * m_speed * m_dir;

        // ��ȸ �Ÿ� ���ط��� �Ѿ���� Ȯ��
        float dist = abs(m_centerPos.y - curPos.y) - m_maxDistance;
        if (dist > 0.f)
        {
            m_dir *= -1; // ���� ����
            curPos.y += dist * m_dir; // �ʰ��� �Ÿ���ŭ (���� ����������) �̵�
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
    missilePos.y += GetScale().y / 2.f; // �̻��� ���� ��ġ

    CMissile* missile = new CMissile;

    missile->SetPos(missilePos);
    missile->SetScale(Vec2(10.f, 20.f));
    missile->SetDir(false); // ���� �̻����� �Ʒ��� ��������
    missile->SetType(2);

    CScene* curScene = CSceneMgr::GetInst()->GetCurScene();
    curScene->AddObject(missile, GROUP_TYPE::DEFAULT);
}


