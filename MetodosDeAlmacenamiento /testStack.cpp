#include "linked_list.hpp"
#include "Stack.hpp"
using namespace std;
int main()
{
    Stack<int> list;
    list.push(4);
    list.print();
    list.push(42);
    list.push(3);
    list.push(56);
    list.push(48);
    list.print();
    cout << "------------------------------" << endl;
    cout<<endl;
    int flag;
    cout<< list.pop(flag)<<endl;
    list.print();
    cout<< list.pop(flag)<<endl;
    list.print();
    cout<< list.pop(flag)<<endl;
    list.print();
    cout<< list.pop(flag)<<endl;
    list.print();
    cout<< list.pop(flag)<<endl;
    list.print();

    try{
        cout<< list.peek()<<endl;
    }
    
    catch(const exception& e){
        cerr << e.what() << '\n';
    }
    list.print();
    return 0;
}