#pragma once

typedef struct _tagArr
{
    int* pInt;
    int maxCount;
    int count;

}tArr;

void InitArr(tArr* _pArr);

void ReleaseArr(tArr* _pArr);

void PushBack(tArr* _pArr, int val);

void Reallocate(tArr* _pArr);

void BubbleSort(tArr* _pArr);