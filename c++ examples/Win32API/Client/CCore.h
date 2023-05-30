#pragma once

// 싱글톤 패턴, 객체의 생성을 1개로 제한
// 언제 어디서든 쉽게 접근 가능
//class CCore
//{
//private:
//    CCore();
//    ~CCore();
//    static CCore* pInst;
//
//public:
//    static CCore* GetInstance()
//    {
//        //정적 변수 초기화는 단 한 번만 실행됨
//        if (pInst == nullptr)
//            pInst = new CCore;
//
//        return pInst;
//    }
//
//    static void Release()
//    {
//        if (pInst != nullptr)
//        {
//            delete pInst;
//            pInst = nullptr;
//        }
//    }
//
//};
class CCore
{
    SINGLE(CCore);

private:
    HWND m_hWnd;          // 메인 윈도우 핸들
    POINT m_ptResolution; // 메인 윈도우 해상도
    HDC m_hDC;            // 메인 윈도우에 Draw할 DC

public:
   int init(HWND _hwnd, POINT _ptRes);

   void progress();

private:
    CCore();
    ~CCore();

    void update();
    void render();

};
