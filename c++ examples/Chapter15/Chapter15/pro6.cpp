#include "Queue.h"


int main()
{
    /*Queue<int> queue1(4);

    int a = queue1.dequeue();

    queue1.enqueue(5);
    queue1.enqueue(2);
    queue1.enqueue(1);
    queue1.enqueue(7);
    queue1.enqueue(4);

    queue1.print();

    a = queue1.dequeue();
    queue1.enqueue(4);

    a = queue1.dequeue();
    a = queue1.dequeue();

    queue1.print();*/


    Queue<string> queue2(3);

    string a = queue2.dequeue();

    queue2.enqueue("y");
    queue2.enqueue("halo");
    queue2.enqueue("shinee");
    queue2.enqueue("s");

    a = queue2.dequeue();

    queue2.enqueue("2pm");

    queue2.print();

    a = queue2.dequeue();
    a = queue2.dequeue();


    queue2.print();

    return 0;
}