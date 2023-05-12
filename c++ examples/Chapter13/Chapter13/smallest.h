#pragma once
#ifndef SMALLESET_H
#define SMALLESET_H
#include <iostream>
using namespace std;


class Smallest
{
private:
    int current;
public:
    Smallest();
    int operator()(int next);
};

#endif