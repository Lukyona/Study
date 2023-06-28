#pragma once
// 상태 패턴
// IDLE, 왼쪽/오른쪽 화살표로 run

#define PI 3.141592f
#define VERTICAL PI/2.f         // 90도, sin 1, cos 0
#define LEFT_ANGLE PI/5.0 * 3.f // 약 108도
#define RIGHT_ANGLE PI/5.0 * 2.f // 약 72도

class MomoPlayer : public GameObject
{
private:
    class Animation* m_anim = nullptr;

    bool m_isGround = false;

    float m_angle = VERTICAL;
    float m_speedX = 8.0f;
    float m_speedY = 8.0f;
    float m_gravity = 0.f;

    void CreateAnim();
    void CreateClip(wstring img, int w, int h, int count, int loop, float time);

    void GroundCheck(Vector2& pos);

    bool IsJumping();
    bool IsFalling();
    bool IsMovingLeft();
    bool IsMovingRight();

    void PreUpdate(Vector2& _pos);

    bool LeftCornerCheck(Vector2& _pos);
    bool RightCornerCheck(Vector2& _pos);

    void WallCheck(Vector2& pos);
    void ZoneCheck(Vector2& pos);


public:
    MomoPlayer();
    ~MomoPlayer();

    virtual void Render() override;
    virtual void Update() override;
    virtual void PostRender() override;

    enum State
    {
        LEFT_IDLE = 0,
        RIGHT_IDLE,
        LEFT_MOVE,
        RIGHT_MOVE,
        LEFT_JUMP, 
        RIGHT_JUMP,
        LEFT_FALL,
        RIGHT_FALL,

        LEFT_ATTACK,
        RIGHT_ATTACK,
        ATTACK_CHARGE_L,
        ATTACK_CHARGE_R,
        LEFT_ATTACK_C,
        RIGHT_ATTACK_C,

    };

private:
    State m_state = State::LEFT_IDLE;

    void SetState(State stat);

};