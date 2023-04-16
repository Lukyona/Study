#pragma once


template <typename T1, typename T2>
struct tPair
{
    T1 first;
    T2 second;
};

template <typename T1, typename T2>
struct tBSTNode
{
    tPair<T1, T2> pair;
    tBSTNode* pParent;
    tBSTNode* pLeftChild;
    tBSTNode* pRightChild;
};


template <typename T1, typename T2>
class CBST
{
    tBSTNoder<T1, T2>* pRoot; // 루트 노드
    int count;       // 데이터 개수

public:
    CBST()
        :pRoot(nullptr), count(0)
    {

    }


    bool insert(const tPair<T1, T2>& _pair);

};

template <typename T1, typename T2>
bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
    tBSTNode* pNewNode = new tBSTNode<T1, T2>();

    pNewNode->pair = _pair;
    pNewNode->pParent = nullptr;
    pNewNode->pLeftChild = nullptr;
    pNewNode->pRightChild = nullptr;

    // 첫번째 데이터라면
    if (pRoot == nullptr)
    {
        pRoot = pNewNode; 
    }
    else
    {
        tBSTNode<T1, T2>* pNode = pRoot; // 비교 대상

        while (true)
        {
            if (pNode->pair.first < pNewNode->pair.first)
            {
                if (pNode->pRightChild == nullptr)
                {
                    pNode->pRightChild = pNewNode;
                    pNewNode->pParent = pNode;
                    break;
                }
                else
                {
                    pNode = pNode->pRightChild; // 비교 대상 변경
                }
            }
            else if (pNode->pair.first > pNewNode->pair.first)
            {
                if (pNode->pLeftChild == nullptr)
                {
                    pNode->pLeftChild = pNewNode;
                    pNewNode->pParent = pNode;
                    break;
                }
                else
                {
                    pNode = pNode->pLeftChild; // 비교 대상 변경
                }
            }
            else // 값이 같음
            {
                return false;
            }
        }

    }

    ++count;

}