#include "framework.h"
#include "Camera.h"

Camera::Camera()
{
    m_projection = Matrix4x4::GetCenterMatrix(MAIN->GetWidth(), MAIN->GetHeight());

    Vector3 eye = Vector3(m_position.x, m_position.y, 0.f);
    Vector3 up = Vector3(0.f, 1.f, 0.f);
    Vector3 at = Vector3(0.f, 0.f, 1.f);

    m_view = Matrix4x4::LookAt(eye, (eye + at), up);

    m_sprite = new Sprite(L"./_Texture/image/Camera.png");
    m_sprite->SetScale(Vector2(0.5f, 0.5f));

    PV = m_projection * m_view;
}

Camera::~Camera()
{
}

void Camera::Update()
{
    Vector2 pos = GetPosition();

    if (m_Object)
        pos = m_Object->GetPosition();

    {
        if (pos.x <= m_cornerLeft.x)
            pos.x = m_cornerLeft.x;

        if (pos.y <= m_cornerLeft.y)
            pos.y = m_cornerLeft.y;

        if (pos.x >= m_cornerRight.x)
            pos.x = m_cornerRight.x;

        if (pos.y >= m_cornerRight.y)
            pos.y = m_cornerRight.y;
    }


    Vector3 eye = Vector3(m_position.x, m_position.y, 0.f);
    Vector3 up = Vector3(0.f, 1.f, 0.f);
    Vector3 at = Vector3(0.f, 0.f, 1.f);

    m_view = Matrix4x4::LookAt(eye, (eye + at), up);
    PV = m_projection * m_view;

    SetPosition(pos);
    m_sprite->SetPosition(pos);

}

void Camera::Render()
{
    m_sprite->Render();
}

// View Coord -> Window Coord
void Camera::VCtoWC(Vector2& pos)
{
    Matrix4x4::Multiply(pos.x, pos.y, PV);

}

void Camera::WCtoVC(Vector2& pos)
{
    Matrix4x4 S, T, V;
    S = Matrix4x4::Scale(1.f, -1.f, 0.f);
    T = Matrix4x4::Translation(-(float)MAIN->GetWidth() * 0.5f, -(float)MAIN->GetHeight() * 0.5f, 0.f);

    Vector3 eye = Vector3(-m_position.x, -m_position.y, 0.f);
    Vector3 up = Vector3(0.f, 1.f, 0.f);
    Vector3 at = Vector3(0.f, 0.f, 1.f);
    V = Matrix4x4::LookAt(eye, (eye + at), up);

    Matrix4x4 result = T * V * S;
    Matrix4x4::Multiply(pos.x, pos.y, result);

}
