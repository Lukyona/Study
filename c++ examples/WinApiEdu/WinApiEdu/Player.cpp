#include "framework.h"
#include "Player.h"

Player::Player()
{
    m_sprite = new Sprite(L"./honeyBee.bmp");
}

Player::~Player()
{
}

void Player::Render()
{
    m_sprite->Render();
}

void Player::Update()
{
    POINT pt = GetPosition();
    POINT size = m_sprite->GetSize();

    size.x *= 0.5f;
    size.y *= 0.5f;


    RECT rect;
    GetClientRect(MAIN->GetWindowHandle(), &rect);

    if (MAIN->GetCharacter() == 'A')
        pt.x -= 10 * 2;
    if (MAIN->GetCharacter() == 'D')
        pt.x += 10 * 2;
    if (MAIN->GetCharacter() == 'W')
        pt.y -= 10 * 2;
    if (MAIN->GetCharacter() == 'S')
        pt.y += 10 * 2;

    if (pt.x <= size.x)
        pt.x = size.x;

    if (pt.x >= MAIN->GetWidth() - size.x)
        pt.x = MAIN->GetWidth() - size.x;

    if (pt.y <= size.y)
        pt.y = size.y;

    if (pt.y >= MAIN->GetHeight() - size.y)
        pt.y = MAIN->GetHeight() - size.y;


    SetPosition(pt);

    m_sprite->SetPosition(GetPosition());

}

RECT Player::GetRectangle()
{
    POINT pt = GetPosition();
    POINT size = m_sprite->GetSize();

    RECT rect;
    rect.top = pt.y - (size.y * 0.5f);
    rect.bottom = pt.y + (size.y * 0.5f);
    rect.left = pt.x - (size.x * 0.5f);
    rect.right = pt.x + (size.x * 0.5f);

    return rect;
}
