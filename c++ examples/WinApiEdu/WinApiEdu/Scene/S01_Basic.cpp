#include "framework.h"
#include "S01_Basic.h"
#include <algorithm>

S01_Basic::S01_Basic()
{
    SetActive(true);
}

S01_Basic::~S01_Basic()
{
}

void S01_Basic::Update()
{
}

void S01_Basic::Render()
{
    HDC hdc = MAIN->GetHDC();
    //BlackRender();

    POINT start = { 0, 0 };
    POINT end = { 100, 100 };

   // DrawLine(hdc, start, end, 10, RGB(255, 0, 0));
   // DrawRectangle(hdc, 0, 0, 200,200, RGB(130, 130, 130));
    wstring imgFile = L"./test.bmp";

    static int x;

    x++;


    DrawBitmap(hdc, POINT{ x,0 }, imgFile);
    
}

void S01_Basic::BlackRender()
{
    HDC hdc = MAIN->GetHDC();

    MoveToEx(hdc, 10, 10, NULL);
    LineTo(hdc, 500, 500);

    Rectangle(hdc, 100, 100, 800, 600);

    Ellipse(hdc, 300, 300, 400, 600);

    POINT tri[4];
    tri[0].x = 100;
    tri[0].y = 100;
    tri[1].x = 200;
    tri[1].y = 80;
    tri[2].x = 70;
    tri[2].y = 170;
    tri[3].x = 100;
    tri[3].y = 100;

    Polygon(hdc, tri, 4); //3�̵� 4�� �Ȱ�, ���� ä��
    //Polyline(hdc, tri, 4); // ������ ���� ä���� ����, �� 4��

    TextOut(hdc, 50, 50, L"ABCDEGFH", 8);

    //������ �, ���� ���� ��� �׷���
    PolyBezier(hdc, tri, 4);

    int cx = 300;
    int cy = 300;
    int r = 100;

    POINT pt[400];
    for (int i = 0; i < 360; i++) // 360�� �� �׸���
    {
        pt[i].x = cx + r * (int)cosf(i * 180 * 3.14f);
        pt[i].y = cy + r * (int)sinf(i * 180 * 3.14f);

    }
    Polygon(hdc, pt, 360);
}

// 1. �ڽ��� ����� �� ����
// 2. DC�� ���� ���� ���
// 3. ��� �� ���� old pen�� ����
// 4. MoveTo LineTo ���
// 5. old pen���� DC�� ����
// 6. �ڽ��� ������ ���� ����

void S01_Basic::DrawLine(HDC hdc, POINT start, POINT end, int width, COLORREF rgb)
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

// DrawLine�� �׸��� �Լ� ���� ������ ����
void S01_Basic::DrawRectangle(HDC hdc, int x, int y, int width, int height, COLORREF rgb)
{
    HBRUSH myBrush;
    HBRUSH oldBrush;

    myBrush = CreateSolidBrush(rgb);
    oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

    Rectangle(hdc, x, y, width, height);

    SelectObject(hdc, oldBrush);

    DeleteObject(myBrush);

}


// 1. MemDC(�޸�DC) ���� : �߰��� �׷��� DC ����
// 2. �ڽ��� ����� ��Ʈ�� ����
// 3. ��Ʈ�� ������ ���� ���
// 4. DC�� ����� ��Ʈ�� ����ϰ� oldBitmap
// 5.
void S01_Basic::DrawBitmap(HDC hdc, POINT pos, wstring imgFile)
{
    HDC MemDC;
    HBITMAP myBitmap, oldBitmap;

    MemDC = CreateCompatibleDC(hdc);

    static int count;

    count++;
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

    //GdiTransparentBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, MemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, RGB(255, 0, 255));
   // GdiTransparentBlt(hdc, 0, 0, 180, 190, MemDC, 0, 0, 180, 190, RGB(255,0,255));


    //if (count <= 5)
    //    GdiTransparentBlt(hdc, pos.x, pos.y, 180, 190, MemDC, 0, 0, 180, 190, RGB(255, 0, 255));
    //else if (count <= 10)
    //    GdiTransparentBlt(hdc, pos.x, pos.y, 355-190, 192, MemDC, 190, 0, 355-190, 192, RGB(255, 0, 255));
    //else
    //    count = 0;


   // BitBlt(hdc, 0, 0, 180,190, MemDC, 0, 0, SRCCOPY); // �ҽ�ī��
    
    SelectObject(MemDC, oldBitmap);

    DeleteObject(myBitmap);

    DeleteDC(MemDC);
}
