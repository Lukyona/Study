#include "pch.h"
#include "CPlayer.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CMissile.h"
#include "CSceneMgr.h"
#include "CScene.h"
#include "CPathMgr.h"
#include "CTexture.h"

CPlayer::CPlayer()
{
    m_tex = new CTexture;
    wstring filePath = CPathMgr::GetInst()->GetContentPath();
    filePath += L"\\texture\\plane.bmp";
    m_tex->Load(filePath);
}

CPlayer::~CPlayer()
{
    if (m_tex != nullptr)
        delete m_tex;
}

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

void CPlayer::render(HDC _dc)
{
    int width = (int)m_tex->Width();
    int height = (int)m_tex->Height();

    Vec2 pos = GetPos();

    
    


    TransparentBlt(_dc, int(pos.x - (float)(width / 2)), int(pos.y - (float)(height / 2)), width, height, m_tex->GetDC(), 0, 0, width, height, RGB(245,29,250));
}


void CPlayer::CreateMissile()
{
    //for (int i = 1; i < 4; ++i)
    //{
        Vec2 missilePos = GetPos();
        missilePos.x -= GetScale().x;
        //missilePos.x += ((float)i * 50.f);
        missilePos.x += 100.f;
        missilePos.y -= GetScale().y / 2.f; // 미사일 나올 위치

        CMissile* missile = new CMissile;

        missile->SetPos(missilePos);
        missile->SetScale(Vec2(25.f, 25.f));
        missile->SetDir(Vec2(0.f, -90.f));
        //missile->SetDir((PI / 4) * float(i)); // 플레이어의 미사일 방향
        missile->SetShape(1);

        CScene* curScene = CSceneMgr::GetInst()->GetCurScene();
        curScene->AddObject(missile, GROUP_TYPE::DEFAULT);
    //}
    
}
