#ifndef _Node_HPP
#define _Node_HPP
template <class T>
class Node
{
private:
    T val,
    Node<T> *next;
public:
    Node(T pVal, Node<T> *pNext);
    ~Node();


};
template <class T>
Node<T>::Node(/* args */)
{
}
template <class T>
Node<T>::~Node()
{
}
template <class T>
class LinkedList
{
private:
    Node<T> *head
    Node<T> *tail
public:
    LinkedList(/* args */);
    ~LinkedList();
    int length();
    void push(T pVal);
    void append(T pVal);
    int incertItem(T pVal);
    int deleteItem(int index);
    T getNth(int index);
};
template <class T>
LinkedList<T>::LinkedList(/* args */)
{
}
template <class T>
LinkedList<T>::~LinkedList()
{
}




#endif