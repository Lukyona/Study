#pragma once
#include "framework.h"

class Animation
{
private:
    vector<class AnimClip*> m_animClips;
    class Sprite* m_sprite = nullptr; // 1개만 생성

    int m_curClipNum; //현재 클립 넘버


public:
    Animation(wstring imgFile);
    ~Animation();

    void Update();
    void Render();

    void AddClip(class AnimClip* clip);

    void SetPosition(Vector2 pt) { m_sprite->SetPosition(pt); }
    void SetScale(Vector2 size) { m_sprite->SetScale(size); }

    Vector2 GetPosition() { return m_sprite->GetPosition(); }
    Vector2 GetScale() { return m_sprite->GetScale(); }


    void SetPlay(UINT playNum);
    bool IsPlay();

    class Sprite* GetSprite();
};

