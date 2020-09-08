/* 
programa para ordenar y buscar un numero en un vector midiend los tiempos
javier alejandro martinez noe
7/9/20
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "mytimer.h"
#include <algorithm>
#include "BubbleSort.hpp"
#include "IncertionSort.hpp"
#include "QuickSort.hpp"
#include "BusqudasE.hpp"
using namespace std;

//esta funcion imprime un vector que recibe de tipo T 
template<class T>
void printVector(vector<T> &lista){
    for(size_t i = 0; i < lista.size(); i++){
        cout << lista[i] << ", ";
    }
    cout <<endl;
}

//esta funcion hace una busqueda secuencial de un vector que recibe de tipo T intanciando un objeto de la clase busquedasE
//y miden el tiempo de ejecuccion
template<class T>
int busquedaSecuencial(int numeroAbuscar, vector<T> &lista){
    BusqudasE<int> busquedas;
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    cout << "indice en el que se encuentra con busqueda secuencial: " <<busquedas.BusquedaSO(numeroAbuscar, lista) << endl;
    STOP_TIMING(t1);
    SHOW_TIMING(t1, "tiempo de procesado");
    cout<<endl;
}
//esta funcion hace una busqueda binaria de un vector que recibe de tipo T intanciando un objeto de la clase busquedasE
// y miden el tiempo de ejecuccion
template<class T>
int busquedaBinaria(int numeroAbuscar, vector<T> &lista){
    BusqudasE<int> busquedas;
    DECLARE_TIMING(t4);
    START_TIMING(t4);
    cout << "indice en el que se encuentra con busqueda binaria: " <<busquedas.BusquedaBinaria(numeroAbuscar, lista) << endl;
    STOP_TIMING(t4);
    SHOW_TIMING(t4, "tiempo de procesado");
    cout<<endl;
}

//esta funcion hace un ordenamiento por IncertionSort de un vector que recibe de tipo T intanciando un objeto de la clase IncertionSort
//hereda de la clase padre Sorter y miden el tiempo de ejecuccion
template<class T>
vector<T> ordenamientoIncercion(vector<T> &lista){
    IncertionSort<int> incertionsort(lista);
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    vector<int> Ovector = incertionsort.sort();
    STOP_TIMING(t1);
    SHOW_TIMING(t1, "tiempo de procesado con Incertion Sort");
    printVector(Ovector);
    cout <<endl; 
    return(Ovector);
}
//esta funcion hace un ordenamiento por BubbleSort de un vector que recibe de tipo T intanciando un objeto de la clase BubbleSort
//hereda de la clase padre Sorter y miden el tiempo de ejecuccion
template<class T>
vector<T> ordenamientoBurbuja(vector<T> &lista){
    BubbleSort<int> bubblesort(lista);
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    vector<int> Ovector = bubblesort.sort();
    STOP_TIMING(t1);
    SHOW_TIMING(t1, "tiempo de procesado con Bubble Sort");
    printVector(Ovector);
    cout <<endl; 
    return(Ovector);
}

//esta funcion hace un ordenamiento por QuickSort de un vector que recibe de tipo T intanciando un objeto de la clase QuickSort 
//hereda de la clase padre Sorter y miden el tiempo de ejecuccion
template<class T>
vector<T> ordenamientoQuick(vector<T> &lista){
    QuickSort<int> quicksort(lista);
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    vector<int> Ovector = quicksort.sort();
    STOP_TIMING(t1);
    SHOW_TIMING(t1, "tiempo de procesado con Quick Sort");
    printVector(Ovector);
    cout <<endl; 
    return(Ovector);
}

// esta es la funcion main aqui se genera una lista aleatorea y se realizan preguntas para saver cunatas veces se corre el proceso
//y porque algoritmo se hacen las busquedas y los ordenamientos llamando a sus respectivas funaciones.
int main(){
    int tamñoLista;
    int numeroDeBusquedas;
    vector<int> lista;
    cout << "De que tamaño queres la lista para trabajar"<<endl;
    cin >> tamñoLista;

    srand(time(NULL));
    for(size_t i = 0; i < tamñoLista; i++){
        int numRand = (int)rand();
        lista.push_back(numRand % (tamñoLista));
    }
    cout << "Cuantas veces quieres buscar"<<endl;
    cin >> numeroDeBusquedas;
    for(size_t i = 0; i < numeroDeBusquedas; i++){
        int metodoOrdenar;
        int metodoBusqueda;
        int numeroAbuscar;
        cout << "Por cual metodo quieres ordenar: 1) Bubble sort, 2) Incertion sort, 3) Quick sort."<<endl;
        cin >> metodoOrdenar;
        if(metodoOrdenar == 1){
            lista = ordenamientoBurbuja(lista);
        }
        else if(metodoOrdenar == 2){
            lista = ordenamientoIncercion(lista);
        }
        else if(metodoOrdenar == 3){
            lista = ordenamientoQuick(lista);
        }
        else{
            cout << "that's not a valid number"<<endl;
            break;
        }

        cout << "Que numero quieres busacar"<<endl;
        cin >> numeroAbuscar;
        busquedaSecuencial(numeroAbuscar, lista);
        busquedaBinaria(numeroAbuscar, lista);

    }

}