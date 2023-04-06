#pragma once

template<typename T>
struct tListNode
{
    T data;
    tListNode* pPrev; // ���� �����̱� ������ �� ���൵ �˾Ƽ� ������
    tListNode<T>* pNext; //�̷��� T�� ���൵ �ǰ�

    tListNode() //�⺻ ������ (���⼭ ����
        :data(), pPrev(nullptr), pNext(nullptr)
    {

    }

    tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext) // �Ű������� �ִ� ������
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

        // ����
        iterator& operator ++ ()
        {
            // end iterator�� ��� or ��ȿ���� ���� ��
            if (pNode == nullptr || !isValid)
            {
                assert(nullptr);
            }

            pNode = pNode->pNext;

            return *this;
        }

        // ����
        iterator operator ++ (int)
        {
            iterator iter(*this);

            ++(*this);

            return iter;
        }

        // ����
        iterator& operator -- ()
        {
            if (pNode == nullptr || !isValid)
            {
                assert(nullptr);
            }

            pNode = pNode->pPrev;

            return *this;

        }

        // ����
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
CList<T>::~CList() // �޸� ����
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

    if (pHead == nullptr) //����Ʈ�� ���� ��尡 ����
    {
        pHead = pNewNode;
    }
    else // ���� ��� ����
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

    if (pHead == nullptr) //����Ʈ�� ���� ��尡 ����
    {
        pTail = pNewNode;

    }
    else // ���� ��� ����
    {
        pHead->pPrev = pNewNode;
        pNewNode->pNext = pHead;
    }

    pHead = pNewNode;

    count++;
}


// inline �Լ��� �����Ϸ��� �Լ��� ȣ������ �ʰ� ȣ��Ǵ� ���� �ڵ带 �ٿ�����. �Լ� ȣ�� ��� �Ƴ�
// �������� �ƴϰ� �����Ϸ��� �˾Ƽ� �Ǵ���. �Լ� ȣ���� ������ �ڵ尡 �� ��� �ζ����̸� ��ȿ����
// �Լ� �ȿ� �ڵ尡 ����� ª���� ȣ���� ����. �� ��쿡 �ζ������� �ϸ� ����
// ���ø� Ŭ������ �ƴ� �Ϲ� Ŭ������ ����� �Լ�(set, gee �� ������ ��)�� �����Ѵٴ� ���� �ζ��� ó���ϰڴٴ� �ǹ�

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

    // �߰��� �����͸� ������ ��� ����
    tListNode<T>* newNode = new tListNode<T>(_data, nullptr, nullptr);

    // iter�� ����Ű�� ��尡 ����� ��
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
