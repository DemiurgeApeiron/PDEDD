/* 
clase abstracta para los sorting algorithm
javier alejandro martinez noe
31/9/20
*/
#ifndef sorter_h
#define sorter_h
#include <iostream>
#include <vector>
using namespace std;
#pragma onece;

template <class T>
class Sorter{
protected:
    vector<T> lista;
public:
    Sorter(std::vector<T> &_lista);
    virtual vector<T> sort()= 0;
    ~Sorter();
};
template <class T>
Sorter<T>::Sorter(vector<T> &_lista) : lista(_lista){}
template <class T>
Sorter<T>::~Sorter(){
}
#endif

