#pragma once
#include "framework.h"
class Graphic2D
{

public:

    static void DrawLine(HDC hdc, POINT start, POINT end, int width, COLORREF rgb);
    static void DrawRectangle(HDC hdc, int x, int y, int width, int height, COLORREF rgb);
    static void DrawBitmap(HDC hdc, POINT pos, wstring imgFile);

    Graphic2D();
    ~Graphic2D();
};

