#include "framework.h"
#include "Collision.h"

// 세 점을 이용해 면적을 구함
// Counter Clockwise - 반시계 방향
int Collision::CCW(Vector2 p1, Vector2 p2, Vector2 p3)
{
    // 실제 면적은 나누기 2 해야함. 삼각형이기 때문에.. 아래 식은 사각형 넓이임.
    double area = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);

    if (area > 0.00001)
        return 1; // 반시계 방향
    else if (area < 0.00001)
        return -1; // 시계 방향
    else
        return 0; // 일직선

    return 0;
}

int Collision::IsLeft(Vector2 p1, Vector2 p2)
{
    int ret;

    if (abs(p1.x - p2.x) < 0.000001f) // 두 점의 x좌표가 일치, y좌표로 구분
        ret = (p1.y <= p2.y);
    else                              // 두 점의 x좌표 불일치, 따라서 x좌표로 p1이 더 왼쪽인지 확인
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

// 1. CCW를 이용해 선분 교차 판단
// 2. 교차점 얻기 (but 수직일 때 계산 못 함)
// 이 두 가지를 합침
bool Collision::LineIntersection(Vector2 AP1, Vector2 AP2, Vector2 BP1, Vector2 BP2, Vector2& result)
{
    int ret;
    // CCW 이용해 교차 판단

    // 선분 A 기준으로 선분 B가 교차되었는지 확인
    int AB = CCW(AP1, AP2, BP1) * CCW(AP1, AP2, BP2); // 이게 음수(방향이 다름)면 교차된 것

    // 선분 B 기준으로 선분 A가 교차되었는지 확인
    int BA = CCW(BP1, BP2, AP1) * CCW(BP1, BP2, AP2);

    if (AB == 0 && BA == 0) //일직선
    {
        Vector2 ap1 = AP1;
        Vector2 ap2 = AP2;
        Vector2 bp1 = BP1;
        Vector2 bp2 = BP1;

        // 선분 A의 점을 p1 < p2 로 만들 예정
        if (IsLeft(AP2, AP1))
        {
            ap1 = AP2;
            ap2 = AP1;
        }
        // 선분 B의 점을 p1 < p2 로 만들 예정

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
