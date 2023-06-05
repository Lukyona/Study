#pragma once
class GameObject
{
private:
    POINT m_position = POINT{ 0,0 };
    POINT m_scale = POINT{ 1,1 };

public:
    virtual void Render() = 0;
    virtual void Update() = 0;
    void SetPosition(POINT pt) { m_position = pt; }
    void SetScale(POINT size) { m_scale = size; }

    POINT GetPosition() { return m_position; }
    POINT GetScale() { return m_scale; }

};

