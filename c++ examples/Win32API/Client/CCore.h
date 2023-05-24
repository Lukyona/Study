#pragma once

// �̱��� ����, ��ü�� ������ 1���� ����
// ���� ��𼭵� ���� ���� ����
class CCore
{
private:
    CCore();
    ~CCore();
    static CCore* pInst;

public:
    static CCore* GetInstance()
    {
        //���� ���� �ʱ�ȭ�� �� �� ���� �����
        if (pInst == nullptr)
            pInst = new CCore;

        return pInst;
    }

    static void Release()
    {
        if (pInst != nullptr)
        {
            delete pInst;
            pInst = nullptr;
        }
    }

};

