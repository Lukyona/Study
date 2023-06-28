#include "framework.h"
#include "Animation.h"
#include "Render/Sprite.h"
#include "Render/AnimClip.h"

Animation::Animation(wstring imgFile)
    : m_curClipNum(0)
{
    m_sprite = new Sprite(imgFile);
}

Animation::~Animation()
{
    for (int i = 0; i < m_animClips.size(); ++i)
    {
        delete m_animClips[i];
    }
    //m_animClips.clear() // 힙에 있는 것들은 이걸로 잘 안 지워짐
    m_animClips.erase(m_animClips.begin(), m_animClips.end());


   /* if(m_sprite)
        delete m_sprite;

    m_sprite = nullptr;*/
    //SAFE_DELETE(m_sprite) // 오류나서 못 씀... 대체 왜..
}

void Animation::Update()
{
    if (m_animClips.size() == 0) return;

    AnimClip* pClip = m_animClips[m_curClipNum];
    pClip->Update();
}


void Animation::Render()
{
    AnimClip* pClip = m_animClips[m_curClipNum];
    pClip->Render();
}

void Animation::AddClip(AnimClip* clip)
{
    m_animClips.push_back(clip);
}

void Animation::SetPlay(UINT playNum)
{
    AnimClip* clip = nullptr;
    if (m_animClips.size() == 0) return;
    if (playNum >= m_animClips.size()) return;

    clip = m_animClips[m_curClipNum];


    // 플레이어, 적 등에서 업데이트 시 무조건 SetPlay() 호출
    // 조건문으로 막아두기
    if ((clip->IsPlay()) && (playNum == m_curClipNum)) return;
    
    m_curClipNum = playNum;
    clip = m_animClips[m_curClipNum];

    clip->SetPlay();
}

// 공격 클립 실시 후 끝났는지 알고 싶을 때
bool Animation::IsPlay()
{
    AnimClip* clip = nullptr;
    if (m_animClips.size() == 0) return false;

    clip = m_animClips[m_curClipNum];

    return clip->IsPlay();
}

Sprite* Animation::GetSprite()
{
    return m_sprite;
}
