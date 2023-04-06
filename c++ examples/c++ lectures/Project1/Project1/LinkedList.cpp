#include "LinkedList.h"
#include <iostream>

void Init(LList *list)
{
    list->headNode = nullptr;
    list->count = 0;
}

void PushBack(LList *list, int data)
{
    tNode* newNode = (tNode*)malloc(sizeof(tNode));

    if(list->count == 0)
    {
        list->headNode = newNode;
    }
    else
    {
        tNode* tmp = list->headNode;

        for(int i = 0; i < list->count; i++)
        {
            if(tmp->nextNode == nullptr)
            {
                tmp->nextNode = newNode;
            }
            else
            {
                tmp = tmp->nextNode;
            }
        }
    }

    newNode->data = data;
    newNode->nextNode = nullptr;

    list->count++;
}

void ReleaseList(LList *list)
{
    tNode* curNode = list->headNode;

    for(int i = 0; i < list->count; i++)
    {
        tNode* target = curNode->nextNode;
        free(curNode);
        curNode = target;
    }

    free(list->headNode);
    list->count = 0;

}

void PushFront(LList *list, int data)
{
    tNode* newNode = (tNode*)malloc(sizeof(tNode));

    
    if(list->count == 0)
    {
        newNode->nextNode = nullptr;
    }
    else
    {
        newNode->nextNode = list->headNode;
    }
    
    newNode->data = data;

    list->headNode = newNode;
    list->count++;
}
