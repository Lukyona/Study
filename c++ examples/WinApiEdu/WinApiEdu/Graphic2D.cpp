#include "Graphic2D.h"
#include "framework.h"

Graphic2D::Graphic2D()
{
}

Graphic2D::~Graphic2D()
{
}

void Graphic2D::DrawLine(HDC hdc, POINT start, POINT end, int width, COLORREF rgb)
{
    HPEN myPen;     // ����� ��
    HPEN oldPen;    // ������ ����� ��

    myPen = CreatePen(PS_SOLID, width, rgb);
    oldPen = (HPEN)SelectObject(hdc, myPen);

    // SelectObject() - (�� ��° �Ű�����) GDI - �׷��� ����̽� �������̽�, OBJ - ������Ʈ

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
    // DBI - Device Independent Bitmap(����̽��� ������ ��Ʈ��)
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

    BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, MemDC, 0, 0, SRCCOPY); // �ҽ�ī��

    SelectObject(MemDC, oldBitmap);

    DeleteObject(myBitmap);

    DeleteDC(MemDC);
}

void Graphic2D::DrawString(HDC hdc, wstring value, POINT pt, int size, COLORREF rgb)
{
    // 1. ��Ʈ ����
    HFONT myFont;
    HFONT oldFont;

    LOGFONT lf;
    wstring fontName = L"Segoe UI"; //��10���� ���Ǵ� ��Ʈ

    // �����͸� �� 0���� ����, �� ���� ���
    //memset(&lf, 0x00, sizeof(LOGFONT));
    ZeroMemory(&lf, sizeof(LOGFONT));

    lf.lfHeight = size;
    lf.lfWidth = 0;         // ���� ������� ���
    lf.lfEscapement = 0;
    lf.lfOrientation = 0; // 0,1,2,4 -- ���η� ���� �� �ִ�
    lf.lfWeight = 400; // ����
    lf.lfItalic = 0; // ���Ÿ�ü
    lf.lfUnderline = 0;
    lf.lfStrikeOut = 0;
    lf.lfCharSet = HANGUL_CHARSET;
  
    wcscpy_s(lf.lfFaceName, fontName.c_str());

    myFont = CreateFontIndirect(&lf);
    oldFont = (HFONT)SelectObject(hdc, myFont);
    
    SetTextColor(hdc, rgb);
    SetBkMode(hdc, TRANSPARENT);


    TextOut(hdc, pt.x, pt.y, value.c_str(), value.length());

    SelectObject(hdc, oldFont);
    DeleteObject(myFont);
}


