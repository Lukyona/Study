#pragma once
class CTimeMgr
{
    SINGLE(CTimeMgr);
private:
    // FPS : Frame per second

    LARGE_INTEGER m_curCount;
    LARGE_INTEGER m_preCount;
    LARGE_INTEGER m_frequency;

    double m_DT; // 프레임 간의 시간값, Delta Time
    UINT m_callCount; //함수 호출 횟수 체크
    double m_acc; // 1초 체크를 위한 누적 시간
    UINT m_fps; // 초당 호출 횟수

public:
    void init();
    void update();
    void render();

    double GetDT() { return m_DT; }
    float GetfDT() { return (float)m_DT; }
};

