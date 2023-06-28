#include "framework.h"
#include "MomoPlayer.h"
#include "Render/Animation.h"
#include "Render/AnimClip.h"
#include "Render/Sprite.h"
#include "Scene/S01_Momodora.h"
#include "Scene/S02_Momodora.h"
#include "Collider/Line.h"
#include "Graphic2D.h"

MomoPlayer::MomoPlayer()
{
    Vector2 p1 = Vector2(-5, -5);
    Vector2 p2 = Vector2(5, 5);
    Vector2 p3 = Vector2(-5, 5);
    Vector2 p4 = Vector2(5, -5);
    Vector2 result;


    CreateAnim();
    m_collider = new Collider();

}

MomoPlayer::~MomoPlayer()
{
    delete m_collider;
    delete m_anim;
}

void MomoPlayer::PostRender()
{
    wstring value = L"FPS : " + to_wstring(TIMEMANAGER->GetFPS());
    POINT pt = POINT{0, 0};
    Graphic2D::DrawString(MAIN->GetHDC(), value, pt, 20, RGB(0, 0, 0));

    pt = POINT{ 0, 20 };
    Vector2 pos = MOUSE->GetPosition();
    value = L"Mouse(w) : " + to_wstring(pos.x);
    value += L", " + to_wstring(pos.y);
    Graphic2D::DrawString(MAIN->GetHDC(), value, pt, 20, RGB(255, 0, 255));

    CAMERA->WCtoVC(pos);

    pt = POINT{ 0, 40 };
    value = L"Camera(w) : " + to_wstring(pos.x);
    value += L", " + to_wstring(pos.y);
    Graphic2D::DrawString(MAIN->GetHDC(), value, pt, 20, RGB(255, 0, 255));

    vector<wstring> status;

    status.push_back(L"LEFT_IDLE"   );
    status.push_back(L"RIGHT_IDLE"     );
    status.push_back(L"LEFT_MOVE"      );
    status.push_back(L"RIGHT_MOVE"     );
    status.push_back(L"LEFT_JUMP"      );
    status.push_back(L"RIGHT_JUMP"     );
    status.push_back(L"LEFT_FALL"      );
    status.push_back(L"RIGHT_FALL"     );
    status.push_back(L"LEFT_ATTACK"    );
    status.push_back(L"RIGHT_ATTACK"   );
    status.push_back(L"ATTACK_CHARGE_L");
    status.push_back(L"ATTACK_CHARGE_R");
    status.push_back(L"LEFT_ATTACK_C"  );
    status.push_back(L"RIGHT_ATTACK_C" );

    pt = POINT{ 0, 60 };
    value = L"Status : " + status.at((UINT)m_state);
    Graphic2D::DrawString(MAIN->GetHDC(), value, pt, 20, RGB(255, 0, 255));
}

void MomoPlayer::Render()
{
    m_anim->Render();
    m_collider->Render();
    PostRender();
}

void MomoPlayer::Update()
{
    Vector2 pos = GetPosition();

    PreUpdate(pos);

    // 초기 상태, 하늘에서 떨어짐
    if (!m_isGround && !(IsJumping() || IsFalling()))
    {
        pos.y -= TIMEMANAGER->Delta() * m_speedX * 40.f;
    }
    else
    {

    }

    //A키로 점프
    if ((IsJumping() || IsFalling()) && !m_isGround)
    {
        pos.x += cosf(m_angle) * m_speedX;
        
        pos.y += sinf(m_angle) * m_speedY - m_gravity;
        m_gravity += 0.15f;
    }

    switch (m_state)
    {
    case LEFT_JUMP:
        if (m_gravity > m_speedY)
            SetState(State::LEFT_FALL);
        break;
    case RIGHT_JUMP:
        if (m_gravity > m_speedY)
            SetState(State::RIGHT_FALL);
        break;
    case LEFT_FALL:
        if (m_isGround)
            SetState(State::LEFT_IDLE);
        break;
    case RIGHT_FALL:
        if (m_isGround)
            SetState(State::RIGHT_IDLE);
        break;

    }

    // 땅에 닿으면 위치 조정
    GroundCheck(pos);
    ZoneCheck(pos);
    //WallCheck(pos);
    SetPosition(pos);

    // 애니메이션 정보 갱신
    m_anim->SetPosition(GetPosition());
    m_anim->SetScale(GetScale());
    m_anim->Update();

    // 콜라이더 정보 갱신
    m_collider->SetPosition(GetPosition());
    m_collider->SetScale(m_anim->GetSprite()->GetRealTextureSize());
    m_collider->Update();

}

void MomoPlayer::CreateAnim()
{
    m_anim = new Animation(L"./_Texture/Momodora/Player/momo_idle.png");

    //LEFT_IDLE
    {
        wstring img = L"./_Texture/Momodora/Player/momo_idle.png";
        CreateClip(img, 480 / 5, 40, 5, 1, 0.1f);
    }

    //RIGHT_IDLE
    {
        wstring img = L"./_Texture/Momodora/Player/momo_idle.png";
        CreateClip(img, 480 / 5, 130, 5, 1, 0.1f);
    }

    //LEFT_MOVE
    {
        wstring img = L"./_Texture/Momodora/Player/momo_run.png";
        CreateClip(img, 768 / 8, 40, 8, 1, 0.1f);
    }

    //RIGHT_MOVE
    {
        wstring img = L"./_Texture/Momodora/Player/momo_run.png";
        CreateClip(img, 768 / 8, 130, 8, 1, 0.1f);
    }

    //LEFT_JUMP
    {
        wstring img = L"./_Texture/Momodora/Player/momo_jump.png";
        CreateClip(img, 1056 / 11, 40, 11, 1, 0.1f);
    }

    //RIGHT_JUMP
    {
        wstring img = L"./_Texture/Momodora/Player/momo_jump.png";
        CreateClip(img, 1056 / 11, 130, 11, 1, 0.1f);
    }

    //LEFT_FALL
    {
        wstring img = L"./_Texture/Momodora/Player/momo_jump.png";
        CreateClip(img, 1056 / 11, 40, 11, 1, 0.1f);
    }

    //RIGHT_FALL
    {
        wstring img = L"./_Texture/Momodora/Player/momo_jump.png";
        CreateClip(img, 1056 / 11, 130, 11, 1, 0.1f);
    }

    //LEFT_ATTACK
    {
        wstring img = L"./_Texture/Momodora/Player/momo_attack.png";
        CreateClip(img, 384 / 4, 40, 4, 1, 0.1f);
    }

    //RIGHT_ATTACK
    {
        wstring img = L"./_Texture/Momodora/Player/momo_attack.png";
        CreateClip(img, 384 / 4, 130, 4, 1, 0.1f);
    }

    //ATTACK_CHARGE_L
    {
        wstring img = L"./_Texture/Momodora/Player/momo_idle.png";
        CreateClip(img, 480 / 5, 40, 5, 1, 0.1f);
    }

    //ATTACK_CHARGE_R
    {
        wstring img = L"./_Texture/Momodora/Player/momo_idle.png";
        CreateClip(img, 480 / 5, 130, 5, 1, 0.1f);
    }

    //LEFT_ATTACK_C
    {
        wstring img = L"./_Texture/Momodora/Player/momo_attack.png";
        CreateClip(img, 384 / 4, 40, 4, 1, 0.1f);
    }

    //RIGHT_ATTACK_C
    {
        wstring img = L"./_Texture/Momodora/Player/momo_attack.png";
        CreateClip(img, 384 / 4, 130, 4, 1, 0.1f);
    }
}

void MomoPlayer::CreateClip(wstring img, int w, int h, int count, int loop, float time)
{
    AnimClip::STATE state;
    if (loop)
    {
        state = AnimClip::LOOP;
    }
    else
    {
        state = AnimClip::ONCE;
    }

    //Idle_Left
    {
        AnimClip* clip = new AnimClip(state);
        m_anim->AddClip(clip);
        Sprite* sprite = m_anim->GetSprite();

        for (int i = 0; i < 5; ++i)
        {
            int sx = w * i + 24;
            int sy = h;
            int ex = sx + 48;
            int ey = sy + 62;
            clip->AddFrame(sprite, img, (float)sx, (float)sy, (float)ex, (float)ey, time);
        }
    }

}

void MomoPlayer::GroundCheck(Vector2& pos)
{
    // 픽셀 콜리전
    bool ground = false;
    Line* line = nullptr;

    Vector2 size = m_collider->GetScale();
    Vector2 AP1 = pos;
    Vector2 AP2 = Vector2(pos.x, pos.y - size.y * 0.5f);
    

    Scene* scene = SCENEMANAGER->GetCurScene();
    if (scene->GetName() == "S01_Momodora")
    {
        S01_Momodora* scene1 = DCAST<S01_Momodora*>(SCENEMANAGER->GetCurScene());

        if (scene1)
            line = scene1->GetLines();
    }

    if (scene->GetName() == "S02_Momodora")
    {
        S02_Momodora* scene2 = DCAST<S02_Momodora*>(SCENEMANAGER->GetCurScene());

        if (scene2)
            line = scene2->GetLines();
    }

    if (!line) return;

    Vector2 result;

    for (int i = 0; i < line->GetCountLine(); ++i)
    {
        Vector2 BP1 = line->GetStartPoint(i);
        Vector2 BP2 = line->GetEndPoint(i);

        if (Collision::LineIntersection(AP1, AP2, BP1, BP2, result))
        {
            ground = true;
            pos.y = result.y + size.y * 0.5f;
        }
        
    }

    m_isGround = ground;
}


bool MomoPlayer::IsJumping()
{
    return (m_state == LEFT_JUMP || m_state == RIGHT_JUMP);
}

bool MomoPlayer::IsFalling()
{
    return (m_state == LEFT_FALL || m_state == RIGHT_FALL);

}

bool MomoPlayer::IsMovingLeft()
{
    return (m_state == LEFT_JUMP || m_state == LEFT_FALL || m_state == LEFT_MOVE);
}

bool MomoPlayer::IsMovingRight()
{
    return (m_state == RIGHT_JUMP || m_state == RIGHT_FALL || m_state == RIGHT_MOVE);
}

// A : 점프
// S : 0.3초 이하 단발 공격, 그 이상 0.6 이하 첫 차지 공격, 그 이상은 풀 차지 공격
// 
void MomoPlayer::PreUpdate(Vector2& _pos)
{
    //VK_LEFT
    {
        if (KEYBOARD->Down(VK_LEFT))
        {
            // 현재 상태가 움직이고 있거나 점프/낙하 상태일 때 실행 X
            if (m_state != State::LEFT_MOVE && !IsJumping() && !IsFalling())
            {
                SetState(State::LEFT_MOVE);
            }

        }

        if (KEYBOARD->Up(VK_LEFT))
        {
            if (m_state != State::LEFT_IDLE)
            {
                if(m_isGround)
                    SetState(State::LEFT_IDLE);
            }
        }

        if (KEYBOARD->Press(VK_LEFT) && LeftCornerCheck(_pos))
        {
            if (m_state == State::LEFT_MOVE)
            {
                _pos.x -= 4.f;
            }

            if (IsJumping() || IsFalling())
                m_angle = LEFT_ANGLE;
        }
    }

    //VK_RIGHT
    {
        if (KEYBOARD->Down(VK_RIGHT))
        {
            // 현재 상태가 움직이고 있거나 점프/낙하 상태일 때 실행 X
            if (m_state != State::RIGHT_MOVE && !IsJumping() && !IsFalling())
            {
                SetState(State::RIGHT_MOVE);
            }

        }

        if (KEYBOARD->Up(VK_RIGHT))
        {
            if (m_state != State::RIGHT_IDLE)
            {
                if (m_isGround)
                    SetState(State::RIGHT_IDLE);
            }
        }

        if (KEYBOARD->Press(VK_RIGHT) && RightCornerCheck(_pos))
        {
            if (m_state == State::RIGHT_MOVE)
            {
                _pos.x += 4.f;
            }

            if (IsJumping() || IsFalling())
                m_angle = RIGHT_ANGLE;
        }
    }

    //A, 점프
    {
        if (KEYBOARD->Down('A'))
        {
            if (!m_isGround)// 점프 혹은 떨어지는 중
                return;

            if ((IsMovingLeft() || m_state == LEFT_IDLE) && (!IsJumping() && !IsFalling() && m_isGround))
            {
                m_isGround = false;
                SetState(State::LEFT_JUMP);
                m_angle = VERTICAL;
                m_gravity = 0.f;
            }

            if ((IsMovingRight() || m_state == RIGHT_IDLE) && (!IsJumping() && !IsFalling() && m_isGround))
            {
                m_isGround = false;
                SetState(State::RIGHT_JUMP);
                m_angle = VERTICAL;
                m_gravity = 0.f;
            }
        }
    }

    //S, 단발 공격, 차치 공격
    {
        if (KEYBOARD->Down('S'))
        {
            if ((m_state != State::LEFT_ATTACK) && (m_state != State::RIGHT_ATTACK))
            {
                if (IsMovingLeft() || m_state == LEFT_IDLE)
                {
                    SetState(State::LEFT_ATTACK);

                }
            }
        }
    }
}

void MomoPlayer::SetState(State stat)
{
    m_state = stat;

    m_anim->SetPlay((UINT)m_state);
}

bool MomoPlayer::LeftCornerCheck(Vector2& _pos)
{
    Collider* collider = nullptr;

    S01_Momodora* scene = (S01_Momodora*)SCENEMANAGER->GetCurScene();

    collider = scene->GetLeftZone();
    
    bool hit = Collision::HitTest(collider, m_collider);

    return (!hit);
}

bool MomoPlayer::RightCornerCheck(Vector2& _pos)
{
    Collider* collider = nullptr;

    S01_Momodora* scene = (S01_Momodora*)SCENEMANAGER->GetCurScene();

    collider = scene->GetRightZone();

    bool hit = Collision::HitTest(collider, m_collider);

    return (!hit);
}

void MomoPlayer::WallCheck(Vector2& pos)
{
    

}

void MomoPlayer::ZoneCheck(Vector2& pos)
{
    bool ground = false;
    Line* line = nullptr;

    Vector2 size = m_collider->GetScale();
    Vector2 AP1 = pos;
    Vector2 AP2 = Vector2(pos.x - size.x * 0.5f, pos.y);
    Vector2 AP3 = Vector2(pos.x + size.x * 0.5f, pos.y);

    Scene* scene = SCENEMANAGER->GetCurScene();
    if (scene->GetName() == "S01_Momodora")
    {
        S01_Momodora* scene1 = DCAST<S01_Momodora*>(SCENEMANAGER->GetCurScene());

        if (scene1)
            line = scene1->GetLines();
    }

    if (scene->GetName() == "S02_Momodora")
    {
        S02_Momodora* scene2 = DCAST<S02_Momodora*>(SCENEMANAGER->GetCurScene());

        if (scene2)
            line = scene2->GetLines();
    }

    if (!line) return;

    Vector2 result;

    for (int i = 0; i < line->GetCountLine(); ++i)
    {
        Vector2 BP1 = line->GetStartPoint(i);
        Vector2 BP2 = line->GetEndPoint(i);


        if (Collision::LineIntersection(AP1, AP2, BP1, BP2, result))
        {
            pos.x = result.x + size.x * 0.5f;
        }

    }

    for (int i = 0; i < line->GetCountLine(); ++i)
    {
        Vector2 BP1 = line->GetStartPoint(i);
        Vector2 BP2 = line->GetEndPoint(i);

        if (Collision::LineIntersection(AP1, AP3, BP1, BP2, result))
        {
            pos.x = result.x - size.x * 0.5f;
        }
    }
}

