#pragma once

// ������ ����ȭ
// ���� ������ ������ ���� Ű�� ���� ������ �̺�Ʈ�� ��������.

// Ű �Է� �̺�Ʈ ó��, tap/hold/away

enum class KEY_STATE
{
    NONE, // ���� �����ӿ����� �� ���Ȱ� ���ݵ� �� ���� ����
    TAP, // �� ���� ����
    HOLD, // ������ �ִ�
    AWAY, // �� �� ����
};

enum class KEY
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    Q,
    W,
    E,
    R,
    T,
    Y,
    U,
    I,
    O,
    P,
    A,
    S,
    D,
    F,
    G,
    Z,
    X,
    C,
    V,
    B,
    
    ALT,
    CTRL,
    LSHIFT,
    SPACE,
    ENTER,
    ESC,


    LAST,
};

struct KeyInfo
{
    KEY_STATE state; // Ű ����
    bool prevPush; //���� �����ӿ��� Ű�� ���ȴ���
};

class CKeyMgr
{
    SINGLE(CKeyMgr);
private:
    vector<KeyInfo> m_vecKey;


public:
    void init();
    void update();

    KEY_STATE GetKeyState(KEY _key)
    {
        return m_vecKey[(int)_key].state;
    }
};

