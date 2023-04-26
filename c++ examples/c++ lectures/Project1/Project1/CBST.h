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

    bool isLeaf() // 단말노드인지 확인(자식 없는지)
    {
        if (arrNode[(int)NODE_TYPE::LCHILD] == nullptr && arrNode[(int)NODE_TYPE::RCHILD] == nullptr)
            return true;

        return false;
    }

    bool isFull() // 자식이 두 개인지
    {
        if (arrNode[(int)NODE_TYPE::LCHILD] && arrNode[(int)NODE_TYPE::RCHILD])
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
    iterator erase(const iterator& _iter);
private:
    tBSTNode<T1, T2>* DeleteNode(tBSTNode<T1, T2>* targetNode);

public:
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

        friend class CBST<T1, T2>;
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
            pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD]; // 갱신
        }
    }
    else // 오른쪽 자식이 없음
    {
        pSuccessor = _pNode;
        while(true)
        {
            if (pSuccessor->isRoot()) return nullptr; // 루트 노드면 null포인터 반환 == 마지막 노드였다

            if (pSuccessor->isLeftChild()) // 부모가 있고 내가 왼쪽 자식임
            {
                pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT]; // 중위후속자는 부모
                break;
            }
            else // 내가 오른쪽 자식임
            {
                pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
            }
        }
    }
    return pSuccessor;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPreSuccessor(tBSTNode<T1, T2>* _pNode) 
{
    tBSTNode<T1, T2>* pSuccessor = nullptr;
    if (_pNode->arrNode[(int)NODE_TYPE::LCHILD] != nullptr) // 왼쪽 자식 보유
    {
        pSuccessor = _pNode->arrNode[(int)NODE_TYPE::LCHILD]; // 왼쪽 자식으로 감

        while (pSuccessor->arrNode[(int)NODE_TYPE::RCHILD]) // 오른쪽 자식이 없을 때까지
        {
            pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::RCHILD]; // 갱신
        }
    }
    else // 왼쪽 자식이 없음
    {
        pSuccessor = _pNode;
        while (true)
        {

            if (pSuccessor->isRoot()) return nullptr; // 루트 노드면 null포인터 반환 == 마지막 노드였다

            if (pSuccessor->isRightChild()) // 부모가 있고 내가 오른쪽 자식임
            {
                pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT]; // 중위선행자는 부모
                break;
            }
            else // 내가 왼쪽 자식임
            {
                pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
            }
        }
    }
    return pSuccessor;
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

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::erase(const iterator& _iter)
{
    assert(_iter.pBST == this); // 현재 트리를 가리키고 있으면 아무 일도 안 일어남

    tBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.pNode);

    return iterator(this, pSuccessor);
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(tBSTNode<T1, T2>* target)
{
    tBSTNode<T1, T2>* pSuccessor = nullptr;
    pSuccessor = GetInOrderSuccessor(target); //중위후속자 노드 찾아놓기

    if (target->isLeaf()) // 자식이 없는 경우
    {

        if (target == pRoot) // 삭제하려는 노드가 루트 노드
        {
            pRoot = nullptr;
        }
        else
        {
            if (target->isLeftChild()) // 부모노드로 접근하여 삭제될 자식노드를 가리키는 포인터를 널로 만든다
                target->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
            else
                target->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;
        }

        delete target;
        --count;

    }
    else if (target->isFull()) // 자식이 2개
    {
        // 삭제될 자리에 중위 선행자의 값을 복사시킨다
        // 원래 중위후속자가 들어있던 노드를 삭제할 것
        target->pair = pSuccessor->pair;
        
        DeleteNode(pSuccessor);
        
        pSuccessor = target;

    }
    else // 자식이 1개
    {

        NODE_TYPE childType = NODE_TYPE::LCHILD;
        if (target->arrNode[(int)NODE_TYPE::RCHILD])
            childType = NODE_TYPE::RCHILD;

        if (target == pRoot)
        {
            pRoot = target->arrNode[(int)childType]; // 삭제할 노드의 자식노드가 루트가 됨
            target->arrNode[(int)childType]->arrNode[(int)NODE_TYPE::PARENT] = nullptr;
        }
        else
        {
            // 부모노드로 접근하여 삭제될 자식노드(본인)가 왼쪽 자식인지 오른쪽 자식인지 확인 
            // 삭제될 본인이 왼쪽 자식이면 부모의 왼쪽 자식 자리에 나의 자식노드를 연결
            if (target->isLeftChild()) 
                target->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = target->arrNode[(int)childType];
            else
                target->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = target->arrNode[(int)childType];

            target->arrNode[(int)childType]->arrNode[(int)NODE_TYPE::PARENT] = target->arrNode[(int)NODE_TYPE::PARENT];
        }
        --count;
    }


    return pSuccessor;
}
