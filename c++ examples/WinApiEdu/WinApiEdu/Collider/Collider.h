#pragma once
class Collider
{
private:
    Vector2 m_position = Vector2(0.f, 0.f);
    Vector2 m_scale = Vector2(1.f, 1.f);
    COLORREF rgb = RGB(0, 255, 0);

public:
    Collider();
    ~Collider();

    void SetPosition(Vector2 pt) { m_position = pt; }
    void SetScale(Vector2 size) { m_scale = size; }

    Vector2 GetPosition() { return m_position; }
    Vector2 GetScale() { return m_scale; }

    void Update();
    void Render();

};

