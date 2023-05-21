#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;

class HExcept : public out_of_range
{
public :
    HExcept();
};

class MExcept : public out_of_range
{
public:
    MExcept();
};

class SExcept : public out_of_range
{
public:
    SExcept();
};

HExcept::HExcept()
    :out_of_range("시간 범위를 벗어났습니다.")
{
}

MExcept::MExcept()
    :out_of_range("0~59분의 범위를 벗어났습니다.")
{
}

SExcept::SExcept()
    :out_of_range("0~59초의 범위를 벗어났습니다.")
{
}


int main()
{
    int hour, minute, second;
    string str;
    try
    {
        getline(cin, str);
        stringstream ss(str);
        ss >> hour >> minute >> second;

        if (hour < 0)
            throw HExcept();
        else if (minute > 59 || minute < 0)
            throw MExcept();
        else if (second > 59 || second < 0)
            throw SExcept();
    }
    catch(HExcept h)
    {
        cout << h.what() << endl;
    }
    catch (MExcept m)
    {
        cout << m.what() << endl;

    }
    catch (SExcept s)
    {
        cout << s.what() << endl;

    }

    int result = 0;
    result += hour * 60 * 60;
    result += minute * 60;
    result += second;

    cout << "입력하신 시간을 초 단위로 환산하면 " << result << "초입니다." << endl;


    return 0;
}

