#include <iostream>
using namespace std;

int sumArr(int* begin, int* end);


int main()
{
    enum colors { red, orange, yellow, green, blue };
    // 지정 따로 안 해주면 0부터 1,2,3,4

    enum colors2 { red1 = 1, orange1 = 3, yellow1, green1, blue1 };
    // 1, 3, 4, 5, 6

    colors2 a = green1;

    cout << a << endl;
    // 5가 출력됨

    int* p = new int;

    delete p;

    int arr[5] = { 1,2,3,4,5 };
    for (int i : arr)
    {
        cout << i;
    }

    // < <= > >= == != 관계표현식

    int arr2[3][2] = {
        {1,3}, {3,4}, {5,6}
    };

    //논리합 || 논리곱 && 논리부정 !

    cout << sumArr << endl; // 함수 주소 뜸

    // 함수포인터
    int (*pf)(int*, int*);
    pf = sumArr;

    //이런 식으로 사용
    cout << (*pf)(arr, arr + 3) << endl;

    // 인라인 함수
    // 함수 호출 = 그 함수 주소로 점프함
    // 인라인 함수 호출 = 점프 안 하고 그 함수의 코드를 그대로 가져옴
    // 이건 컴파일러가 하는 거고 호출 방법 자체는 똑같음, 함수(매개변수)

    //디폴트 매개변수
    //int add(int fir, int sec = 1)
    // sec 매개변수를 넣지 않아도 오류가 나지 않고 디폴트 값인 1이 들어간 채로 함수 호출

    // 함수 오버로딩
    // 리턴형만 다른 건 안 됨, 매개변수가 무조건 달라야함

    // 템플릿
    // template <typename T>  or <class T>

    //class Stock이 있다는 가정 하에 클래스 배열
    /* Stock s[3] = {
        Stock("A", 100, 2),
        Stock("B", 200, 4),
        Stock("C", 300, 6)
    };*/


    // friend 함수(프라이빗 멤버 변수에 접근 가능)는 해당 클래스 내부에 있지만 멤버 함수는 아니며
    //  정의할 때 friend 키워드 제외하고 클래스 범위 확인 연산자(::)도 안 붙임


    // << 연산자 오버로딩, cout << stock이 가능하도록
    /*std::ostream& operator << (std::ostream& os, Stock& s)
    {
        os << s.name << " " << s.val;
        return os;
    }*/


    //string 함수들
    // 
    // stoi(), string to int, 문자열을 정수로, 변환하려는 문자열에 숫자 말고 다른 게 들어가있으면 오류
    //getline(), 공백 포함 문자열 입력받기, 줄바꿈까지 입력받음
    //substr(), 문자열 분리, 첫번째 매개변수 시작 인덱스, 두번째 매개변수 개수
    //find(), 문자열 찾기, 첫번째 매개변수 찾을 문자열, 검색 시작 인덱스, 반환값이 -1이면 발견 실패
    //replace(), 문자열 대체, 첫번째 매개변수 대체 시작 위치, 두번째 매개변수 길이, 세번째 매개변수 대체할 문자열(이걸로 대체됨)


    // >> 비트를 오른쪽으로 이동, 나누기 2의 효과, 비트가 오른쪽으로 이동해 사라지는 것을 언더플로우
    // << 비트를 왼쪽으로 이동, 곱하기 2의 효과, 비트가 왼쪽으로 이동해 사라지는 것을 오버플로우
    // >>=, <<= 사용 가능
    // 음수에 오른쪽 시프트 연산자 사용 시 1로 채우기, 나머지 경우는 다 0으로 채움

    //MSB(Most Significant Bit) = 부호비트(가장 중요)
    //LSB(Least Signigicant Bit) = 맨 오른쪽 비트

    // 비트 연산자 
    // 논리곱 &, 논리합 |, 논리부정 ~
    // 배타 논리합 ^ XOR, 한 개만 1일 때 1, 둘 다 1이면 0
    // &= |= ^= 가능

    return 0;
}

// 배열의 시작 주소와 끝 주소를 받아 반복문 실행
int sumArr(int* begin, int* end)
{
    int total = 0;
    int* pt;

    for (pt = begin; pt != end; pt++)
    {
        total += *pt;
    }
    return total;
}