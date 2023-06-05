#pragma once
class Player final : public GameObject // final 더 이상은 상속 x
{
private:
    class Sprite* m_sprite = nullptr;


public:
    Player();
    ~Player();

    virtual void Render() override;
    virtual void Update() override;

    RECT GetRectangle();
};


