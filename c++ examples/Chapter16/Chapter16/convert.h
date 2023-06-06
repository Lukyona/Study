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
    oss << data; // data를 출력 문자열 스트림에 삽입
    return oss.str();ㅡㅡ
}

template<typename T>
T toData(string strg)
{
    T data;
    istringstream iss(strg);
    iss >> data; // 입력 문자열 스트림에서 추출하여 data에 저장
    return data;
}

#endif