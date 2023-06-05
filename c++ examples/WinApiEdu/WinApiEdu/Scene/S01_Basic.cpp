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

    Polygon(hdc, tri, 4); //3이든 4든 똑같, 안을 채움
    //Polyline(hdc, tri, 4); // 라인은 안을 채우지 않음, 점 4개

    TextOut(hdc, 50, 50, L"ABCDEGFH", 8);

    //베지어 곡선, 점을 통해 곡선을 그려줌
    PolyBezier(hdc, tri, 4);

    int cx = 300;
    int cy = 300;
    int r = 100;

    POINT pt[400];
    for (int i = 0; i < 360; i++) // 360도 원 그리기
    {
        pt[i].x = cx + r * (int)cosf(i * 180 * 3.14f);
        pt[i].y = cy + r * (int)sinf(i * 180 * 3.14f);

    }
    Polygon(hdc, pt, 360);
}

// 1. 자신이 사용할 펜 생성
// 2. DC에 사용될 펜을 등록
// 3. 사용 전 펜을 old pen에 저장
// 4. MoveTo LineTo 사용
// 5. old pen으로 DC에 복귀
// 6. 자신이 생성한 펜을 제거

void S01_Basic::DrawLine(HDC hdc, POINT start, POINT end, int width, COLORREF rgb)
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

// DrawLine과 그리는 함수 빼고 과정이 같음
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


// 1. MemDC(메모리DC) 생성 : 중간에 그려질 DC 생성
// 2. 자신이 사용할 비트맵 생성
// 3. 비트맵 파일의 정보 얻기
// 4. DC에 사용할 비트맵 등록하고 oldBitmap
// 5.
void S01_Basic::DrawBitmap(HDC hdc, POINT pos, wstring imgFile)
{
    HDC MemDC;
    HBITMAP myBitmap, oldBitmap;

    MemDC = CreateCompatibleDC(hdc);

    static int count;

    count++;
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

    //GdiTransparentBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, MemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, RGB(255, 0, 255));
   // GdiTransparentBlt(hdc, 0, 0, 180, 190, MemDC, 0, 0, 180, 190, RGB(255,0,255));


    //if (count <= 5)
    //    GdiTransparentBlt(hdc, pos.x, pos.y, 180, 190, MemDC, 0, 0, 180, 190, RGB(255, 0, 255));
    //else if (count <= 10)
    //    GdiTransparentBlt(hdc, pos.x, pos.y, 355-190, 192, MemDC, 190, 0, 355-190, 192, RGB(255, 0, 255));
    //else
    //    count = 0;


   // BitBlt(hdc, 0, 0, 180,190, MemDC, 0, 0, SRCCOPY); // 소스카피
    
    SelectObject(MemDC, oldBitmap);

    DeleteObject(myBitmap);

    DeleteDC(MemDC);
}
