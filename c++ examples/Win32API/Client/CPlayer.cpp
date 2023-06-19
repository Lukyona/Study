#include "pch.h"
#include "CPlayer.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CMissile.h"
#include "CSceneMgr.h"
#include "CScene.h"

void CPlayer::update()
{
    Vec2 vPos = GetPos();
    if (KEY_HOLD(KEY::W))
    {
        vPos.y -= 200.f * fDT;
    }
    if (KEY_HOLD(KEY::S))
    {
        vPos.y += 200.f * fDT;

    }
    if (KEY_HOLD(KEY::A))
    {
        vPos.x -= 200.f * fDT;

    }
    if (KEY_HOLD(KEY::D))
    {
        vPos.x += 200.f * fDT;

    }


    if (KEY_TAP(KEY::SPACE))
    {
        CreateMissile();
    }

    SetPos(vPos);
}


void CPlayer::CreateMissile()
{
    for (int i = 1; i < 4; ++i)
    {
        Vec2 missilePos = GetPos();
        missilePos.x -= GetScale().x;
        missilePos.x += ((float)i * 50.f);
        missilePos.y -= GetScale().y / 2.f; // �̻��� ���� ��ġ

        CMissile* missile = new CMissile;

        missile->SetPos(missilePos);
        missile->SetScale(Vec2(25.f, 25.f));
        missile->SetDir((PI / 4) * float(i)); // �÷��̾��� �̻��� ����
        missile->SetShape(1);

        CScene* curScene = CSceneMgr::GetInst()->GetCurScene();
        curScene->AddObject(missile, GROUP_TYPE::DEFAULT);
    }
    
}
