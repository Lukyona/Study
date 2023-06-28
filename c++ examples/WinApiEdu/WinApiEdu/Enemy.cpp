#include "framework.h"
#include "Enemy.h"

Enemy::Enemy()
{
    m_sprite = new Sprite(L"./honeyCup.png");

}

Enemy::~Enemy()
{
}

void Enemy::Render()
{
    m_sprite->Render();
}

void Enemy::Update()
{
    Vector2 pt1 = m_player->GetPosition();
    Vector2 pt2 = GetPosition();

    //���� �ܴ��� ������ �Ÿ�
    float dist = (pt1.x - pt2.x) * (pt1.x - pt2.x) + (pt1.y - pt2.y) * (pt1.y - pt2.y);
    dist = sqrt(dist);

    if (dist <= 300.f) // �Ÿ��� 300 ���ϸ�, �÷��̾��� ������ ���� ������ ���ǵ�� �̵��ؾ� ��
    {
        Vector2 pt = pt1 - pt2; // ����, ���� ���ϱ�
        Vector2 normal = pt.GetNormalized();

        Vector2 position = GetPosition();

        position += (normal * 3.f);


        //Vector2 position = pt2;

        //if (abs(pt1.y - pt2.y) >= 50)
        //{
        //    if (pt2.y <= pt1.y)
        //    {
        //        position.y += 5 * 2;
        //    }
        //    else
        //    {
        //        position.y -= 5 * 2;
        //    }

        //}
        //else
        //{
        //    if (pt2.x <= pt1.x)
        //    {
        //        position.x += 5 * 2;
        //    }
        //    else
        //    {
        //        position.x -= 5 * 2;
        //    }
        //}

        SetPosition(position);

        
        if (dist <= 50)
        {
            MessageBox(NULL, L"������!", L"Game", MB_OK);
            m_player->SetPosition(Vector2{ 100,100 });
            SetPosition(Vector2{ 700,500 });
        }

    }
    else //�� �̻��̸� �� �ڸ��� ���߱�
    {
        SetPosition(GetPosition());
    }


    m_sprite->SetPosition(GetPosition());
    //m_sprite->SetScale(GetScale());
    
}

RECT Enemy::GetRectangle()
{
    Vector2 pt = GetPosition();
    Vector2 size = m_sprite->GetSize();

    RECT rect;
    rect.top = pt.y - (size.y * 0.5f);
    rect.bottom = pt.y + (size.y * 0.5f);
    rect.left = pt.x - (size.x * 0.5f);
    rect.right = pt.x + (size.x * 0.5f);

    return rect;
}