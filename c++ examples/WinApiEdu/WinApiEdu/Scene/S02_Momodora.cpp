#include "framework.h"
#include "Objects/MomoPlayer.h"
#include "S02_Momodora.h"

S02_Momodora::S02_Momodora()
{
    SetName("S02_Momodora");

    m_background = new Sprite(L"./_Texture/Momodora/background1.png");

    Vector2 size = m_background->GetSize();
    Vector2 pos;

    pos.x = -(size.x * 0.5f - MAIN->GetWidth() * 0.5f);
    pos.y = 0.f;

    CAMERA->SetPosition(pos);
    CAMERA->SetCornerLeft(Vector2(-size.x*0.5f+ MAIN->GetWidth() * 0.5f, 0.f));
    CAMERA->SetCornerRight(Vector2(size.x*0.5f+ MAIN->GetWidth() * 0.5f, 0.f));

    if (!OBJECTMANAGER->FindObject("Momo"))
    {
        MomoPlayer* player = new MomoPlayer();
        player->SetPosition(Vector2(-320.f, 0.f));
        OBJECTMANAGER->AddObject("Momo", player);

        MomoPlayer* player2 = dynamic_cast<MomoPlayer*>(ObjectFactory <MomoPlayer>::Create("Momo"));

        CAMERA->SetObject(player);
    }




    // 그라운드 라인 생성
    m_ground = new Line();
    m_ground->AddLine(-960.f, -216.f, 960.f, -216.f);
    m_ground->AddLine(-961.5f, MAIN->GetHeight(), -961.5f, MAIN->GetHeight());
   // m_ground->AddLine(-624.f, -165.f, 960.f, -216.f);

    ZoneLeft = new Collider();
    Vector2 pos2 = Vector2(-size.x * 0.5f, 0.f);
    ZoneLeft->SetPosition(pos2);
    pos2 = Vector2(4.f, size.y);
    ZoneLeft->SetScale(pos2);

    ZoneRight = new Collider();
    pos2 = Vector2(size.x * 0.5f, 0.f);
    ZoneRight->SetPosition(pos2);
    pos2 = Vector2(4.f, size.y);
    ZoneRight->SetScale(pos2);


}

S02_Momodora::~S02_Momodora()
{
    delete m_background;
    delete m_ground;
}

void S02_Momodora::Update()
{
    OBJECTMANAGER->Update("Momo");

    m_background->Update();
    m_ground->Update();

    ZoneLeft->Update();
    ZoneRight->Update();
}

// Collider를 등록
// 이벤트 패턴, Collision이 발생하면 Noti를 주는 형태

void S02_Momodora::Render()
{
    m_background->Render();
    m_ground->Render();
    OBJECTMANAGER->Render("Momo");
    ZoneLeft->Render();
    ZoneRight->Render();


}

Line* S02_Momodora::GetLines()
{
    return m_ground;
}

Collider* S02_Momodora::GetLeftZone()
{
    return ZoneLeft;
}

Collider* S02_Momodora::GetRightZone()
{
    return ZoneRight;
}
