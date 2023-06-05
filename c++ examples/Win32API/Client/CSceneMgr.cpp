#include "pch.h"
#include "CSceneMgr.h"

#include "CScene_Start.h"

CSceneMgr::CSceneMgr()
    : m_arrScenes{}, m_curScene(nullptr)
{
}

CSceneMgr::~CSceneMgr()
{
    // �� ���� ����
    for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
    {
        if (m_arrScenes[i] != nullptr)
            delete m_arrScenes[i];
    }
}

void CSceneMgr::init()
{
    // �� ����
    m_arrScenes[(UINT)SCENE_TYPE::START] = new CScene_Start;
    //m_arrScenes[(UINT)SCENE_TYPE::TOOL] = new CScene_Start;
    //m_arrScenes[(UINT)SCENE_TYPE::STAGE_01] = new CScene_Start;
    //m_arrScenes[(UINT)SCENE_TYPE::STAGE_02] = new CScene_Start;

    m_curScene = m_arrScenes[(UINT)SCENE_TYPE::START];

    
}
