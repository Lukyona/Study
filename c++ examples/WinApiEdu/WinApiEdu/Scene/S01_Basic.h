#pragma once
class S01_Basic : public Scene
{
public:
    S01_Basic();
    ~S01_Basic();


    void Update() override; // 위치, 충돌
    void Render() override; // 렌더링

    void BlackRender();
    void DrawLine(HDC hdc, POINT start, POINT end, int width, COLORREF rgb);
    void DrawRectangle(HDC hdc, int x, int y, int width, int height,  COLORREF rgb);
    void DrawBitmap(HDC hdc, POINT pos, wstring imgFile);

    void ChangeScene() override {};

};

