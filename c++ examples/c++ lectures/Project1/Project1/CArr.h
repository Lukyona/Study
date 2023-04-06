#pragma once
#include <assert.h>

template <typename T> // 클래스 템플릿, 이 경우 함수 정의도 모두 같은 헤더파일에 있어야함
class CArr
{
private:
    T* pData;
    int count;
    int maxCount;

public:
    CArr(); // 참고로 만약 복사 생성자 하나만을 정의했다면 기본 생성자 안 만들어준다고 함.
    ~CArr(); // 생성자가 하나라도 존재하면 아예 안 만들어준답니다ㅜ

    void PushBack(const T& data);
    void Resize(int dataCount);

    T& operator[] (int idx);

    class iterator; // 전방선언
    iterator begin();
    iterator end();
    iterator erase(iterator& iter);

    void clear() { count = 0; };
   

    class iterator // inner class, CArr의 private 멤버들에 접근 가능
    {
    private: //원래라면 CArr은 여기에 접근 못 함, friend 선언으로 접근 가능
        CArr* pArr; // iterator가 가리킬 데이터를 관리하는 가변 배열
        T* piData; // 데이터들 시작 주소
        int idx; // 가리키는 데이터 인덱스
        bool isValid; // iterator 유효성 체크

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

        friend class CArr; // 이제 CArr은 iterator의 private멤버에 접근 가능

        T& operator * ()
        {
            //재할당이 한 번 이상 일어남 or end iterator일 경우 or iterator가 유효하지 않을 경우
            if (piData != pArr->pData || idx == -1 || !isValid) 
                assert(nullptr);

            return piData[idx];
        }

        //전위
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

        //후위
        iterator operator ++ (int) // 매개변수에 int를 넣어줌으로써 이것을 후위 연산자로 인식
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
    pData = new T[2]; // new 키워드로 동적할당, 초기 크기 2

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
T& CArr<T>::operator[](int idx) //연산자 오버로딩, 배열 요소(정수)를 반환
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
    // iterator가 다른 가변 배열 요소를 가리키는 경우 or end iterator인 경우 or 가리키고 있는 인덱스가 현재 개수와 같거나 클 때
    if (this != iter.pArr || iter == end() || iter.idx >= count) 
    {
        assert(nullptr);
    }


    // 가리키는 데이터 제거 (= 덮어씌우기)
    int loopCount = (count - 1) - iter.idx;

    for (int i = 0; i < loopCount; ++i)
    {
        pData[i + iter.idx] = pData[i + iter.idx + 1];
    }

    iter.isValid = false; // 삭제한 곳을 가리키고 있기에 유효하지 않음

    // 현재 요소 개수 감소
    --count;

    if (count == iter.idx) --iter.idx; //마지막 요소를 제거하게 되면 카운트와 인덱스가 같아지기 때문에 에러이므로 인덱스 감소

    return iterator(this, pData, iter.idx); // 삭제된 요소 다음 요소를 가리키는 (유효한)iterator 반환
}