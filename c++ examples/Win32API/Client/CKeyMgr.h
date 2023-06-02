#pragma once

// 프레임 동기화
// 동일 프레임 내에서 같은 키에 대해 동일한 이벤트를 가져간다.

// 키 입력 이벤트 처리, tap/hold/away

enum class KEY_STATE
{
    NONE, // 이전 프레임에서도 안 눌렸고 지금도 안 눌린 상태
    TAP, // 막 누른 시점
    HOLD, // 누르고 있는
    AWAY, // 막 뗀 시점
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
    KEY_STATE state; // 키 상태
    bool prevPush; //이전 프레임에서 키가 눌렸는지
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

