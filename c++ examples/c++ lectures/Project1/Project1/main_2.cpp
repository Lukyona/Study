#include <iostream>
#include <map>
#include <set>
#include <string>

using std::cout;
using std::wcout;
using std::endl;
using std::map;
using std::make_pair;
using std::set;
using std::wstring; // wchar_t Ÿ���� �����迭�� ����

#define MAN 1
#define WOMAN 2

struct tStdInfo
{
    wchar_t name[20];
    unsigned char age;
    unsigned char gender;

    tStdInfo()
        : name{}, age(0), gender(0)
    {

    }

    tStdInfo(const wchar_t* pName, unsigned char _age, unsigned char _gender)
        : name{}, age(_age), gender(_gender)
    {
        wcscpy_s(name, pName);
    }
};

class MyClass
{
    int a;

public:
    bool operator < (const MyClass& other) // const ������ �ٸ� ���
    {
        if (a < other.a) return true;
        else return false;
    }

    bool operator < (const MyClass& other) const
    {
        if (a < other.a) return true;
        else return false;
    }

    bool operator > (const MyClass& other) const
    {
        if (a > other.a) return true;
        else return false;
    }
};

int main()
{
    // ����Ž�� != ����Ž��Ʈ��, ����Ž�� ��ü�� Ʈ���� �ƴϾ �� �� ����.
    // ��, ���ĵ� �����Ϳ��� ���� ����
    // 
    // ����Ž��Ʈ��(BST)
    // ������ �Է� �� Ž�� O(logN) ȿ��
    // Ʈ���� ����� �뷱���� �������� ������ ����� �� Ž�� ȿ���� ������ �ʴ´�.
    // - �ڰ����� ��� �ʿ� (AVL, Red/Black tree)


    set<int> setInt;

    setInt.insert(100); //         100
    setInt.insert(50);  //        /     /
    setInt.insert(150); //      50     150 


    const wchar_t* pStr = L"���ڿ�"; //�ּҸ� �Ѱ���

    map<const wchar_t*, tStdInfo> mapData;

    tStdInfo info(L"������", 18, MAN);
    tStdInfo info2(L"����ȣ", 18, WOMAN);

    mapData.insert(make_pair(L"������", info));
    mapData.insert(make_pair(L"����ȣ", info2));

    map<const wchar_t*, tStdInfo>::iterator mapiter;

    mapiter = mapData.find(L"������");

    _wsetlocale(LC_ALL, L"korean");

    if (mapiter == mapData.end())
    {
        wcout << L"������ ã�� ����" << endl;
    }
    else
    {
        wcout << L"�̸� : " << mapiter->second.name << endl;
        wcout << L"���� : " << mapiter->second.age << endl;
        wcout << L"���� : ";
        if (mapiter->second.gender == MAN)
        {
            wcout << L"����" << endl;
        }
        else if (mapiter->second.gender == WOMAN)
        {
            wcout << L"����" << endl;
        }
        else
        {
            wcout << L"�� �� ����" << endl;
        }

    }

    (*mapiter).first; // ������
    mapiter->second; // ������ ����

    map<wstring, tStdInfo> mapData2;

    wstring str;
    str = L"abc"; //�ּҸ� ����Ű�� �� �ƴ϶� ��ü������ ����(��)�� ������
    str += L"def";

    str = L"yaro"; // �̰ɷ� �ʱ�ȭ��
    str[2] = L'k';

    wstring str2;

    if (str == str2) // �ּ� �񱳰� �ƴ� ���� �����ϴ� ����(��) ��, ũ�� �񱳵� ����
    {

    }

    map<MyClass, tStdInfo> mapData3;
    MyClass a;
    mapData3.insert(make_pair(a, info)); //  MyClass�� >,<�� const�������� ���ǵǾ��־����


    return 0;
}