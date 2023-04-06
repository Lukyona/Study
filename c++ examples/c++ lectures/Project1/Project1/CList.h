#pragma once

template<typename T>
struct tListNode
{
    T data;
    tListNode* pPrev; // 본인 내부이기 때문에 안 써줘도 알아서 이해함
    tListNode<T>* pNext; //이렇게 T를 써줘도 되고

    tListNode() //기본 생성자 (여기서 정의
        :data(), pPrev(nullptr), pNext(nullptr)
    {

    }

    tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext) // 매개변수가 있는 생성자
        : data(_data), pPrev(_pPrev), pNext(_pNext)
    {

    }
};

template<typename T>
class CList
{
private:
    tListNode<T>* pHead;
    tListNode<T>* pTail;
    int count;

public:
    CList();
    ~CList();
    void PushBack(const T& data);
    void PushFront(const T& data);

    class iterator;
    iterator begin();
    iterator end();
    iterator erase(iterator& iter);
    iterator insert(const iterator& _iter, const T& data);

    class iterator
    {
    private:
        CList<T>* pList;
        tListNode<T>* pNode;
        bool isValid;

    public:
        iterator()
            :pList(nullptr), pNode(nullptr), isValid(false)
        {

        }

        iterator(CList<T>* _list, tListNode<T>* _node)
            :pList(_list), pNode(_node), isValid(false)
        {
            if (_list != nullptr && _node != nullptr) isValid = true;
        }

        ~iterator()
        {

        }

        T& operator * ()
        {
            return pNode->data;
        }

        bool operator == (const iterator& otheriter)
        {
            if (pList == otheriter.pList && pNode == otheriter.pNode) return true;

            return false;
        }

        bool operator != (const iterator& otheriter)
        {
            return !(*this == otheriter);
        }

        // 전위
        iterator& operator ++ ()
        {
            // end iterator인 경우 or 유효하지 않을 때
            if (pNode == nullptr || !isValid)
            {
                assert(nullptr);
            }

            pNode = pNode->pNext;

            return *this;
        }

        // 후위
        iterator operator ++ (int)
        {
            iterator iter(*this);

            ++(*this);

            return iter;
        }

        // 전위
        iterator& operator -- ()
        {
            if (pNode == nullptr || !isValid)
            {
                assert(nullptr);
            }

            pNode = pNode->pPrev;

            return *this;

        }

        // 후위
        iterator operator -- (int)
        {
            iterator iter(*this);

            --(*this);

            return iter;
        }



        friend class CList;
    };

};

template<typename T>
CList<T>::CList()
    : pHead(nullptr), pTail(nullptr), count(0)
{

}

template<typename T>
CList<T>::~CList() // 메모리 해제
{
    tListNode<T>* pDelNode = pHead;

    while (pDelNode)
    {
        tListNode<T>* pDelNext = pDelNode->pNext;
        free(pDelNode);
        pDelNode = pDelNext;
    }
}

template<typename T>
void CList<T>::PushBack(const T& data)
{
    tListNode<T>* pNewNode = new tListNode<T>(data, nullptr, nullptr);

    if (pHead == nullptr) //리스트에 기존 노드가 없음
    {
        pHead = pNewNode;
    }
    else // 기존 노드 존재
    {
        pTail->pNext = pNewNode;
        pNewNode->pPrev = pTail;
    }

    pTail = pNewNode;

    count++;
}

template<typename T>
void CList<T>::PushFront(const T& data)
{
    tListNode<T>* pNewNode = new tListNode<T>(data, nullptr, nullptr);

    if (pHead == nullptr) //리스트에 기존 노드가 없음
    {
        pTail = pNewNode;

    }
    else // 기존 노드 존재
    {
        pHead->pPrev = pNewNode;
        pNewNode->pNext = pHead;
    }

    pHead = pNewNode;

    count++;
}


// inline 함수는 컴파일러가 함수를 호출하지 않고 호출되는 곳에 코드를 붙여넣음. 함수 호출 비용 아낌
// 무조건은 아니고 컴파일러가 알아서 판단함. 함수 호출이 많은데 코드가 긴 경우 인라인이면 비효율적
// 함수 안에 코드가 상당히 짧지만 호출은 많음. 이 경우에 인라인으로 하면 좋음
// 템플릿 클래스가 아닌 일반 클래스는 헤더에 함수(set, gee 등 간단한 것)를 구현한다는 것은 인라인 처리하겠다는 의미

template<typename T>
inline typename CList<T>::iterator CList<T>::begin()
{
    return iterator(this, pHead);
}

template<typename T>
inline typename CList<T>::iterator CList<T>::end()
{
    return iterator(this, nullptr);
}

template<typename T>
inline CList<T>::iterator CList<T>::erase(iterator& iter)
{
    if (count == 1 || iter == end()) assert(nullptr);

    --count;

    if (iter.pNode == pHead)
    {
        iter.pNode->pNext->pPrev = nullptr;
        pHead = iter.pNode->pNext;

        return iterator(this, pHead);

    }
    else if(iter.pNode == pTail)
    {
        iter.pNode->pPrev->pNext = nullptr;
        pTail = iter.pNode->pPrev;

        return iterator(this, pTail);

    }
    else
    {
        iter.pNode->pPrev->pNext = iter.pNode->pNext;
        iter.pNode->pNext->pPrev = iter.pNode->pPrev;

        return iterator(this, iter.pNode->pPrev);

    }
}

template<typename T>
inline CList<T>::iterator CList<T>::insert(const iterator& iter,const T& _data)
{
    if (iter == end()) assert(nullptr);

    // 추가될 데이터를 저장할 노드 생성
    tListNode<T>* newNode = new tListNode<T>(_data, nullptr, nullptr);

    // iter가 가리키는 노드가 헤드일 때
    if (iter.pNode == pHead)
    {
        pHead = newNode;
    }
    else
    {
        iter.pNode->pPrev->pNext = newNode;
        newNode->pPrev = iter.pNode->pPrev;
    }


    newNode->pNext = iter.pNode;
    iter.pNode->pPrev = newNode;

    ++count;

    return iterator(this, newNode);
}
