#pragma once
#include <cassert>

enum class NODE_TYPE
{
    PARENT, // 0
    LCHILD, // 1
    RCHILD, // 2
    END,    // 3
};

template <typename T1, typename T2>
struct tPair
{
    T1 first;
    T2 second;
};

template <typename T1, typename T2>
tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
    return tPair<T1, T2>{_first, _second};
}

template <typename T1, typename T2>
struct tBSTNode
{
    tPair<T1, T2> pair;
    tBSTNode* arrNode[(int)NODE_TYPE::END]; //  = arrNode[3]

    /*tBSTNode* pParent;
    tBSTNode* pLeftChild;
    tBSTNode* pRightChild;*/

public:

    tBSTNode()
        : pair(), arrNode{}
    {}

    tBSTNode(const tPair<T1, T2>& _pair, tBSTNode* _parent, tBSTNode* _lChild, tBSTNode* _rChild)
        : pair(_pair), arrNode{ _parent, _lChild, _rChild }
    {}

    bool isRoot() // ��Ʈ ������� Ȯ��
    {
        if (arrNode[(int)NODE_TYPE::PARENT] == nullptr) return true;
        else return false;
    }

    bool isLeftChild()
    {
        if (this == arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD]) // ���� �θ��� ���� �ڽ����� Ȯ��
            return true;
        
        
        return false;
    }

    bool isRightChild()
    {
        if (this == arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD]) // ���� �θ��� ���� �ڽ����� Ȯ��
            return true;
        
        return false;
    }
};


template <typename T1, typename T2>
class CBST
{
    tBSTNode<T1, T2>* pRoot; // ��Ʈ ���
    int count;       // ������ ����

public:
    CBST()
        :pRoot(nullptr), count(0)
    {}


    bool insert(const tPair<T1, T2>& _pair);
    tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode);
    tBSTNode<T1, T2>* GetInOrderPreSuccessor(tBSTNode<T1, T2>* _pNode);

    class iterator;

    iterator begin();
    iterator end();
    iterator find(const T1& _find);

    class iterator
    {
    private:
        CBST<T1, T2>* pBST;

        tBSTNode<T1, T2>* pNode; // null�� ��� end iterator

    public:
        iterator()
            : pBST(nullptr), pNode(nullptr)
        {}

        iterator(CBST<T1, T2>* _pBST, tBSTNode<T1, T2>* _pNode)
            : pBST(_pBST), pNode(_pNode)
        {}

        bool operator == (const iterator& other)
        {
            if (pBST == other.pBST && pNode == other.pNode) return true;

            return false;
        }

        bool operator != (const iterator& other)
        {
            return !(*this == other);
        }

        const tPair<T1, T2>& operator *() //���۷��� ��ȯ
        {
            assert(pNode); // end iterator�� ��� = pNode�� null�̸� ���

            return pNode->pair;
        }

        const tPair<T1, T2>* operator->() // �ּҰ� ��ȯ
        {
            assert(pNode); // end iterator�� ��� = pNode�� null�̸� ���

            return &pNode->pair;
        }

        iterator& operator ++()
        {
            pNode = pBST->GetInOrderSuccessor(pNode); // �����ļ���
            return *this;
        }


    };
};

template <typename T1, typename T2>
bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
    tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);

    // ù��° �����Ͷ��
    if (pRoot == nullptr)
    {
        pRoot = pNewNode; 
    }
    else
    {
        tBSTNode<T1, T2>* pNode = pRoot; // �� ���
        NODE_TYPE node_type = NODE_TYPE::END;

        while (true)
        {
            if (pNode->pair.first < pNewNode->pair.first)
            {
                node_type = NODE_TYPE::RCHILD;
            }
            else if (pNode->pair.first > pNewNode->pair.first)
            {
                node_type = NODE_TYPE::LCHILD;

            }
            else // ���� ����
            {
                return false;
            }

            if (pNode->arrNode[(int)node_type] == nullptr) // �ڽ� ��尡 �������
            {
                pNode->arrNode[(int)node_type] = pNewNode;
                pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
                break;
            }
            else
            {
                pNode = pNode->arrNode[(int)node_type]; // �� ��� ����
            }
        }
    }
    ++count;

    return true;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode) //�����ļ��� ã��
{
    tBSTNode<T1, T2>* pSuccessor = nullptr;
    if (_pNode->arrNode[(int)NODE_TYPE::RCHILD] != nullptr) // ������ �ڽ� ����
    {
        pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD]; // ������ �ڽ����� ��

        while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD]) // ���� �ڽ��� ���� ������
        {
            pSuccessor = _pNode->arrNode[(int)NODE_TYPE::LCHILD]; // ����
        }
    }
    else // ������ �ڽ��� ����
    {
        while(true)
        {
            if (_pNode->isRoot()) return nullptr; // ��Ʈ ���� null������ ��ȯ == ������ ��忴��

            if (_pNode->isLeftChild()) // �θ� �ְ� ���� ���� �ڽ���
            {
                pSuccessor = _pNode->arrNode[(int)NODE_TYPE::PARENT]; // �����ļ��ڴ� �θ�
                break;
            }
            else // ���� ������ �ڽ���
            {
                pSuccessor = _pNode->arrNode[(int)NODE_TYPE::PARENT];
            }
        }
    }
    return pSuccessor;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPreSuccessor(tBSTNode<T1, T2>* _pNode) 
{
    return nullptr;
}

// ��ȯ Ÿ���� ���� Ŭ���� ���� �̳�Ŭ������ ��� ��ȯ�� �տ� typename�� �ٿ������
template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin() // ���� ���� ���(������ȸ�� �������� �Ѵ�)
{
    tBSTNode<T1, T2>* pNode = pRoot;

    while (pNode->arrNode[(int)NODE_TYPE::LCHILD])
    {
        pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
    }

    return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
    return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find) // inset()�� ����
{
    tBSTNode<T1, T2>* pNode = pRoot; // �� ���
    NODE_TYPE node_type = NODE_TYPE::END;

    while (true)
    {
        if (pNode->pair.first < _find)
        {
            node_type = NODE_TYPE::RCHILD;
        }
        else if (pNode->pair.first > _find)
        {
            node_type = NODE_TYPE::LCHILD;

        }
        else // ���� ����, Ž�� ����
        {
            break;
        }

        if (pNode->arrNode[(int)node_type] == nullptr) // Ž�� ����
        {
            pNode = nullptr;
            break;
        }
        else
        {
            pNode = pNode->arrNode[(int)node_type]; // �� ��� ����
        }
    }

    return iterator(this, pNode);
}
