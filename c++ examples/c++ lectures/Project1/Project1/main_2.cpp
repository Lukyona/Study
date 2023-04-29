#include <iostream>
#include <map>
#include <set>
#include <string>
#include "CBST.h"

using std::cout;
using std::wcout;
using std::endl;
using std::map;
using std::make_pair;
using std::set;
using std::wstring; // wchar_t Ÿ���� �����迭�� ����

#define MAN 1 // ��ó���� - ������ ������ ���� ����
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

enum MY_TYPE
{
    TYPE_1, //0
    TYPE_2, //1
    TYPE_3, //2
};

enum class OTHER_TYPE
{
    TYPE_1,
    TYPE_10
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
    
    int a = TYPE_1;
    int b = (int)OTHER_TYPE::TYPE_1;


    // ����Ž�� != ����Ž��Ʈ��, ����Ž�� ��ü�� Ʈ���� �ƴϾ �� �� ����.
    // ��, ���ĵ� �����Ϳ��� ���� ����
    // 
    // ����Ž��Ʈ��(BST)
    // ������ �Է� �� Ž�� O(logN) ȿ��
    // Ʈ���� ����� �뷱���� �������� ������ ����� �� Ž�� ȿ���� ������ �ʴ´�.
    // - �ڰ����� ��� �ʿ� (AVL, Red/Black tree)


    /*set<int> setInt;

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
    */


    CBST<int, int> bstint;

    tPair<int, int> pair;

    pair.first = 100;
    bstint.insert(pair);

    pair.first = 150;
    bstint.insert(pair);

    bstint.insert(make_bstpair(50, 0));
    bstint.insert(make_bstpair(175, 0));
    bstint.insert(make_bstpair(75, 0));
    bstint.insert(make_bstpair(25, 0));
    bstint.insert(make_bstpair(125, 0));


    CBST<int, int>::iterator iter = bstint.begin();

    iter = bstint.find(150);

   /* (*iter).first;
    iter->first;

    tPair<int, int>* pPair = &pair;
    pPair->first;
    pPair->second;

    for (iter = bstint.begin(); iter != bstint.end(); ++iter)
    {
        wcout << iter->first << endl;
    }*/


    iter = bstint.erase(iter);

    iter = bstint.find(100);
    iter = bstint.erase(iter);


    for (iter = bstint.begin(); iter != bstint.end(); ++iter)
    {
        wcout << iter->first << endl;
    }
        

    // ���
    // ������ ȣ�� ���� : �ڽ� -> �θ�
    // ������ ����/�ʱ�ȭ ���� : �θ� -> �ڽ�
    // �Ҹ��� ȣ��/���� ���� : �ڽ� -> �θ�
    
    // �������̵� : �θ�Ŭ������ ��� �Լ��� �ڽ� Ŭ�������� �����������ν� �ڽ� Ŭ������ ������ ����� ȣ��ǵ��� �Ѵ�.

    return 0;
}