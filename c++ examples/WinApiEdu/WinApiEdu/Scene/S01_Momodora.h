#pragma once
class S01_Momodora : public Scene
{
public:
    S01_Momodora();
    ~S01_Momodora();

    void Update() override; // ��ġ, �浹
    void Render() override; // ������

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

