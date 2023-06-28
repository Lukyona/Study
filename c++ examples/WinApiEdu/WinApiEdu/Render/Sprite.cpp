#include "framework.h"
#include "Sprite.h"
#include "Base/Matrix4x4.h"

Sprite::Sprite(wstring img)
{
    SRVMANAGER->CreateImage(img);
    m_imgFile = img;
    
    
    Vector2 size = SRVMANAGER->FindImageSize(img);

    SetOffset(0.f, 0.f);
    SetOffsetSize(size.x, size.y);
    SetTextureSize(size.x, size.y);


    //HBITMAP myBitmap, oldBitmap;

    //MemDC = CreateCompatibleDC(MAIN->GetHDC());
    //// DBI - Device Independent Bitmap(디바이스와 무관한 비트맵)
    //myBitmap = (HBITMAP)LoadImage(NULL, img.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    //BITMAP bitmap;
    //GetObject(myBitmap, sizeof(BITMAP), &bitmap);

    //oldBitmap = (HBITMAP)SelectObject(MemDC, myBitmap);
    //m_size = Vector2( bitmap.bmWidth, bitmap.bmHeight );

    //DeleteObject(myBitmap);

}

Sprite::Sprite(wstring img, float x, float y, float sizeX, float sizeY)
{
    SRVMANAGER->CreateImage(img);
    m_imgFile = img;

    Vector2 size = SRVMANAGER->FindImageSize(img);

    SetOffset(x, y);
    SetOffsetSize(sizeX - x, sizeY - y);
    SetTextureSize(size.x, size.y);



}

Sprite::~Sprite()
{
}

// DX Matrix --> 쉐이더로 보내는 역할
void Sprite::Update()
{

}

void Sprite::Render()
{
    Vector2 position = GetPosition();


    position.x = position.x - m_offsetSize.x / 2.f * m_scale.x;
    position.y = position.y + m_offsetSize.y * 0.5f * m_scale.y;

    CAMERA->VCtoWC(position);
    //Test(position);

    if (0) // win api 상에서 이미지를 회전하고 싶으면
    {
        Gdiplus::Matrix M;
        M.SetElements(-m_scale.x, 0.f, 0.f, m_scale.y, m_position.x + m_offsetSize.x*m_scale.x, m_position.y);
        M.RotateAt(45.f, PointF(m_offsetSize.x * 0.5f, m_offsetSize.y*0.5f), Gdiplus::MatrixOrderPrepend);

        Image* img = SRVMANAGER->FindGdiPlusImage(m_imgFile);
        RectF dest{ 0.f, 0.f, m_offsetSize.x, m_offsetSize.y };

        //Gdiplus용 메모리 DC
        Graphics graphic(MAIN->GetHDC());
        graphic.SetTransform(&M);
        graphic.DrawImage(img, dest, m_offset.x, m_offset.y, m_offsetSize.x, m_offsetSize.y, UnitPixel);
        return;

    }


    HDC hdc = SRVMANAGER->FindImage(m_imgFile);

    //마젠타 배경 제거
    GdiTransparentBlt(MAIN->GetHDC(), (int)position.x, (int)position.y, (int)(m_scale.x * m_offsetSize.x), (int)(m_scale.y * m_offsetSize.y), 
                        hdc, m_offset.x, m_offset.y, (int)m_offsetSize.x, (int)m_offsetSize.y, RGB(0, 0, 0));

    //BitBlt(MAIN->GetHDC(), x, y, m_size.x, m_size.y, MemDC, 0, 0, SRCCOPY); // 소스카피

}

Vector2 Sprite::GetRealTextureSize()
{
    Vector2 size = m_scale * m_offsetSize;


    return size;
}

void Sprite::Test(Vector2& pos)
{
    Matrix4x4 projection = Matrix4x4::GetCenterMatrix(MAIN->GetWidth(), MAIN->GetHeight());

    Matrix4x4 view;
    view.NormalVector();
    //view.Translation(1000.f, 500.f, 0.f);

    Matrix4x4 world;
    world.NormalVector();
    world.Translation(500.f, 370.f, 0.f);

    Matrix4x4 r = projection * view * world;
    Matrix4x4::Multiply(pos.x, pos.y, r);

    //projection.Out();
}
