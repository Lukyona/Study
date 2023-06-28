#include "framework.h"
#include "S02_Bee.h"
#include "Player.h"
#include "Enemy.h"
#include "Render/Animation.h"
#include "Render/AnimClip.h"

S02_Bee::S02_Bee()
{
    CAMERA->SetPosition(Vector2(300.f, 0.f));
    m_player = new Player();
    m_enemy = new Enemy();

    m_player->SetPosition(POINT{ 300,300 });
    m_enemy->SetPosition(POINT{ 800,600 });
    m_enemy->SetPlayer(m_player);
    m_background = new Sprite(L"./_Texture/Momodora/background1.png");

    m_anim = new Animation(L"./_Texture/Momodora/Player/momo_idle.png");
    {
        AnimClip* clip = new AnimClip(AnimClip::LOOP);
        m_anim->AddClip(clip);
        Sprite* sprite = m_anim->GetSprite();

        wstring img = L"./_Texture/Momodora/Player/momo_idle.png";

        int x = 480 / 5;
        int y = 192 / 2;

        for (int i = 0; i < 5; ++i)
        {
            int sx = x * i + 24;
            int sy = 40;
            int ex = sx + 48;
            int ey = sy + 62;
            clip->AddFrame(sprite, img, (float)sx, (float)sy, (float)ex, (float)ey, 0.1f);

        }

    }

}

S02_Bee::~S02_Bee()
{
}

void S02_Bee::Update()
{
    //콜리전 체크
    RECT result;
    RECT A, B;

    A = m_player->GetRectangle();
    B = m_enemy->GetRectangle();

    //if (IntersectRect(&result, &A, &B)) // A와 B가 겹쳤으면
    //{
    //    MessageBox(NULL, L"도망!", L"Game", MB_OK);
    //}


    m_background->Update();

    m_player->Update();
    m_enemy->Update();
    m_anim->Update();
}

void S02_Bee::Render()
{
    //HDC hdc = MAIN->GetHDC();

    //wstring backgroundFile = L"./background.bmp";
    //wstring beeFile = L"./honeyBee.PNG";
    //wstring cupFile = L"./honeyCup.PNG";

    //DrawBitmap(hdc, POINT{ 0,0 }, backgroundFile);

    m_background->Render();

    m_player->Render();
    m_enemy->Render();

    m_anim->Render();

    CAMERA->Render();

}

void S02_Bee::DrawBitmap(HDC hdc, POINT pos, wstring imgFile)
{
    HDC MemDC;
    HBITMAP myBitmap, oldBitmap;

    MemDC = CreateCompatibleDC(hdc);


    static int count;

    count++;

    // DBI - Device Independent Bitmap(디바이스와 무관한 비트맵)
    myBitmap = (HBITMAP)LoadImage(NULL, imgFile.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    BITMAP bitmap;
    GetObject(myBitmap, sizeof(BITMAP), &bitmap);

    oldBitmap = (HBITMAP)SelectObject(MemDC, myBitmap);


    GdiTransparentBlt(hdc, 0, 0, bitmap.bmWidth * 2, bitmap.bmHeight * 2, MemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, RGB(255, 0, 255));

    //BitBlt(hdc, 0, 0, 640,330, MemDC, 0, 0, SRCCOPY); // 소스카피


    SelectObject(MemDC, oldBitmap);

    DeleteObject(myBitmap);

    DeleteDC(MemDC);
}
