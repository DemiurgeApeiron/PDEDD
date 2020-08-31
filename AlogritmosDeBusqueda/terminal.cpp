#include <iostream>
#include "BusqudasE.hpp"
#include "mytimer.h"
using namespace std;
template <class T>
T program(T i){
    int numeroAbuscar = 10000;
    BusqudasE<int> busquedas(i);
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    cout << "indice en el que se encuentra con busqueda secuencial: " <<busquedas.BusquedaSO(numeroAbuscar) << endl;
    STOP_TIMING(t1);
    //busquedas.displayLista();
    SHOW_TIMING(t1, "tiempo de procesado");

    cout<<endl;
    busquedas.OrdenarLista();
    DECLARE_TIMING(t2);
    START_TIMING(t2);
    cout << "indice en el que se encuentra con busqueda ordenada: " <<busquedas.BusquedaSO2(numeroAbuscar) << endl;
    STOP_TIMING(t2);
    //busquedas.displayLista();
    SHOW_TIMING(t2, "tiempo de procesado");

    cout<<endl;

    DECLARE_TIMING(t3);
    START_TIMING(t3);
    cout << "indice en el que se encuentra con busqueda ordenada 2: " <<busquedas.BusquedaSO3(numeroAbuscar) << endl;
    STOP_TIMING(t3);
    //busquedas.displayLista();
    SHOW_TIMING(t3, "tiempo de procesado");

    cout<<endl;

    DECLARE_TIMING(t4);
    START_TIMING(t4);
    cout << "indice en el que se encuentra con busqueda binaria: " <<busquedas.BusquedaBinaria(numeroAbuscar) << endl;
    STOP_TIMING(t4);
    //busquedas.displayLista();
    SHOW_TIMING(t4, "tiempo de procesado");
}

int main(){
    int i = 100000;
    program(i);
}