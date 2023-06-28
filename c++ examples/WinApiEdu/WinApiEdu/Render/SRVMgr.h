#pragma once
#include "framework.h"
#define SRVMANAGER SRVMgr::GetInstance() 


class SRVMgr // Ω¶¿Ã¥ı ∏Æº“Ω∫ ∫‰ ∏≈¥œ¿˙
{
private:
    SRVMgr();

    struct SpriteResource
    {
        Image* m_image = nullptr;
        HDC MemDC = nullptr;
        Vector2 m_spriteSize;
    };

    map<wstring, SpriteResource*> m_sprites;

public:
    ~SRVMgr();
    
    static SRVMgr* GetInstance()
    {
        static SRVMgr singleton;
        return &singleton;
    }

    HDC CreateImage(wstring fileName);
    HDC FindImage(wstring fileName);
    Image* FindGdiPlusImage(wstring fileName);
    Vector2 FindImageSize(wstring fileName);


};

