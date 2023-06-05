#pragma once
// 비트맵 1개를 그리는
class Sprite 
{
private:
    POINT m_position = POINT{ 0,0 };
    POINT m_scale = POINT{ 1,1 };

    HDC MemDC = NULL;

    POINT m_size = POINT{ 0,0 };

public:
    Sprite(wstring img, POINT pt = {0,0});
    ~Sprite();

    void Update();
    void Render();

    void SetPosition(POINT pt) { m_position = pt; }
    void SetScale(POINT size) { m_scale = size; }

    POINT GetPosition() { return m_position; }
    POINT GetScale() { return m_scale; }
    POINT GetSize() { return m_size; }

};

