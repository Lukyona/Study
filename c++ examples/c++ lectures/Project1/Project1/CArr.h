#pragma once
#include <assert.h>

template <typename T> // Ŭ���� ���ø�, �� ��� �Լ� ���ǵ� ��� ���� ������Ͽ� �־����
class CArr
{
private:
    T* pData;
    int count;
    int maxCount;

public:
    CArr(); // ����� ���� ���� ������ �ϳ����� �����ߴٸ� �⺻ ������ �� ������شٰ� ��.
    ~CArr(); // �����ڰ� �ϳ��� �����ϸ� �ƿ� �� ������ش�ϴ٤�

    void PushBack(const T& data);
    void Resize(int dataCount);

    T& operator[] (int idx);

    class iterator; // ���漱��
    iterator begin();
    iterator end();
    iterator erase(iterator& iter);

    void clear() { count = 0; };
   

    class iterator // inner class, CArr�� private ����鿡 ���� ����
    {
    private: //������� CArr�� ���⿡ ���� �� ��, friend �������� ���� ����
        CArr* pArr; // iterator�� ����ų �����͸� �����ϴ� ���� �迭
        T* piData; // �����͵� ���� �ּ�
        int idx; // ����Ű�� ������ �ε���
        bool isValid; // iterator ��ȿ�� üũ

    public:
        iterator()
            : pArr(nullptr), piData(nullptr), idx(-1), isValid(false)
        {

        }

        iterator(CArr* arr, T* _pData, int _idx)
            : pArr(arr), piData(_pData), idx(_idx), isValid(false)
        {
            if (arr != nullptr && _idx >= 0) isValid = true;
        }

        ~iterator()
        {

        }

        friend class CArr; // ���� CArr�� iterator�� private����� ���� ����

        T& operator * ()
        {
            //���Ҵ��� �� �� �̻� �Ͼ or end iterator�� ��� or iterator�� ��ȿ���� ���� ���
            if (piData != pArr->pData || idx == -1 || !isValid) 
                assert(nullptr);

            return piData[idx];
        }

        //����
        iterator& operator ++ ()
        {            
            if (piData != pArr->pData || idx == -1) assert(nullptr); 

            if (idx == pArr->count - 1) idx = -1;
            else
            {
                ++idx;

            }
            return *this;
        }

        //����
        iterator operator ++ (int) // �Ű������� int�� �־������ν� �̰��� ���� �����ڷ� �ν�
        {
            iterator iter = *this;
            ++(*this);

            return iter;
        }

        iterator& operator -- ()
        {

            return *this;
        }

        bool operator == (const iterator& other)
        {
            if (this->idx == other.idx && this->piData == other.piData) return true;
            
            return false;
        }

        bool operator != (const iterator& other)
        {
            return !(*this == other);
        }

       

    };

    


};

template<typename T>
CArr<T>::CArr()
    : pData(nullptr), count(0), maxCount(2)
{
    pData = new T[2]; // new Ű����� �����Ҵ�, �ʱ� ũ�� 2

}

template<typename T>
CArr<T>::~CArr()
{
    delete[] pData;

}

template<typename T>
void CArr<T>::PushBack(const T& data)
{
    if (count >= maxCount)
    {
        Resize(maxCount * 2);
    }

    pData[count] = data;
    count++;

    // BubbleSort(this);
}

template<typename T>
void CArr<T>::Resize(int dataCount)
{
    if (maxCount >= dataCount)
    {
        assert(nullptr);
    }
    T* temp = new int[dataCount];

    for (int i = 0; i < count; i++)
    {
        temp[i] = pData[i];
    }

    delete[] pData;

    pData = temp;
    maxCount = dataCount;
}

template<typename T>
T& CArr<T>::operator[](int idx) //������ �����ε�, �迭 ���(����)�� ��ȯ
{
    return pData[idx];

}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
    if (count == 0) return end();

    return iterator(this, pData, 0);

}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
    return iterator(this, pData, -1);

}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& iter)
{
    // iterator�� �ٸ� ���� �迭 ��Ҹ� ����Ű�� ��� or end iterator�� ��� or ����Ű�� �ִ� �ε����� ���� ������ ���ų� Ŭ ��
    if (this != iter.pArr || iter == end() || iter.idx >= count) 
    {
        assert(nullptr);
    }


    // ����Ű�� ������ ���� (= ������)
    int loopCount = (count - 1) - iter.idx;

    for (int i = 0; i < loopCount; ++i)
    {
        pData[i + iter.idx] = pData[i + iter.idx + 1];
    }

    iter.isValid = false; // ������ ���� ����Ű�� �ֱ⿡ ��ȿ���� ����

    // ���� ��� ���� ����
    --count;

    if (count == iter.idx) --iter.idx; //������ ��Ҹ� �����ϰ� �Ǹ� ī��Ʈ�� �ε����� �������� ������ �����̹Ƿ� �ε��� ����

    return iterator(this, pData, iter.idx); // ������ ��� ���� ��Ҹ� ����Ű�� (��ȿ��)iterator ��ȯ
}