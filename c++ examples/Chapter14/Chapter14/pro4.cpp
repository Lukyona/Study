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
    :out_of_range("�ð� ������ ������ϴ�.")
{
}

MExcept::MExcept()
    :out_of_range("0~59���� ������ ������ϴ�.")
{
}

SExcept::SExcept()
    :out_of_range("0~59���� ������ ������ϴ�.")
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

    cout << "�Է��Ͻ� �ð��� �� ������ ȯ���ϸ� " << result << "���Դϴ�." << endl;


    return 0;
}

