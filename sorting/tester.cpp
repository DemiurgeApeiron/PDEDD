#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "mytimer.h"
#include <algorithm>
#include "SelectionSort.hpp"
#include "BubbleSort.hpp"
#include "IncertionSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
using namespace std;
template<class T>
void printVector(vector<T> &lista){
    for(size_t i = 0; i < lista.size(); i++){
        cout << lista[i] << ", ";
    }
    cout <<endl;
}


int main(){
    int listSize = 10;
    vector<int> listaTest;
    vector<int> listaNueva1;
    vector<int> listaNueva2;
    vector<int> listaNueva3;
    vector<int> listaNueva4;
    vector<int> listaNueva5;
    srand(time(NULL));
    for(size_t i = 0; i < listSize; i++){
        int numRand = (int)rand();
        listaTest.push_back(numRand % (listSize));
        listaNueva1.push_back(numRand % (listSize));
        listaNueva2.push_back(numRand % (listSize));
        listaNueva3.push_back(numRand % (listSize));
        listaNueva4.push_back(numRand % (listSize));
        listaNueva5.push_back(numRand % (listSize));
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

    SelectionSort<int> selectionsort(listaNueva1);
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    vector<int> Ovector = selectionsort.sort();
    STOP_TIMING(t1);
    SHOW_TIMING(t1, "tiempo de procesado con Selection Sort");
    //printVector(Ovector);
    cout <<endl;  

    BubbleSort<int> bubblesort(listaNueva2);
    DECLARE_TIMING(t2);
    START_TIMING(t2);
    vector<int> Ovector2 = bubblesort.sort();
    STOP_TIMING(t2);
    SHOW_TIMING(t2, "tiempo de procesado con Bubble Sort");
    //printVector(Ovector2);
    cout <<endl; 

    IncertionSort<int> incertionsort(listaNueva3);
    DECLARE_TIMING(t3);
    START_TIMING(t3);
    vector<int> Ovector3 = incertionsort.sort();
    STOP_TIMING(t3);
    SHOW_TIMING(t3, "tiempo de procesado con Incertion Sort");
    //printVector(Ovector3);
    cout <<endl; 

    MergeSort<int> mergesort(listaNueva4);
    DECLARE_TIMING(t4);
    START_TIMING(t4);
    vector<int> Ovector4 = mergesort.sort();
    STOP_TIMING(t4);
    SHOW_TIMING(t4, "tiempo de procesado con Merge Sort");
    printVector(Ovector4);
    cout <<endl; 

    QuickSort<int> quicksort(listaNueva5);
    DECLARE_TIMING(t5);
    START_TIMING(t5);
    vector<int> Ovector5 = quicksort.sort();
    STOP_TIMING(t5);
    SHOW_TIMING(t5, "tiempo de procesado con Quick Sort");
    printVector(Ovector5);
    cout <<endl; 

    





}