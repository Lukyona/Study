#include "pch.h"
#include "CMissile.h"
#include "CTimeMgr.h"

CMissile::CMissile()
    :m_theta(0.f), m_dir(Vec2(1.f, 1.f))
{
    m_dir.Normalize();
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
    Vec2 vPos = GetPos();

    if (typeNum == 1)
    {
        vPos.x += 400.f * fDT * cosf(m_theta);
        vPos.y -= 400.f * fDT * sinf(m_theta);
    }
    else if(typeNum == 2)
    {
        vPos.x += 400.f * fDT * m_dir.x;
        vPos.y += 400.f * fDT * m_dir.y; // ���� ������ Y �������� ��
    }

    SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
    Vec2 m_vPos = GetPos();
    Vec2 m_vScale = GetScale();

    if (shapeNum == 1)
    {
        Ellipse(_dc, (int)(m_vPos.x - m_vScale.x / 2.f), (int)(m_vPos.y - m_vScale.y / 2.f),
            (int)(m_vPos.x + m_vScale.x / 2.f), (int)(m_vPos.y + m_vScale.y / 2.f));
    }
    else if(shapeNum == 2)
    {
        //RoundRect(_dc, (int)(m_vPos.x - m_vScale.x / 2.f), (int)(m_vPos.y - m_vScale.y / 2.f),
        //    (int)(m_vPos.x + m_vScale.x / 2.f), (int)(m_vPos.y + m_vScale.y / 2.f), 25.f, 25.f);
        RoundRect(_dc, (int)(m_vPos.x - m_vScale.x / 2.f), (int)(m_vPos.y - m_vScale.y / 2.f), (int)(m_vPos.x + m_vScale.x), (int)(m_vPos.y + m_vScale.y), m_vScale.x, m_vScale.y);
    }

}

//�÷��̾� �̻��� ���� �߰� (�� �������� ������, ȸ���� �ϸ� ����)
// ���� ���� �߰� ( 1�� �̻��ϸ� ��ٴ���