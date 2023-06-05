#include "framework.h"
#include "Sprite.h"

Sprite::Sprite(wstring img, POINT pt)
{
    HBITMAP myBitmap, oldBitmap;

    MemDC = CreateCompatibleDC(MAIN->GetHDC());
    // DBI - Device Independent Bitmap(����̽��� ������ ��Ʈ��)
    myBitmap = (HBITMAP)LoadImage(NULL, img.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    BITMAP bitmap;
    GetObject(myBitmap, sizeof(BITMAP), &bitmap);

    oldBitmap = (HBITMAP)SelectObject(MemDC, myBitmap);
    m_size = POINT{ bitmap.bmWidth, bitmap.bmHeight };

    DeleteObject(myBitmap);

}

Sprite::~Sprite()
{
}

void Sprite::Update()
{
    if (MemDC)
    {
        DeleteDC(MemDC);
        MemDC = NULL;
    }
}

void Sprite::Render()
{
    int x = GetPosition().x - m_size.x * 0.5f;
    int y = GetPosition().y - m_size.y * 0.5f;

    //����Ÿ ��� ����
    GdiTransparentBlt(MAIN->GetHDC(), x, y, m_size.x, m_size.y, MemDC, 0, 0, m_size.x, m_size.y, RGB(255, 0, 255));

    //BitBlt(MAIN->GetHDC(), x, y, m_size.x, m_size.y, MemDC, 0, 0, SRCCOPY); // �ҽ�ī��

}
