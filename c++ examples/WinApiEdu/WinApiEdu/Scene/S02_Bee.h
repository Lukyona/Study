#pragma once
#include "framework.h"

class S02_Bee : public Scene
{

public:
    S02_Bee();
    ~S02_Bee();

    void Update() override; // 위치, 충돌
    void Render() override; // 렌더링

    void DrawBitmap(HDC hdc, POINT pos, wstring imgFile);

    void ChangeScene() override {};

    class Player* m_player = nullptr;
    class Enemy* m_enemy = nullptr;
};

