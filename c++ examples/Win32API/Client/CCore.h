#pragma once

// �̱��� ����, ��ü�� ������ 1���� ����
// ���� ��𼭵� ���� ���� ����
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
//        //���� ���� �ʱ�ȭ�� �� �� ���� �����
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
    HWND m_hWnd;          // ���� ������ �ڵ�
    POINT m_ptResolution; // ���� ������ �ػ�
    HDC m_hDC;            // ���� �����쿡 Draw�� DC

    HBITMAP m_hBit;
    HDC m_memDC;

public:
   int init(HWND _hwnd, POINT _ptRes);

   void progress();

   HWND GetMainHwnd() { return m_hWnd; }
   HDC GetMainDC() { return m_hDC; }
   POINT GetResolution() { return m_ptResolution; }
private:
    void update();
    void render();

};
