#pragma once
class CTimeMgr
{
    SINGLE(CTimeMgr);
private:
    // FPS : Frame per second

    LARGE_INTEGER m_curCount;
    LARGE_INTEGER m_preCount;
    LARGE_INTEGER m_frequency;

    double m_DT; // ������ ���� �ð���, Delta Time
    UINT m_callCount; //�Լ� ȣ�� Ƚ�� üũ
    double m_acc; // 1�� üũ�� ���� ���� �ð�
    UINT m_fps; // �ʴ� ȣ�� Ƚ��

public:
    void init();
    void update();
    void render();

    double GetDT() { return m_DT; }
    float GetfDT() { return (float)m_DT; }
};

