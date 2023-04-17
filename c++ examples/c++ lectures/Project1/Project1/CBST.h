#pragma once

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
