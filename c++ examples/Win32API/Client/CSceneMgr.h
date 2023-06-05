#pragma once

class CScene;

class CSceneMgr
{
    SINGLE(CSceneMgr);

private:
    CScene* m_arrScenes[(UINT)SCENE_TYPE::END]; //¸ðµç ¾À ¸ñ·Ï
    CScene* m_curScene;                         // ÇöÀç ¾À


public:

    void init();
};

