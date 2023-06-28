#pragma once
#include "framework.h"

class AnimClip
{
private:
    struct Frame
    {
        wstring imageFile;
        Vector2 m_offset = Vector2(0.f, 0.f);
        Vector2 m_offsetSize = Vector2(0.f, 0.f);
        float m_time = 0.f; // 동작 시간
    };

    vector<Frame*> m_frames;

    const void* ptr = nullptr; // 뭐든 다 받을 수 있는 void 포인터

    //const void* m_address = nullptr;

    class Sprite* m_sprite = nullptr; // 주소형
    UINT m_curFrame = 0; // 현재 프레임 위치
    float m_playTime = 0.f; // 시간을 담아놓는 버퍼

    bool m_play = true; // Attack이 끝나면 false


public:
    enum STATE
    {
        LOOP = 0, // idle 등
        ONCE,     // Attack 등 -> 첫 번째 프레임으로 돌아감
        END,      // 마지막 프레임에 멈춰져 있게

    };

    AnimClip(STATE eState = STATE::LOOP);
    ~AnimClip();

    void Update();
    void Render();

    void AddFrame(class Sprite* _sprite, wstring img, float startX, float startY, float EndX, float EndY, float time);
    void AddFrame(wstring img, float startX, float startY, float EndX, float EndY, float time);

    void SetPlay()
    {
        m_curFrame = 0;
        m_play = true;
        m_playTime = 0.f;
    }

    void SetStop()
    {
        m_play = false;
    }

    bool IsPlay() { return m_play; }

private:
    STATE m_state = STATE::LOOP;
};

