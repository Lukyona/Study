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

    // ���� �������� �ð��� m_speed��ŭ �̵�
    curPos.x += fDT * m_speed * m_dir;


    // ��ȸ �Ÿ� ���ط��� �Ѿ���� Ȯ��
    float dist = abs(m_centerPos.x - curPos.x) - m_maxDistance;
    if (dist > 0.f)
    {
        m_dir *= -1; // ���� ����
        curPos.x += dist * m_dir; // �ʰ��� �Ÿ���ŭ (���� ����������) �̵�

    }

    SetPos(curPos);
}


