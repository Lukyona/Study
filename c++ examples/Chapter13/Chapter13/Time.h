#pragma once
class Time
{
private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    bool isPM; // 0 - morning, 1 - afternoon
public:
    Time();
    Time(int h, int m, int s, int ampm);
    
    Time& operator ++();
    Time& operator +=(const int sec);
    int operator ()();

    void normalize();
};

