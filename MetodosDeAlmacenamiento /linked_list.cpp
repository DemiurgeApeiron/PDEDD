#include "linked_list.hpp"
using namespace std;
int main()
{
    LinkedList<int> list;
    list.push(3);
    list.push(6);
    list.push(4);
    list.push(6);
    list.push(4);
    list.delete_item(0);    
    list.delete_item(0);    
    list.append(6);
    list.append(4);
    list.append(4);
    list.insert_item(100, 5);
    list.insert_item(4, 5);
    int item;
    list.get_nth(5, item);
    list.print();
    //std::cout << item << std::endl;
    cout << list.Count(4) <<endl;
    list.RemoveDuplicates();
    list.print();
    list.Reverse();
    list.print();


    list.DeleteList();
    cout << list.length() <<endl;



    return 0;
}