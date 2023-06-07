#include "pch.h"
#include "CMissile.h"
#include "CTimeMgr.h"

CMissile::CMissile()
    :m_dir(1)
{
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
    Vec2 vPos = GetPos();

    vPos.y += 400.f * fDT * m_dir;

    SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
    Vec2 m_vPos = GetPos();
    Vec2 m_vScale = GetScale();
    Ellipse(_dc, (int)(m_vPos.x - m_vScale.x / 2.f), (int)(m_vPos.y - m_vScale.y / 2.f),
        (int)(m_vPos.x + m_vScale.x / 2.f), (int)(m_vPos.y + m_vScale.y / 2.f));
}

//플레이어 미사일 종류 추가 (세 방향으로 나가든, 회전을 하며 가든)
// 몬스터 종류 추가 ( 1번 미사일만 쏜다던지, 앞뒤로 움직이는 몬스터, 위치 다양