#pragma once

class CScene;

class CSceneMgr
{
    SINGLE(CSceneMgr);

private:
    CScene* m_arrScenes[(UINT)SCENE_TYPE::END]; //��� �� ���
    CScene* m_curScene;                         // ���� ��


public:

    void init();
    void update();
    void render(HDC _dc);
    CScene* GetCurScene() { return m_curScene; }
};

