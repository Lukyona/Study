#include "SRVMgr.h"
#include "framework.h"

SRVMgr::SRVMgr()
{
}

SRVMgr::~SRVMgr()
{
    for (auto a : m_sprites)
    {
        delete a.second;
    }

    m_sprites.clear();
}

HDC SRVMgr::CreateImage(wstring fileName)
{
    if (m_sprites.find(fileName) != m_sprites.end())
    {
        return m_sprites[fileName]->MemDC;
    }

    SpriteResource* sprite = new SpriteResource();

    sprite->m_image = new Image(fileName.c_str());
    sprite->m_spriteSize.x = (float)sprite->m_image->GetWidth();
    sprite->m_spriteSize.y = (float)sprite->m_image->GetHeight();

    // �޸�DC ����
    HDC hdc = GetDC(MAIN->GetWindowHandle());
    sprite->MemDC = CreateCompatibleDC(hdc);

    HBITMAP hBitmap = CreateCompatibleBitmap(hdc, sprite->m_image->GetWidth(), sprite->m_image->GetHeight());

    SelectObject(sprite->MemDC, hBitmap);


    // Gdiplus�� �̿��Ͽ� ��Ʈ�ʿ� �����
    Graphics graphic(sprite->MemDC); // �׷����� DC ����
    RectF dest(0.f, 0.f, sprite->m_spriteSize.x, sprite->m_spriteSize.y); //������

    graphic.DrawImage(sprite->m_image, dest, 0.f, 0.f, sprite->m_spriteSize.x, sprite->m_spriteSize.y, UnitPixel);
    
    m_sprites.insert(make_pair(fileName, sprite));

    return sprite->MemDC;
}

HDC SRVMgr::FindImage(wstring fileName)
{
    if (m_sprites.find(fileName) != m_sprites.end())
    {
        return m_sprites[fileName]->MemDC;
        
    }
    return nullptr;
}

Image* SRVMgr::FindGdiPlusImage(wstring fileName)
{
    if (m_sprites.find(fileName) != m_sprites.end())
    {
        return m_sprites[fileName]->m_image;

    }
    return nullptr;
}

Vector2 SRVMgr::FindImageSize(wstring fileName)
{
    if (m_sprites.find(fileName) != m_sprites.end())
    {
        return m_sprites[fileName]->m_spriteSize;

    }
    return Vector2(0.f, 0.f);
}
