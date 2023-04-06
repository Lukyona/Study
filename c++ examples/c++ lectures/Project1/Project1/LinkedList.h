#pragma once

typedef struct _tNode
{
    int data;
    struct _tNode* nextNode;

}tNode;

typedef struct LinkedList
{
    tNode* headNode;
    int count;
}LList;

void Init(LList* list);

void PushBack(LList* list, int data);

void ReleaseList(LList* list);

void PushFront(LList* list, int data);
