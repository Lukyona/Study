#include "pch.h"
#include "CScene_Start.h"
#include "CObject.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
    CObject* obj = new CObject;

    obj->SetPos(Vec2(640.f,384.f));
    obj->SetScale(Vec2(100.f, 100.f));


    AddObject(obj, GROUP_TYPE::DEFAULT);
}

void CScene_Start::Exit()
{
}
    