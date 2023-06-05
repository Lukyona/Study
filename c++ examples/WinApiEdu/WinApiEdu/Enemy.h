#pragma once
class Enemy final : public GameObject
{
private:
    class Sprite* m_sprite = nullptr;


public:
    Enemy();
    ~Enemy();


    virtual void Render() override;
    virtual void Update() override;

    RECT GetRectangle();

    void SetPlayer(GameObject* obj) { m_player = obj; }

    GameObject* m_player = nullptr;

};

