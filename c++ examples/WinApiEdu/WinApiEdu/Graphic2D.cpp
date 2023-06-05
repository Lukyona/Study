#include "Graphic2D.h"
#include "framework.h"

void Graphic2D::DrawLine(HDC hdc, POINT start, POINT end, int width, COLORREF rgb)
{
    HPEN myPen;     // 사용할 펜
    HPEN oldPen;    // 이전에 사용한 펜

    myPen = CreatePen(PS_SOLID, width, rgb);
    oldPen = (HPEN)SelectObject(hdc, myPen);

    // SelectObject() - (두 번째 매개변수) GDI - 그래픽 디바이스 인터페이스, OBJ - 오브젝트

    MoveToEx(hdc, start.x, start.y, NULL);

    LineTo(hdc, end.x, end.y);

    SelectObject(hdc, oldPen);

    DeleteObject(myPen);
}

void Graphic2D::DrawRectangle(HDC hdc, int x, int y, int width, int height, COLORREF rgb)
{
    HBRUSH myBrush;
    HBRUSH oldBrush;

    myBrush = CreateSolidBrush(rgb);
    oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

    Rectangle(hdc, x, y, width, height);

    SelectObject(hdc, oldBrush);

    DeleteObject(myBrush);
}

void Graphic2D::DrawBitmap(HDC hdc, POINT pos, wstring imgFile)
{
    HDC MemDC;
    HBITMAP myBitmap, oldBitmap;

    MemDC = CreateCompatibleDC(hdc);
    // DBI - Device Independent Bitmap(디바이스와 무관한 비트맵)
    myBitmap = (HBITMAP)LoadImage(NULL, imgFile.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    /*
    LoadImageW(
_In_opt_ HINSTANCE hInst,
_In_ LPCWSTR name,
_In_ UINT type,
_In_ int cx,
_In_ int cy,
_In_ UINT fuLoad);
*/

    BITMAP bitmap;
    GetObject(myBitmap, sizeof(BITMAP), &bitmap);

    oldBitmap = (HBITMAP)SelectObject(MemDC, myBitmap);

    BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, MemDC, 0, 0, SRCCOPY); // 소스카피

    SelectObject(MemDC, oldBitmap);

    DeleteObject(myBitmap);

    DeleteDC(MemDC);
}

Graphic2D::Graphic2D()
{
}

Graphic2D::~Graphic2D()
{
}
