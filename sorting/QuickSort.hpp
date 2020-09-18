/* 
clase para quick sort algorithm
javier alejandro martinez noe
31/9/20
*/
#include <iostream>
#include <vector>
#include "Sorter.hpp"
using namespace std;
#pragma onece

template <class T>
class QuickSort : public Sorter<T>{
private:
    void quickSort(vector<T> &list, int low, int high);
    int partition(vector<T> &list, int low, int high);
public:
    QuickSort(vector<T> &_lista);
    ~QuickSort();
    vector<T> sort();
};
template <class T>
QuickSort<T>::QuickSort(vector<T> &_lista): Sorter<T>(_lista)
{

}
template <class T>
QuickSort<T>::~QuickSort()
{
}
template <class T>
vector<T> QuickSort<T>::sort(){
    quickSort(this->lista, 0, this->lista.size()-1);
    return(this->lista);
}

template <class T>
void QuickSort<T>::quickSort(vector<T> &list, int low, int high){
   if(low < high){
       int piv = partition(list,low, high);
       quickSort(list,low, piv-1);
       quickSort(list,piv+1, high);
   }
}
template <class T>
int QuickSort<T>::partition(vector<T> &list, int low, int high){
    T pivote = list[high];
    int i = low -1;

    for (int j = low; j < high; j++){
        if(list[j] < pivote){
            i++;
            T temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    T temp = list[i+1];
    list[i+1] = list[high];
    list[high] = temp;
    return i + 1;
    

}




