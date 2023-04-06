#include <iostream>
#include "Arr.h"
#include "CArr.h"
#include "CList.h"
#include <list>

using std::cout, std::endl, std::cin;

int main()
{
    // Arr
    /*tArr arr;
    InitArr(&arr);

    int val = 0;
    for(int i = 0; i < 10; i++)
    {
        std::cin >> val;
        PushBack(&arr, val);
    }

    std::cout << arr.maxCount << std::endl;

    for(int i = 0; i < arr.count; i++)
    {
        std::cout << arr.pInt[i] << std::endl;
    }
    ReleaseArr(&arr);*/


    //CArr
    //CArr<int> carr;
    //carr.PushBack(10);
    //carr.PushBack(20);
    //carr.PushBack(30);

    //int data = carr[1];
    //carr[1] = 40;

    //carr[2] = 50;

    //cout << carr[2] << endl;
    

    //CList
   /* CList<int> clist;

    for (int i = 0; i < 4; ++i)
    {
        clist.PushBack(i);
    }*/


    //iterator
    //CArr<int> myvec;
    //
    //myvec.PushBack(1);
    //myvec.PushBack(2);
    //myvec.PushBack(3);

    //CArr<int>::iterator myiter = myvec.begin();


    //int value = *myiter;
    //*myiter = 100;


    //for (; myiter != myvec.end(); ++myiter)
    //{
    //    cout << *myiter << endl;
    //}

    //myiter = myvec.begin();
    //int data = *(myiter++); // data = 100
    //
    //myiter = myvec.begin();
    //int data1 = *(++myiter); // data1 = 2


    //CArr arr1 = myvec; // 대입 연산자가 아니라 알아서 복사생성자가 호출됨

    //cout << arr1[2] << endl;
    

    //erase
    //CArr<int> myvec;
    //
    //myvec.PushBack(1);
    //myvec.PushBack(2);
    //myvec.PushBack(3);

    //CArr<int>::iterator myiter = myvec.begin();
    //myiter = myvec.erase(++myiter);

    //for (myiter = myvec.begin(); myiter != myvec.end(); ++myiter)
    //{
    //    cout << *myiter << endl;
    //}

    //myvec.clear();

    //for (int i = 0; i < 10; ++i)
    //{
    //    myvec.PushBack(i);
    //}

    //myiter = myvec.begin();
    //for (; myiter != myvec.end(); ) // 홀수 제거
    //{
    //    if (*myiter == 9) myiter = myvec.erase(myiter);
    //    else ++myiter;
    //}

    //for (myiter = myvec.begin(); myiter != myvec.end(); ++myiter)
    //{
    //    cout << *myiter << endl;
    //}

    
    //list iterator
    CList<int> mylist;

    mylist.PushBack(100);
    mylist.PushBack(200);
    mylist.PushBack(300);

    CList<int>::iterator listiter = mylist.begin();
    *listiter = 150;

    cout << "list iterator test" << endl;

    listiter = mylist.insert(listiter, 100);


    for (listiter = mylist.begin(); listiter != mylist.end(); ++listiter)
    {
        cout << *listiter << endl;
    }

    list<int> li;

    return 0;
}
