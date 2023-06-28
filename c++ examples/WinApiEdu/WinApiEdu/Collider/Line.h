#pragma once
class Line
{
private:
    vector<Vector2*> m_lines;

    void DrawLine(Vector2 start, Vector2 end, COLORREF rgb);

public:
    Line();
    ~Line();

    void Update();
    void Render();

    void AddLine(float x1, float y1, float x2, float y2);

    int GetCountLine() { return (int)m_lines.size()/2; }

    Vector2 GetStartPoint(int id);
    Vector2 GetEndPoint(int id);
};

