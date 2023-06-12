#include "pch.h"
#include "CScene_Start.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CCore.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
    // 플레이어 추가
    CObject* obj = new CPlayer;
    obj->SetPos(Vec2(640.f, 584.f));
    obj->SetScale(Vec2(100.f, 100.f));
    AddObject(obj, GROUP_TYPE::DEFAULT);


    // 몬스터 추가
    int monCount = 8;
    float moveDist; // = 50.f;
    float objScale; // = 50.f;
    Vec2 vResolution = CCore::GetInst()->GetResolution();
    float term; //= (vResolution.x - ((moveDist + objScale / 2.f) * 2)) / (float)(monCount - 1);

    CMonster* monObj = nullptr;
    for (int i = 0; i < monCount; ++i)
    {
        monObj = new CMonster;

        srand(i);

        bool isVertical = rand() % 2;
        monObj->isMoveVertical(isVertical);

        moveDist = (rand() % 50) + 5;
        objScale = (rand() % 50) + 20;

        if (isVertical)
        {
            term = (vResolution.y - ((moveDist + objScale / 2.f) * 2)) / (float)(monCount - 1);
        }
        else
        {
            term = (vResolution.x - ((moveDist + objScale / 2.f) * 2)) / (float)(monCount - 1);
        }
        
        monObj->SetPos(Vec2((moveDist + objScale/2.f) + (float)(i * term), 50.f));
        monObj->SetScale(Vec2(objScale, objScale));
        monObj->SetCenterPos(monObj->GetPos());
        monObj->SetMaxDistance(moveDist);
        AddObject(monObj, GROUP_TYPE::DEFAULT);
    }
}

void CScene_Start::Exit()
{
}
    