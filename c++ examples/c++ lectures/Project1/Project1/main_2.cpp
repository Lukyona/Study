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
using std::wstring; // wchar_t 타입의 가변배열과 유사

#define MAN 1 // 전처리기 - 컴파일 이전에 먼저 실행
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
    bool operator < (const MyClass& other) // const 버전과 다른 취급
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


    // 이진탐색 != 이진탐색트리, 이진탐색 자체는 트리가 아니어도 할 수 있음.
    // 단, 정렬된 데이터에만 적용 가능
    // 
    // 이진탐색트리(BST)
    // 데이터 입력 및 탐색 O(logN) 효율
    // 트리의 모양이 밸런스가 유지되지 않으면 제대로 된 탐색 효율이 나오지 않는다.
    // - 자가균형 기능 필요 (AVL, Red/Black tree)


    /*set<int> setInt;

    setInt.insert(100); //         100
    setInt.insert(50);  //        /     /
    setInt.insert(150); //      50     150 


    const wchar_t* pStr = L"문자열"; //주소를 넘겨줌

    map<const wchar_t*, tStdInfo> mapData;

    tStdInfo info(L"마지용", 18, MAN);
    tStdInfo info2(L"신은호", 18, WOMAN);

    mapData.insert(make_pair(L"마지용", info));
    mapData.insert(make_pair(L"신은호", info2));

    map<const wchar_t*, tStdInfo>::iterator mapiter;

    mapiter = mapData.find(L"마지용");

    _wsetlocale(LC_ALL, L"korean");

    if (mapiter == mapData.end())
    {
        wcout << L"데이터 찾기 실패" << endl;
    }
    else
    {
        wcout << L"이름 : " << mapiter->second.name << endl;
        wcout << L"나이 : " << mapiter->second.age << endl;
        wcout << L"성별 : ";
        if (mapiter->second.gender == MAN)
        {
            wcout << L"남자" << endl;
        }
        else if (mapiter->second.gender == WOMAN)
        {
            wcout << L"여자" << endl;
        }
        else
        {
            wcout << L"알 수 없음" << endl;
        }

    }

    (*mapiter).first; // 마지용
    mapiter->second; // 마지용 정보

    map<wstring, tStdInfo> mapData2;

    wstring str;
    str = L"abc"; //주소를 가리키는 게 아니라 자체적으로 문자(열)를 관리함
    str += L"def";

    str = L"yaro"; // 이걸로 초기화됨
    str[2] = L'k';

    wstring str2;

    if (str == str2) // 주소 비교가 아닌 따로 관리하는 문자(열) 비교, 크기 비교도 가능
    {

    }

    map<MyClass, tStdInfo> mapData3;
    MyClass a;
    mapData3.insert(make_pair(a, info)); //  MyClass에 >,<가 const버전으로 정의되어있어야함
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
        

    // 상속
    // 생성자 호출 순서 : 자식 -> 부모
    // 생성자 실행/초기화 순서 : 부모 -> 자식
    // 소멸자 호출/실행 순서 : 자식 -> 부모
    
    // 오버라이딩 : 부모클래스의 멤버 함수를 자식 클래스에서 재정의함으로써 자식 클래스에 구현된 기능이 호출되도록 한다.

    return 0;
}