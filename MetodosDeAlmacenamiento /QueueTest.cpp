#include "linked_list.hpp"
#include "Queue.hpp"
using namespace std;
int main()
{
    Queue<int> list;
    list.enqueue(4);
    list.enqueue(42);
    list.enqueue(3);
    list.enqueue(56);
    list.enqueue(48);
    list.print();
    cout << "------------------------------" << endl;
    cout<<endl;
    cout<< list.dequeue()<<endl;

    cout<< list.dequeue()<<endl;

    cout<< list.dequeue()<<endl;

    cout<< list.dequeue()<<endl;

    cout<< list.dequeue()<<endl;


    return 0;
}