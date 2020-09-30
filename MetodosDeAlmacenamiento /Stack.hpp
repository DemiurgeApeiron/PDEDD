#ifndef _STACKS_HPP
#define _STACKS_HPP

#include <iostream>
#include "linked_list.hpp"
using namespace std;


template<class T>
class Stack : public LinkedList<T>
{
protected:
    using LinkedList<T>::insert_item;
    using LinkedList<T>::delete_item;
    using LinkedList<T>::append;
    using LinkedList<T>::get_nth;
    
public:
    Stack(/* args */);
    ~Stack();
    T pop(int &flag);
    T peek();

};
template<class T>
Stack<T>::Stack(/* args */)
{
}
template<class T>
Stack<T>::~Stack()
{
}
template<class T>
T Stack<T>:: pop(int &flag){
    flag = 1;
    if(this->is_empty()){
        flag = 0;
        return T();
    }
    T res = this->head->get_val();
    this->delete_item(0);
    return res;
}
template<class T>
T Stack<T>:: peek(){
    if(this->is_empty()){
        throw "stack is empty";
         
    }
    return(this->head->get_val());

}

#endif