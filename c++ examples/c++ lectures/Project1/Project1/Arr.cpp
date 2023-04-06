#include "Arr.h"
#include <iostream>


void InitArr(tArr *_pArr)
{
    _pArr->pInt = (int*)malloc(sizeof(int) * 2);
    _pArr->maxCount = 2;
    _pArr->count = 0;
}

void ReleaseArr(tArr* _pArr)
{
    free(_pArr->pInt);
    _pArr->count = 0;
    _pArr->maxCount = 0;
}

void PushBack(tArr *_pArr, int val)
{
    if(_pArr->count >= _pArr->maxCount)
    {
        Reallocate(_pArr);
    }

    _pArr->pInt[_pArr->count] = val;
    _pArr->count++;

    BubbleSort(_pArr);
}

void Reallocate(tArr *_pArr)
{
    int* temp = (int*)malloc(sizeof(int) * (_pArr->maxCount * 2));

    for(int i = 0; i < _pArr->count; i++)
    {
        temp[i] = _pArr->pInt[i];
    }
    
    free(_pArr->pInt);

    _pArr->pInt = temp;
    _pArr->maxCount *= 2;
}

void BubbleSort(tArr *_pArr)
{
    for(int i = 0; i < _pArr->count - 1; i++)
    {
        for(int j = 0; j < _pArr->count - 1; j++)
        {
            if(_pArr->pInt[j] > _pArr->pInt[j+1])
            {
                int tmp = _pArr->pInt[j];
                _pArr->pInt[j] = _pArr->pInt[j+1];
                _pArr->pInt[j+1] = tmp;
            }
        } 
    }
}
