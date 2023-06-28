#pragma once
class MomoEffect : public GameObject
{
private:
    class Animation* m_anim = nullptr;

    function<void()> m_EndCallback = nullptr;

public:
    enum State
    {
        LEFT_ATTACK = 0,
        RIGHT_ATTACK,
        EFFECT_CHARGE,
        LEFT_ATTACK_CHARGE,
        RIGHT_ATTACK_CHARGE,
    };

    MomoEffect();
    ~MomoEffect();

    virtual void Render() override;
    virtual void Update() override;
    virtual void PostRender() {};
    virtual void PreRender() {};


};

