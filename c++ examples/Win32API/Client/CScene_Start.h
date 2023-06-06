#pragma once
#include "CScene.h"
class CScene_Start :
    public CScene
{



public:
    CScene_Start();
    ~CScene_Start();

   // 키워드 안 써도 되지만 다른 멤버 함수와 구분이 쉽게 가도록 명시적으로
    virtual void Enter();
    virtual void Exit();
};

