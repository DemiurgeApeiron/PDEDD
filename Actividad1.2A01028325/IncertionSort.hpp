/* 
clase abstracta para los sorting algorithm
javier alejandro martinez noe
31/9/20
*/
#include <iostream>
#include <vector>
#include "Sorter.hpp"
using namespace std;
#pragma onece

template <class T>
class IncertionSort : public Sorter<T>{
private:
    /* data */
public:
    IncertionSort(vector<T> &_lista);
    ~IncertionSort();
    vector<T> sort();
};
template <class T>
IncertionSort<T>::IncertionSort(vector<T> &_lista): Sorter<T>(_lista)
{

}
template <class T>
IncertionSort<T>::~IncertionSort()
{
}
template <class T>
vector<T> IncertionSort<T>::sort(){
    T key;
    for(size_t i = 1; i < this->lista.size();i++){
        key = this->lista[i];
        int j = i-1;
        while((j >= 0) && (this->lista[j] > key)){
            this->lista[j+1] = this->lista[j];
            j--;
        }
        this->lista[j+1] = key;
    }
    return this ->lista;
}


