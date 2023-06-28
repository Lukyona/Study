#pragma once
#include "framework.h"
#define CAMERA Camera::GetInstance()
class Camera
{
private:
    class Sprite* m_sprite = nullptr;

    Camera();

    Matrix4x4 m_projection;
    Matrix4x4 m_view;
    Matrix4x4 PV;

    
    GameObject* m_Object = nullptr;

    Vector2 m_position = Vector2(0.f, 0.f);
    Vector2 m_scale = Vector2(1.f, 1.f);

    Vector2 m_cornerLeft = Vector2(0.f, 0.f);
    Vector2 m_cornerRight = Vector2(0.f, 0.f);

public:
    ~Camera();

    static Camera* GetInstance()
    {
        static Camera singleton;
        return &singleton;
    }

    void Update();
    void Render();

    void SetPosition(Vector2 pt) { m_position = pt; }
    void SetScale(Vector2 size) { m_scale = size; }

    Vector2 GetPosition() { return m_position; }
    Vector2 GetScale() { return m_scale; }

    Matrix4x4 GetProjectionMatrix() { return m_projection; }
    Matrix4x4 GetViewMatrix() { return m_view; }

    void VCtoWC(Vector2& pos);
    void WCtoVC(Vector2& pos);

    void SetObject(GameObject* obj) { m_Object = obj; }

    void SetCornerLeft(Vector2 value) { m_cornerLeft = value; }
    void SetCornerRight(Vector2 value) { m_cornerRight = value; }

};

