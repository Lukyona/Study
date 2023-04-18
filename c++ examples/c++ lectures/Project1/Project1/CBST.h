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

    bool isRoot() // 루트 노드인지 확인
    {
        if (arrNode[(int)NODE_TYPE::PARENT] == nullptr) return true;
        else return false;
    }

    bool isLeftChild()
    {
        if (this == arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD]) // 내가 부모의 왼쪽 자식인지 확인
            return true;
        
        
        return false;
    }

    bool isRightChild()
    {
        if (this == arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD]) // 내가 부모의 왼쪽 자식인지 확인
            return true;
        
        return false;
    }
};


template <typename T1, typename T2>
class CBST
{
    tBSTNode<T1, T2>* pRoot; // 루트 노드
    int count;       // 데이터 개수

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

        tBSTNode<T1, T2>* pNode; // null인 경우 end iterator

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

        const tPair<T1, T2>& operator *() //레퍼런스 반환
        {
            assert(pNode); // end iterator면 경고 = pNode가 null이면 경고

            return pNode->pair;
        }

        const tPair<T1, T2>* operator->() // 주소값 반환
        {
            assert(pNode); // end iterator면 경고 = pNode가 null이면 경고

            return &pNode->pair;
        }

        iterator& operator ++()
        {
            pNode = pBST->GetInOrderSuccessor(pNode); // 중위후속자
            return *this;
        }


    };
};

template <typename T1, typename T2>
bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
    tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);

    // 첫번째 데이터라면
    if (pRoot == nullptr)
    {
        pRoot = pNewNode; 
    }
    else
    {
        tBSTNode<T1, T2>* pNode = pRoot; // 비교 대상
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
            else // 값이 동일
            {
                return false;
            }

            if (pNode->arrNode[(int)node_type] == nullptr) // 자식 노드가 비었으면
            {
                pNode->arrNode[(int)node_type] = pNewNode;
                pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
                break;
            }
            else
            {
                pNode = pNode->arrNode[(int)node_type]; // 비교 대상 변경
            }
        }
    }
    ++count;

    return true;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode) //중위후속자 찾기
{
    tBSTNode<T1, T2>* pSuccessor = nullptr;
    if (_pNode->arrNode[(int)NODE_TYPE::RCHILD] != nullptr) // 오른쪽 자식 보유
    {
        pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD]; // 오른쪽 자식으로 감

        while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD]) // 왼쪽 자식이 없을 때까지
        {
            pSuccessor = _pNode->arrNode[(int)NODE_TYPE::LCHILD]; // 갱신
        }
    }
    else // 오른쪽 자식이 없음
    {
        while(true)
        {
            if (_pNode->isRoot()) return nullptr; // 루트 노드면 null포인터 반환 == 마지막 노드였다

            if (_pNode->isLeftChild()) // 부모가 있고 내가 왼쪽 자식임
            {
                pSuccessor = _pNode->arrNode[(int)NODE_TYPE::PARENT]; // 중위후속자는 부모
                break;
            }
            else // 내가 오른쪽 자식임
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

// 반환 타입이 본인 클래스 내의 이너클래스일 경우 반환형 앞에 typename을 붙여줘야함
template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin() // 가장 왼쪽 노드(중위순회를 기준으로 한다)
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
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find) // inset()와 유사
{
    tBSTNode<T1, T2>* pNode = pRoot; // 비교 대상
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
        else // 값이 동일, 탐색 성공
        {
            break;
        }

        if (pNode->arrNode[(int)node_type] == nullptr) // 탐색 실패
        {
            pNode = nullptr;
            break;
        }
        else
        {
            pNode = pNode->arrNode[(int)node_type]; // 비교 대상 변경
        }
    }

    return iterator(this, pNode);
}
