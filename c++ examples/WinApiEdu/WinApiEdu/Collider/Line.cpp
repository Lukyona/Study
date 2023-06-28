#include "framework.h"
#include "Line.h"

Line::Line()
{
}

Line::~Line()
{
    for (UINT i = 0; i < m_lines.size(); ++i)
    {
        delete m_lines[i];
    }
    m_lines.erase(m_lines.begin(), m_lines.end());
}

void Line::DrawLine(Vector2 start, Vector2 end, COLORREF rgb)
{
    HPEN myPen;     // 사용할 펜
    HPEN oldPen;    // 이전에 사용한 펜

    myPen = CreatePen(PS_SOLID, 1, rgb);
    oldPen = (HPEN)SelectObject(MAIN->GetHDC(), myPen);

    // SelectObject() - (두 번째 매개변수) GDI - 그래픽 디바이스 인터페이스, OBJ - 오브젝트

    MoveToEx(MAIN->GetHDC(), (int)start.x, (int)start.y, NULL);

    LineTo(MAIN->GetHDC(), (int)end.x, (int)end.y);

    SelectObject(MAIN->GetHDC(), oldPen);

    DeleteObject(myPen);
}

void Line::Update()
{
}

void Line::Render()
{
    if (m_lines.size() == 0) return;

    for (int i = 0; i < GetCountLine(); ++i)
    {
        Vector2 start = Vector2(m_lines[i * 2]->x, m_lines[i * 2]->y);
        Vector2 end = Vector2(m_lines[i*2+1]->x, m_lines[i * 2 + 1]->y);

        CAMERA->VCtoWC(start);
        CAMERA->VCtoWC(end);

        DrawLine(start, end, RGB(255, 0, 255));
    }
}

void Line::AddLine(float x1, float y1, float x2, float y2)
{
    Vector2* start = new Vector2();
    start->x = x1;
    start->y = y1;

    Vector2* end = new Vector2();
    end->x = x2;
    end->y = y2;

    m_lines.push_back(start);
    m_lines.push_back(end);

}

Vector2 Line::GetStartPoint(int id)
{
    Vector2 pos = Vector2(m_lines[id * 2]->x, m_lines[id * 2]->y);
    return pos;
}

Vector2 Line::GetEndPoint(int id)
{
    Vector2 pos = Vector2(m_lines[id * 2 + 1]->x, m_lines[id * 2 +1]->y);
    return pos;
}


