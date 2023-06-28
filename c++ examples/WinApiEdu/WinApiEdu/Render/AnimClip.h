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
        float m_time = 0.f; // ���� �ð�
    };

    vector<Frame*> m_frames;

    const void* ptr = nullptr; // ���� �� ���� �� �ִ� void ������

    //const void* m_address = nullptr;

    class Sprite* m_sprite = nullptr; // �ּ���
    UINT m_curFrame = 0; // ���� ������ ��ġ
    float m_playTime = 0.f; // �ð��� ��Ƴ��� ����

    bool m_play = true; // Attack�� ������ false


public:
    enum STATE
    {
        LOOP = 0, // idle ��
        ONCE,     // Attack �� -> ù ��° ���������� ���ư�
        END,      // ������ �����ӿ� ������ �ְ�

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

