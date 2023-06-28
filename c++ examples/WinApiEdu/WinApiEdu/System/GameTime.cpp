#include "framework.h"
#include "GameTime.h"

GameTime::GameTime()
{
	old_time = std::chrono::system_clock::now();  //����ð�
}

GameTime::~GameTime()
{
}

void GameTime::Update()
{
	std::chrono::duration<double> sec;

	// ����ð��� Old�ð����� duration ���ϱ�
	sec = std::chrono::system_clock::now() - old_time;
	// �� Update�� �ð� --> Delta()���ؼ� �� Object���� �ð� ����
	m_TimeElepased = (float)sec.count();         
	// ���� �ð��� old_time�� ����
	old_time = std::chrono::system_clock::now(); // start
	m_FrameCount++;
	
	// Game���� ���۽ð��� ����
	m_RunningTime = m_RunningTime + m_TimeElepased;
	
	m_FPStimeElepased = m_FPStimeElepased + m_TimeElepased;

	if (m_FPStimeElepased > 1.0f)
	{
		m_FramePerSecond = m_FPStimeElepased / m_FrameCount;
		m_FrameCountPerSecond = m_FrameCount;
		m_FPStimeElepased = 0.0f;
		m_FrameCount = 0;
	}
	
//	printf("%f  �ʴ� Frame��:%d\n", m_TimeElepased, m_FrameCountPerSecond);
	

}

void GameTime::Update(float lockFPS)
{

	std::chrono::duration<double> sec;

	// ����ð��� Old�ð����� duration ���ϱ�
	sec = std::chrono::system_clock::now() - old_time;
	// �� Update�� �ð� --> Delta()���ؼ� �� Object���� �ð� ����
	m_TimeElepased = (float)sec.count();
	
	while (m_TimeElepased < 1.0f / lockFPS)
	{
		sec = std::chrono::system_clock::now() - old_time;
		m_TimeElepased = (float)sec.count();
	}
	
	
	// ���� �ð��� old_time�� ����

	old_time = std::chrono::system_clock::now(); // start
	m_FrameCount++;

	// Game���� ���۽ð��� ����
	m_RunningTime = m_RunningTime + m_TimeElepased;

	m_FPStimeElepased = m_FPStimeElepased + m_TimeElepased;

	if (m_FPStimeElepased > 1.0f)
	{
		m_FramePerSecond = m_FPStimeElepased / m_FrameCount;
		m_FrameCountPerSecond = m_FrameCount;
		m_FPStimeElepased = 0.0f;
		m_FrameCount = 0;
	}
}

