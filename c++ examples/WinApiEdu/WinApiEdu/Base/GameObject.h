#pragma once
class GameObject
{
private:
    Vector2 m_position = Vector2( 0.f,0.f );
    Vector2 m_scale = Vector2( 1.f,1.f );

protected:
    Collider* m_collider = nullptr;


public:
    virtual void Render() = 0;
    virtual void Update() = 0;
    virtual void PostRender() {};
    
    void SetPosition(Vector2 pt) { m_position = pt; }
    void SetScale(Vector2 size) { m_scale = size; }

    Vector2 GetPosition() { return m_position; }
    Vector2 GetScale() { return m_scale; }

    Collider* GetCollider() { return m_collider; }
};

