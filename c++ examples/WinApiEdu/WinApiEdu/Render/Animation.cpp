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
    //m_animClips.clear() // ���� �ִ� �͵��� �̰ɷ� �� �� ������
    m_animClips.erase(m_animClips.begin(), m_animClips.end());


   /* if(m_sprite)
        delete m_sprite;

    m_sprite = nullptr;*/
    //SAFE_DELETE(m_sprite) // �������� �� ��... ��ü ��..
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


    // �÷��̾�, �� ��� ������Ʈ �� ������ SetPlay() ȣ��
    // ���ǹ����� ���Ƶα�
    if ((clip->IsPlay()) && (playNum == m_curClipNum)) return;
    
    m_curClipNum = playNum;
    clip = m_animClips[m_curClipNum];

    clip->SetPlay();
}

// ���� Ŭ�� �ǽ� �� �������� �˰� ���� ��
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
