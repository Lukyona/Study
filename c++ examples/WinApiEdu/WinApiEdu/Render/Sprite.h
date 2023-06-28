#pragma once
// 비트맵 1개를 그리는
class Sprite 
{
private:
    Vector2 m_position = Vector2( 0.f,0.f );
    Vector2 m_scale = Vector2( 1.f,1.f );
    Vector2 m_textureSize = Vector2{ 0,0 };

    HDC MemDC = NULL;

    wstring m_imgFile;

    Vector2 m_offset = Vector2(0.f, 0.f);
    Vector2 m_offsetSize = Vector2(0.f, 0.f);


    void SetTextureSize(float x, float y) { m_textureSize = Vector2(x, y); }
    
public:
    Sprite(wstring img);
    Sprite(wstring img, float x, float y, float sizeX, float sizeY);
    ~Sprite();

    void Update();
    void Render();

    void SetPosition(Vector2 pt) { m_position = pt; }
    void SetScale(Vector2 size) { m_scale = size; }

    Vector2 GetPosition() { return m_position; }
    Vector2 GetScale() { return m_scale; }
    Vector2 GetSize() { return m_textureSize; }
    Vector2 GetRealTextureSize();

    void SetOffset(Vector2 value) { m_offset = value; }
    void SetOffset(float x, float y) { m_offset.x = x; m_offset.y = y;}

    void SetOffsetSize(Vector2 value) { m_offsetSize = value; }
    void SetOffsetSize(float x, float y) { m_offsetSize = Vector2(x,y); }

    void SetImage(wstring img) { m_imgFile = img; }


    void Test(Vector2& pos);

};

