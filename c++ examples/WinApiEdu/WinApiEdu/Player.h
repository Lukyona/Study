#pragma once
class Player final : public GameObject // final �� �̻��� ��� x
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


