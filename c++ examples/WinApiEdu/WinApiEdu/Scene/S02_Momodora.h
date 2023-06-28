#pragma once
class S02_Momodora : public Scene
{
public:
    S02_Momodora();
    ~S02_Momodora();

    void Update() override; // 위치, 충돌
    void Render() override; // 렌더링

    void ChangeScene() override {};

    class Line* GetLines();

    class Collider* GetLeftZone();
    class Collider* GetRightZone();

private:
    class Sprite* m_background = nullptr;

    class Line* m_ground = nullptr;


    class Collider* ZoneLeft = nullptr;
    class Collider* ZoneRight = nullptr;

};

