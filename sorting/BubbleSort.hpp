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
vector<T> BubbleSort<T>::sort(){
    vector<T> list = this->lista;
    for(size_t i =0; i < list.size(); i++){

        bool noSwap = true;
        /*cout << "gg0" <<endl;
        list = sortBack(list, -1, -2, list[list.size()-1], list[list.size()-2], noSwap);
        cout << "gg" <<endl;*/
        list  = sortForwards(list, 0, 1, list[0], list[1], noSwap);
        if(noSwap){
            break;
        }
    }
    
    return list ;

}

