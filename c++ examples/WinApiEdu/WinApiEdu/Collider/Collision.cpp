#include "framework.h"
#include "Collision.h"

// �� ���� �̿��� ������ ����
// Counter Clockwise - �ݽð� ����
int Collision::CCW(Vector2 p1, Vector2 p2, Vector2 p3)
{
    // ���� ������ ������ 2 �ؾ���. �ﰢ���̱� ������.. �Ʒ� ���� �簢�� ������.
    double area = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);

    if (area > 0.00001)
        return 1; // �ݽð� ����
    else if (area < 0.00001)
        return -1; // �ð� ����
    else
        return 0; // ������

    return 0;
}

int Collision::IsLeft(Vector2 p1, Vector2 p2)
{
    int ret;

    if (abs(p1.x - p2.x) < 0.000001f) // �� ���� x��ǥ�� ��ġ, y��ǥ�� ����
        ret = (p1.y <= p2.y);
    else                              // �� ���� x��ǥ ����ġ, ���� x��ǥ�� p1�� �� �������� Ȯ��
        ret = (p1.x <= p2.x);

    return ret;
}

bool Collision::AABB(Collider* A, Collider* B)
{
    float ax1 = A->GetPosition().x - (A->GetScale().x * 0.5f);
    float ax2 = A->GetPosition().x + (A->GetScale().x * 0.5f);
    float ay1 = A->GetPosition().y - (A->GetScale().y * 0.5f);
    float ay2 = A->GetPosition().y + (A->GetScale().y * 0.5f);

    float bx1 = B->GetPosition().x - (B->GetScale().x * 0.5f);
    float bx2 = B->GetPosition().x + (B->GetScale().x * 0.5f);
    float by1 = B->GetPosition().y - (B->GetScale().y * 0.5f);
    float by2 = B->GetPosition().y + (B->GetScale().y * 0.5f);


    if (max(ax1, ax2) < min(bx1, bx2) || max(bx1, bx2) < min(ax1, ax2))
    {
        return false;
    }

    if (max(ay1, ay2) < min(by1, by2) || max(by1, by2) < min(ay1, ay2))
    {
        return false;
    }

    return true;
}

bool Collision::OBB(Collider* A, Collider* B)
{
    return false;

}

Collision::Collision()
{
}

Collision::~Collision()
{
}

bool Collision::HitTest(Collider* A, Collider* B)
{
    bool result = AABB(A, B);

    return result;

    if (result)
        return OBB(A, B);



    return false;
}

// 1. CCW�� �̿��� ���� ���� �Ǵ�
// 2. ������ ��� (but ������ �� ��� �� ��)
// �� �� ������ ��ħ
bool Collision::LineIntersection(Vector2 AP1, Vector2 AP2, Vector2 BP1, Vector2 BP2, Vector2& result)
{
    int ret;
    // CCW �̿��� ���� �Ǵ�

    // ���� A �������� ���� B�� �����Ǿ����� Ȯ��
    int AB = CCW(AP1, AP2, BP1) * CCW(AP1, AP2, BP2); // �̰� ����(������ �ٸ�)�� ������ ��

    // ���� B �������� ���� A�� �����Ǿ����� Ȯ��
    int BA = CCW(BP1, BP2, AP1) * CCW(BP1, BP2, AP2);

    if (AB == 0 && BA == 0) //������
    {
        Vector2 ap1 = AP1;
        Vector2 ap2 = AP2;
        Vector2 bp1 = BP1;
        Vector2 bp2 = BP1;

        // ���� A�� ���� p1 < p2 �� ���� ����
        if (IsLeft(AP2, AP1))
        {
            ap1 = AP2;
            ap2 = AP1;
        }
        // ���� B�� ���� p1 < p2 �� ���� ����

        if (IsLeft(BP2, BP1))
        {
            bp1 = BP2;
            bp2 = BP1;
        }



        // ap1 ------------ap2
        //      bp1 ----------bp2

        ret = (int)(IsLeft(bp1, ap2) && IsLeft(ap1, bp2));

        if (ret)
        {
            result = bp1;
            return true;

        }
        else
            return false;


    }
    else
    {
        ret = (AB <= 0) && (BA <= 0);
    }

    if (ret == 0)
        return false;

    double under = (BP2.y - BP1.y) * (AP2.x - AP1.x) - (BP2.x - BP1.x) * (AP2.y - AP1.y);
    double _t = (double)(BP2.x - BP1.x) * (AP1.y - BP1.y) - (BP2.y - BP1.y) * (AP1.x - BP1.x);
    double _s = (double)(AP2.x - AP1.x) * (AP1.y - BP1.y) - (AP2.y - AP1.y) * (AP1.x - BP1.x);

    double t = _t / under;
    double s = _s / under;

    result.x = (float)(AP1.x + t * (double)(AP2.x - AP1.x));
    result.y = (float)(AP1.y + t * (double)(AP2.y - AP1.y));

    return true;
    
    
    return false;
}
