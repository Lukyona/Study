#include "AnimClip.h"

AnimClip::AnimClip(STATE eState)
{
    m_state = eState;
}

AnimClip::~AnimClip()
{
    for (int i = 0; i < m_frames.size(); ++i)
    {
        delete m_frames[i];
    }
    m_frames.erase(m_frames.begin(), m_frames.end());
}

void AnimClip::Update()
{
    Frame* frame = m_frames[m_curFrame];

    // 타임 체크 기준 m_play가 true일 때만
    // once : 한 번만 재생하고 m_play = false
    // loop : 항상 m_play = true
    if (m_play)
    {
        m_playTime += TIMEMANAGER->Delta();
        if (m_playTime >= frame->m_time)
        {
            ++m_curFrame;
            if (m_curFrame == m_frames.size())
            {
                switch (m_state)
                {
                    case STATE::LOOP:
                        m_curFrame = 0;
                        break;
                    case STATE::ONCE:
                        m_curFrame = 0;
                        --m_curFrame;
                        SetStop();
                        break;
                    case STATE::END:
                        --m_curFrame;
                        SetStop();
                        break;
                }
            }

            m_playTime = 0.f;

        }
    }

    frame = m_frames[m_curFrame];
    m_sprite->SetOffset(frame->m_offset);
    m_sprite->SetOffsetSize(frame->m_offsetSize);
    m_sprite->SetImage(frame->imageFile);
}

void AnimClip::Render()
{
    m_sprite->Render();

}

void AnimClip::AddFrame(Sprite* _sprite, wstring img, float startX, float startY, float endX, float endY, float time)
{
    m_sprite = _sprite;

    //m_address = _sprite;
   // ((Sprite*)m_address)->;

    Frame* pFrame = new Frame();

    pFrame->imageFile = img;
    pFrame->m_offset = Vector2(startX, startY);
    pFrame->m_offsetSize = Vector2(endX - startX, endY - startY);
    pFrame->m_time = time; 


    SRVMANAGER->CreateImage(img);

    m_frames.push_back(pFrame);
}

void AnimClip::AddFrame(wstring img, float startX, float startY, float EndX, float EndY, float time)
{
    Frame* pFrame = new Frame();

    pFrame->imageFile = img;
    pFrame->m_offset = Vector2(startX, startY);
    pFrame->m_offsetSize = Vector2(EndX - startX, EndY - startY);
    pFrame->m_time = time;

    SRVMANAGER->CreateImage(img);

    m_frames.push_back(pFrame);
}

