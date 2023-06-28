#include "framework.h"
#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

void Collider::Update()
{
}

void Collider::Render()
{
    Vector2 size = GetScale();
    size *= 0.5f;
    Vector2 pos = GetPosition();

    Vector2 p1 = Vector2(pos.x - size.x, pos.y - size.y);
    Vector2 p2 = Vector2(pos.x + size.x, pos.y - size.y);
    Vector2 p3 = Vector2(pos.x + size.x, pos.y + size.y);
    Vector2 p4 = Vector2(pos.x - size.x, pos.y + size.y);

    CAMERA->VCtoWC(p1);
    CAMERA->VCtoWC(p2);
    CAMERA->VCtoWC(p3);
    CAMERA->VCtoWC(p4);


    HPEN myPen;     // ����� ��
    HPEN oldPen;    // ������ ����� ��

    myPen = CreatePen(PS_SOLID, 1, rgb);
    oldPen = (HPEN)SelectObject(MAIN->GetHDC(), myPen);

    // SelectObject() - (�� ��° �Ű�����) GDI - �׷��� ����̽� �������̽�, OBJ - ������Ʈ

    MoveToEx(MAIN->GetHDC(),(int)p1.x, (int)p1.y, NULL);

    LineTo(MAIN->GetHDC(), (int)p2.x, (int)p2.y);
    LineTo(MAIN->GetHDC(), (int)p3.x, (int)p3.y);
    LineTo(MAIN->GetHDC(), (int)p4.x, (int)p4.y);
    LineTo(MAIN->GetHDC(), (int)p1.x, (int)p1.y);

    SelectObject(MAIN->GetHDC(), oldPen);

    DeleteObject(myPen);
}
