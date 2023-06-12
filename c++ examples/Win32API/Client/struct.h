#pragma once


struct Vec2
{
    float  x;
    float  y;

public:
    Vec2()
        :x(0.f), y(0.f)
    {}

    Vec2(float _x, float _y)
        :x(_x), y(_y)
    {}

    Vec2(int _x, int _y)
        : x((float)_x), y((float)_y)
    {}


    Vec2& operator = (POINT _pt)
    {
        x = (float)_pt.x;
        y = (float)_pt.y;
    }

    Vec2(const POINT& _pt)
        :x((float)_pt.x), y((float)_pt.y)
    {

    }


    float Length()
    {
        return sqrt(x* x + y * y);
    }

    Vec2& Normalize() //정규화, 단위화, 방향을 유지한 채로 벡터 길이 1로 만들기
    {
        float len = Length();

        assert(len != 0.f); // (0,0)이면 오류

        x /= len;
        y /= len;

        return *this;
    }
};