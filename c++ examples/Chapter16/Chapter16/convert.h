#pragma once

#ifndef CONVERT_H
#define CONVERT_H
#include <iostream>
#include <string>
#include<sstream>
using namespace std;

template<typename T>
string toString(T data)
{
    ostringstream oss("");
    oss << data; // data�� ��� ���ڿ� ��Ʈ���� ����
    return oss.str();�Ѥ�
}

template<typename T>
T toData(string strg)
{
    T data;
    istringstream iss(strg);
    iss >> data; // �Է� ���ڿ� ��Ʈ������ �����Ͽ� data�� ����
    return data;
}

#endif