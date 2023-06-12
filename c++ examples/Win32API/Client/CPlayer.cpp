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
    Vec2 missilePos = GetPos();
    missilePos.y -= GetScale().y / 2.f; // 미사일 나올 위치

    CMissile* missile = new CMissile;

    missile->SetPos(missilePos);
    missile->SetScale(Vec2(25.f, 25.f));
    missile->SetDir(Vec2( - 1.f, -7.f)); // 플레이어의 미사일 방향
    missile->SetType(1);

    CScene* curScene = CSceneMgr::GetInst()->GetCurScene();
    curScene->AddObject(missile, GROUP_TYPE::DEFAULT);
}
