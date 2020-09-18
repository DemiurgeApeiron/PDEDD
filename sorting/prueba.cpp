#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "mytimer.h"
#include <algorithm>

using namespace std;
template<class T>
void printVector(vector<T> &lista){
    for(size_t i = 0; i < lista.size(); i++){
        cout << lista[i] << ", ";
    }
    cout <<endl;
}

template <class T>
void merge(vector<T> &arr, int begin, int mid, int end){
    int i = begin;
    int j = mid +1;
    vector<T> aux(arr.begin()+begin, arr.begin()+end);

    for(int k = begin; k <= end; k++){
        if((aux[i-begin] < aux[j-begin] || j < end) && i <= mid){
            arr[k] = aux[i-begin];
            i++;
        }
        else if((aux[i-begin] < aux[j-begin] || j < end) && i <= mid){
            arr[k] = aux[j-begin];
            j++;
        }
    }

  
}

template <class T>
void mergeSort(vector<T> &listaToMege, int primer, int ultimo){
    int n = listaToMege.size();
    if(primer < ultimo){
    
        int medio = primer + (ultimo - primer) / 2;

        mergeSort(listaToMege, primer, medio);
        mergeSort(listaToMege, medio+1,ultimo);

        merge(listaToMege,primer,medio,ultimo);

    }
    else{

    }
}


int main(){
    int listSize = 10;
    vector<int> listaTest;
    vector<int> listaNueva1;

    srand(time(NULL));
    for(size_t i = 0; i < listSize; i++){
        int numRand = (int)rand();
        listaTest.push_back(numRand % (listSize));
        listaNueva1.push_back(numRand % (listSize));

    }
    //printVector(listaNueva1);
    cout << "ordenada std"<<endl;
    DECLARE_TIMING(t0);
    START_TIMING(t0);
    sort(listaTest.begin(), listaTest.end()); 
    STOP_TIMING(t0);
    SHOW_TIMING(t0, "tiempo de procesado con std Sort");
    printVector(listaTest);
    cout <<endl;

    DECLARE_TIMING(t4);
    START_TIMING(t4);
    mergeSort(listaNueva1, 0, listaNueva1.size());
    vector<int> Ovector4 = listaNueva1;
    STOP_TIMING(t4);
    SHOW_TIMING(t4, "tiempo de procesado con Merge Sort");
    printVector(Ovector4);
    cout <<endl; 

}

