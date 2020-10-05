/* 
clase para crear Linked Lists
javier alejandro martinez noe
30/9/20
*/
#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <iostream>
using namespace std;

template <class T>
class Node
{
protected:
    T val;
    Node<T> *next;

public:
    ~Node<T>() {};
    Node<T>(T pVal, Node<T> *pNext)
    {
        val = pVal;
        next = pNext;
    };

    T get_val() {return val;};
    void set_val(T pVal) {val = pVal;};
    Node<T> *get_next() {return next;};
    void set_next(Node<T> *pNext) {next = pNext;};
};

template <class T>
class LinkedList
{
protected:
    Node<T> *head;

public:
    ~LinkedList()
    {
        DeleteList();
    };
    LinkedList()
    {
        head = NULL;
    };

    int length();
    void print();
    void push(T pVal);
    void append(T pVal);
    int insert_item(T pVal, int index);
    bool is_empty();
    int delete_item(int index);
    int get_nth(int index, T &item);
    int Count(T searchFor);
    void DeleteList();
    void RemoveDuplicates();
    void Reverse();
    void Sort();
    void SortedInsert (Node<T> * newNode);

};
template <class T>
int LinkedList<T>:: length(){
    int length = 0;
    Node<T> *ptr = head;
    while (ptr != NULL){
        length++;
        ptr = ptr->get_next();
    }
    return length;
}

template <class T>
void LinkedList<T>::print(){
    Node<T> *ptr = head;
    while (ptr != NULL)
    {
        std::cout << ptr->get_val() << ", ";
        ptr = ptr->get_next();
    }
    std::cout << std::endl;        
    }


template <class T>
void LinkedList<T>::push(T pVal){
    Node<T> *node = new Node<T>(pVal, head);
    head = node;
};


template <class T>
void LinkedList<T>::append(T pVal){
    Node<T> *ptr = head;
    while (ptr->get_next() != NULL)
    {
        ptr = ptr->get_next();
    }
    Node<T> *node = new Node<T>(pVal, NULL);
    ptr->set_next(node);
};

template <class T>
int LinkedList<T>::insert_item(T pVal, int index){
    if (index > length()){
        return -1;
    }
        
    if (index < 0){
        return -2;
    }
    if (index == 0){
        push(pVal);
        return 1;
    }

    int i = 0;
    Node<T> *ptr = head;
    Node<T> *pre = NULL;
    while (ptr != NULL && index > i){
        pre = ptr;
        ptr = ptr->get_next();
        i++;
    }
    Node<T> *node = new Node<T>(pVal, ptr);
    pre->set_next(node);
    return 1;
};
template <class T>
bool LinkedList<T>::is_empty(){        
    return head == NULL;
};

template <class T>
int LinkedList<T>:: delete_item(int index){
    if (is_empty()){
        return -1;
    }     
    if (index >= length()){
        return -1;
    }
    if (index < 0){
        return -2;
    }
    if (index == 0){
        Node<T> *temp = head;
        head = head->get_next();
        delete temp;
        return 1;
    }
    int i = 0;
    Node<T> *ptr = head;
    Node<T> *pre = NULL;
    while (ptr->get_next() != NULL && index > i){
        pre = ptr;
        ptr = ptr->get_next();
        i++;
    }
    pre->set_next(ptr->get_next());
    delete ptr;
    return 1;
};

template <class T>
int LinkedList<T>::get_nth(int index, T &item){
    if (index < 0){
        return -1;
    }  
    if (index >= length()){
        return -2;
    }    
    int i = 0;
    Node<T> *ptr = head;
    while (ptr->get_next() != NULL && index > i){
        ptr = ptr->get_next();
        i++;
    }
    item = ptr->get_val();
    return 1;
};
template <class T>
int LinkedList<T>:: Count(T searchFor){
    /*
    Esta funcion cuenta el número de veces que ocurre un elemento dado en la lista. 
    Esta funcion tine una complejidad temporal de O(n) porque recorre toda la lista para 
    poder hacer las comparaciones.
    */
    if (is_empty()){
        return -1;
    }  
    int i = 0;
    Node<T> *ptr = head;
    while (ptr != NULL){
        if(ptr->get_val()==searchFor){
            i++;
        }
        ptr = ptr->get_next();
    }
    return i;
}

template <class T>
void LinkedList<T>::DeleteList(){
    /*
    Esta funcion borra todos los elemntos de la lista y redefine los apuntadores 
    que la lista se entienda como vacia. 
    Esta funcion tine una complejidad temporal de O(n) porque recorre toda la lista para 
    poder borrar y redefinir los apuntadores.
    */
    if (not is_empty()){
    Node<T> *trash;
    Node<T> *ptr = head;
    head = NULL;
    while (ptr != NULL){
        trash = ptr;
        ptr = ptr->get_next();
        delete(trash);
    }
    }
}

template <class T>
void LinkedList<T>::RemoveDuplicates(){
    /*
    Esta funcion remueve los elemetos duplicados dejando el primero de una lista. 
    
    Esta funcion tine una complejidad temporal de O(n^2) porque recorre toda la lista al cuadrado para 
    poder hacer las comparaciones y borrar los elemtos repetidos. Tiene una funcionalidad similar a 
    seleccion sort.
    */
    if (not is_empty()){
        int puntList[length()];
        Node<T> *ptr = head;
        Node<T> *pActual = ptr->get_next();
        Node<T> *pre = ptr;
        int i = 0;
        puntList[0] = ptr->get_val();
        while (ptr != NULL && ptr->get_next() != NULL){
            //cout <<"ciclo " << i <<endl;
            pActual = ptr->get_next();
            pre = ptr;
            while (pActual->get_next() != NULL){
                //cout << puntList[i] << " ------ "<<pActual->get_val()<<endl;
                if(puntList[i] == pActual->get_val()){
                    pre->set_next(pActual->get_next());
                    delete(pActual);
                    pActual = pre->get_next();
                    //cout << "borrado" <<endl;
                    //cout << pre->get_val() <<" pre-> "<<pre->get_next()->get_val()<<endl;
                }
                else{
                    pre = pActual;
                    pActual = pActual->get_next();
                    //cout << "No borrado" <<endl;
                }
            }
            //cout << puntList[i] << " ------ "<<pActual->get_val()<<endl;
            //cout << "end Secuence" <<endl;  
            if(puntList[i] == pActual->get_val()){
                pre->set_next(pActual->get_next());
                delete(pActual);
                pActual = pre->get_next();
            }
            else{
                pre = pActual;
                pActual = pActual->get_next();
                i++;
            }

            ptr = ptr->get_next();
            if(ptr != NULL){
                puntList[i] = ptr->get_val();
            }
        } 
    }       
}


template <class T>
void LinkedList<T>::Reverse(){
    /*
    Esta funcion invierte el orden de los elementos en la lista. 
    
    Esta funcion tine una complejidad temporal de O(n) porque recorre toda la lista para 
    poder hacer el reordenamiento.
    */
    if (not is_empty()){
        int space = length();
        int index[space-1];
        Node<T> *ptr = head;
        for (int i = 0; i < space; i++){
            index[space-1-i] = ptr->get_val();
            ptr = ptr->get_next();
        }
        ptr = head;
        for (int i = 0; i < space; i++){
            ptr->set_val(index[i]);
            ptr = ptr->get_next();
        }
    }
}

template <class T>
void LinkedList<T>:: Sort(){
    /*
    Esta funcion ordena los elemento en la lista de manera acendente. 
    
    Esta funcion tine una complejidad temporal de O(n^2), porque recorre toda la lista al cuandrado, 
    ocupa el algoritmo de Bubble Sort para ordenar e implementa una salida para que si en un ciclo 
    no se ha ordenado la lista se detenga. Sin embargo en el peor de los casos sige siendo O(n^2).
    */
    if(not is_empty()){
        Node<T> *ptr = head;
        for(size_t i = 0; i < length(); i++){
            bool noSwap = true;
            while(ptr->get_next() != NULL){
                if(ptr->get_val() > ptr->get_next()->get_val()){
                    T temp = ptr->get_val();
                    ptr->set_val(ptr->get_next()->get_val());
                    ptr->get_next()->set_val(temp);
                    noSwap = false;
                }
                ptr = ptr->get_next();
            }
            if(noSwap){
                break;
            }
            ptr = head;
        }
    }
}

template <class T>
void LinkedList<T>:: SortedInsert(Node<T> * newNode){
    /*
    Esta funcion llama a la funcion de ordenamiento e incerta un Nodo en su posicion 
    respectiva deacuerdo a su valor. 
    
    Esta funcion tine una complejidad temporal de O(n), si se cuenta el ordenamiento como un 
    prerequisito, ya que esta nadamas recorre la lista para incertar un Nodo en la posision respectiva. 
    
    Si se toma el ordenamiento como parte de la funcion, esta tiene una complejidad temporal de O(n^2),
    ya la funcionalidad espesifica de la funcion se ve amalgamada con la del ordenamiento y solo se queda 
    con la mayor complejidad O(n^2).
    */
    if(not is_empty()){
        Sort();
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        if(newNode->get_val() <= ptr->get_val()){
            head = newNode;
            newNode->set_next(ptr);
        }
        else{
            while(ptr->get_next() != NULL && newNode->get_val() > ptr->get_val()){
                pre = ptr;
                ptr = ptr->get_next();
            }
            if(newNode->get_val() > ptr->get_val()){
                newNode->set_next(NULL);
                ptr->set_next(newNode); 
            }
            else{
                newNode->set_next(ptr);
                pre->set_next(newNode); 
            }
             
        }
    }
}
#endif