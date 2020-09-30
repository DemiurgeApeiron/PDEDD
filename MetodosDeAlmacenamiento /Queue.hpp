#ifndef _QUEUE_HPP
#define _QUEUE_HPP
#include <iostream>
#include "linked_list.hpp"
using namespace std;
template<class T>
class Queue : public LinkedList<T>
{
protected:
    /* data */
public:
    Queue(/* args */);
    ~Queue();
    void enqueue(T val){this->push(val);}
    T dequeue();
};
template<class T>
Queue<T>::Queue(/* args */)
{
}
template<class T>
Queue<T>::~Queue()
{
}
template<class T>
T Queue<T>::dequeue(){
    Node<T> *ptr = this->head;
    if(ptr == NULL){
        throw "Queue is empty";
    }
    if(ptr->get_next() == NULL){
        T res = ptr->get_val();
        delete(ptr);
        this->head = NULL;
        return(res);
    }
    Node<T> *pre = NULL;
    while(ptr->get_next() != NULL){
        pre = ptr;
        ptr = ptr->get_next();
    }
    T res = ptr->get_val();
    delete(ptr);
    pre->set_next(NULL);
    return res;
}


#endif