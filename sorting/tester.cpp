#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "mytimer.h"
#include <algorithm>
#include "SelectionSort.hpp"
#include "BubbleSort.hpp"
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
    vector<int> listaNueva1;
    vector<int> listaNueva2;
    srand(time(NULL));
    for(size_t i = 0; i < listSize; i++){
        int numRand = (int)rand();
        listaNueva1.push_back(numRand % (listSize));
        listaNueva2.push_back(numRand % (listSize));
    }
    printVector(listaNueva1);
    cout <<endl;
    SelectionSort<int> selectionsort(listaNueva1);
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    vector<int> Ovector = selectionsort.sort();
    STOP_TIMING(t1);
    SHOW_TIMING(t1, "tiempo de procesado con Selection Sort");
    printVector(Ovector);
    cout <<endl;    
    BubbleSort<int> bubblesort(listaNueva2);
    DECLARE_TIMING(t2);
    START_TIMING(t2);
    vector<int> Ovector2 = bubblesort.sort();
    STOP_TIMING(t2);
    SHOW_TIMING(t2, "tiempo de procesado con Bubble Sort");
    printVector(Ovector2); 





}