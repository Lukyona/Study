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
    HWND m_hWnd;
    POINT m_ptResolution;

public:
   int init(HWND _hwnd, POINT _ptRes);

   void progress();

private:
    CCore();
    ~CCore();


};
