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

//�÷��̾� �̻��� ���� �߰� (�� �������� ������, ȸ���� �ϸ� ����)
// ���� ���� �߰� ( 1�� �̻��ϸ� ��ٴ���, �յڷ� �����̴� ����, ��ġ �پ�