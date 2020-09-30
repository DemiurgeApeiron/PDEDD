/* 
clase abstracta para los sorting algorithm
javier alejandro martinez noe
31/9/20
*/
#include <iostream>
#include <vector>
#include "Sorter.hpp"
using namespace std;
#pragma once

template <class T>
class BubbleSort : public Sorter<T>
{
private:
    vector<T> sortForwards(vector<T> &list, int iActual, int iFuture, T vActual, T vFuture, bool &noSwap);
    vector<T> sortBack(vector<T> &list, int iActual, int iFuture, T vActual, T vFuture, bool &noSwap);
    vector<T> sortIterator(vector<T> &list);
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
vector<T> BubbleSort<T>:: sortBack(vector<T> &list, int iActual, int iFuture, T vActual, T vFuture, bool &noSwap){
    if(iActual*-1 == list.size()){
        return list;
    }
    else{
        if(vActual < vFuture){
            T temp = list[iActual];
            list[iActual] = list[iFuture];
            list[iFuture] = temp;
            noSwap = false;
        }
        else{
            vActual = vFuture;
        }

        sortBack(list,iFuture,iFuture-1, vActual, list[iFuture-1], noSwap);

    }

    return list;
}

template <class T>
vector<T> BubbleSort<T>:: sortForwards(vector<T> &list, int iActual, int iFuture, T vActual, T vFuture, bool &noSwap){
    if(iActual == list.size()-1){
        return list;
        
    }
    else{
        if(vActual > vFuture){
            T temp = list[iActual];
            list[iActual] = list[iFuture];
            list[iFuture] = temp;
            noSwap = false;
        }
        else{
            vActual = vFuture;
        }
        sortForwards(list,iFuture,iFuture+1, vActual, list[iFuture+1],noSwap);
    }
    return list;
}
template <class T>
vector<T> BubbleSort<T>:: sortIterator(vector<T> &list){
    for(size_t i = 0; i < list.size(); i++){
        bool noSwap = true;
        for(size_t j = 0; j < list.size()-1; j++){
            if(list[j] > list[j+1]){
                T temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                noSwap = false;
            }
        }
        if(noSwap){
            break;
        }
    }
    return list;
}

template <class T>
vector<T> BubbleSort<T>::sort(){
    vector<T> list = this->lista;
    list = sortIterator(list);

    
    //este funciona es recursivo y segun yo tiene la misma complejidad, pero por alguna razon es muchooooo mas lenta
    /*for(size_t i =0; i < list.size(); i++){

        bool noSwap = true;
        list  = sortForwards(list, 0, 1, list[0], list[1], noSwap);
        if(noSwap){
            break;
        }
    }
    */
    return list ;

}

