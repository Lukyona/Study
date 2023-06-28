#pragma once
#define  TIMEMANAGER  GameTime::GetInstance()

class GameTime
{
public:
	static GameTime* GetInstance()
	{
		static GameTime singleTone;
		return &singleTone;
	}
public:
	void   Update();
	void   Update(float lockFPS);   // �����ð��� ���
	float  Delta() { return m_TimeElepased; }
	float  GetRunning() { return m_RunningTime; }
	float  GetFPS() { return m_FramePerSecond; }
	int    GetFrame() { return m_FrameCountPerSecond; }
private:
	std::chrono::system_clock::time_point old_time; // start�ð�
	float m_TimeElepased = 0.0f;      // Update�� ��� �ð�
	float m_FPStimeElepased = 0.0f;   // Frame
	float m_RunningTime = 0.0f;       // �� Running �ð�
	float m_FramePerSecond = 0.0f;    // 
	int   m_FrameCount = 0;
	int   m_FrameCountPerSecond = 0;   // �ʴ� frame Count

private:
	GameTime();
public:
	~GameTime();

};

