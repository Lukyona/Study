#pragma once
class CTimeMgr
{
    SINGLE(CTimeMgr);
private:
    // FPS : Frame per second

    LARGE_INTEGER m_curCount;
    LARGE_INTEGER m_Frequency;
public:
    void init();
};

