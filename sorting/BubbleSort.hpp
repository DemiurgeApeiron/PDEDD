/* 
clase abstracta para los sorting algorithm
javier alejandro martinez noe
31/9/20
*/
#include <iostream>
#include <vector>
#include "Sorter.hpp"
using namespace std;
#pragma once;

template <class T>
class BubbleSort : public Sorter<T>
{
private:
    vector<T> sortForwards(vector<T> list, int iActual, int iFuture, T vActual, T vFuture, bool &noSwap);
    vector<T> sortBack(vector<T> list, int iActual, int iFuture, T vActual, T vFuture, bool &noSwap);
public:
    BubbleSort(vector<T> &_lista);
    ~BubbleSort();
    vector<T> sort();
};
template <class T>
BubbleSort<T>::BubbleSort(vector<T> &_lista): Sorter<T>(_lista)
{
}
template <class T>
BubbleSort<T>::~BubbleSort()
{
}

template <class T>
vector<T> BubbleSort<T>:: sortBack(vector<T> list, int iActual, int iFuture, T vActual, T vFuture, bool &noSwap){
    if(iActual*-1 == list.size()){
        return this->lista;
    }
    else{
        if(vActual < vFuture){
            T temp = this->lista[iActual];
            this->lista[iActual] = this->lista[iFuture];
            this->lista[iFuture] = temp;
            noSwap = false;
        }
        else{
            vActual = vFuture;
        }
        sortBack(list,iFuture,iFuture-1, vActual, list[iFuture-1], noSwap);
    }
    return this->lista;
}

template <class T>
vector<T> BubbleSort<T>:: sortForwards(vector<T> list, int iActual, int iFuture, T vActual, T vFuture, bool &noSwap){
    if(iActual == list.size()-1){
        return this->lista;
        
    }
    else{
        if(vActual > vFuture){
            T temp = this->lista[iActual];
            this->lista[iActual] = this->lista[iFuture];
            this->lista[iFuture] = temp;
            noSwap = false;
        }
        else{
            vActual = vFuture;
        }
        sortForwards(list,iFuture,iFuture+1, vActual, list[iFuture+1],noSwap);
    }
    return this->lista;
}

template <class T>
vector<T> BubbleSort<T>::sort(){
    for(size_t i =0; i < this->lista.size(); i++){
        bool noSwap = true;
        this->lista = sortBack(this-> lista, -1, -2, this-> lista[-1], this-> lista[-2], noSwap);
        this->lista  = sortForwards(this-> lista, 0, 1, this->lista[0], this->lista[1], noSwap);
        if(noSwap){
            break;
        }
    }
    
    return this->lista ;

}

