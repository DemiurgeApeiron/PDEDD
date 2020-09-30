/* 
clase abstracta para los sorting algorithm
javier alejandro martinez noe
31/9/20
*/
#ifndef OO_hpp
#define OO_hppOO_hpp
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
    vector<T> sort(vector<T> &arr, bool (*compare)(T &a, T B));
    ~Sorter();
};
template <class T>
Sorter<T>::Sorter(vector<T> &_lista) : lista(_lista){}
template <class T>
Sorter<T>::~Sorter(){
}
template <class T>
vector<T> Sorter<T>:: sort(vector<T> &arr, bool (*compare)(T &a, T B)){
    for(size_t i = 0; i < arr.size()-1;i++){
        size_t min = i;
        for(size_t j = i+1; j < arr.size();j++){
            if((8*compare)(arr[j],arr[min])){
                min = j
            }
        }
        T temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
#endif

