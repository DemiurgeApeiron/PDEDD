/* 
clase abstracta para los sorting algorithm
javier alejandro martinez noe
31/9/20
*/
#include <iostream>
#include <vector>
#include "Sorter.hpp"
using namespace std;
#pragma onece;

template <class T>
class SelectionSort : public Sorter<T>{
private:
    /* data */
public:
    SelectionSort(vector<T> &_lista);
    ~SelectionSort();
    vector<T> sort();
};
template <class T>
SelectionSort<T>::SelectionSort(vector<T> &_lista): Sorter<T>(_lista)
{

}
template <class T>
SelectionSort<T>::~SelectionSort()
{
}
template <class T>
vector<T> SelectionSort<T>::sort(){
    T j = 0; 
    for (size_t i = 0; i < this -> lista.size(); i++){
        j = i;
        for (j; j < this ->lista.size(); j++) {
            //cout << "la: " <<lista[i] << " lj: " <<lista[j] << " j: " << j << " i: " << i <<endl;
            if(this ->lista[i] > this ->lista[j]){
                //cout << "li " << lista[i] << "lj " << lista[j] <<endl;
                T temp = this ->lista[j];
                this ->lista[j] = this ->lista[i];
                this ->lista[i] = temp;

            } 
        }  
    }
    return this ->lista;
}


