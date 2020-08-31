#include "BusquedasE.h"

template<class T>
BusqudasE<T>::BusqudasE(){

}
template<class T>
BusqudasE<T>::~BusqudasE(){

}
template<class T>
vector<T> BusqudasE<T> :: oredenador(vector<T> &lista){

}
template<class T>
T BusqudasE<T> :: BusquedaSO(vector<T> &lista, T K){
    T respuesta = -1;
    for(int i = 0; i < lista.size(); i++){
        if(K == lista[i]){
            respuesta = i;
            break;
        }
    }
    return respuesta;
}
template<class T>
T BusqudasE<T> :: BusquedaSO2(vector<T> &lista, T K){
    T respuesta = -1;
    for(int i = 0; i < lista.size(); i++){
        if(K == lista[i]){
            respuesta = i;
            break;
        }
    }
    return respuesta;
}
template<class T>
T BusqudasE<T> :: BusquedaSO3(vector<T> &lista, T K){
    return 0;
}
template<class T>
T BusqudasE<T> :: BusquedaBinaria(vector<T> &lista, T primer, T ultimo){
    int indice;
    if(ultimo < primer){
        indice = -1;
    }
    else{
        int medio = (primer + ultimo)/2;
        if(lista[medio] == 0){
            indice = medio;
        }
        else if(lista[medio] > 0){
            indice = busquedaBinaria(lista, primer, medio-1);
        }
        else{
            indice = busquedaBinaria(lista, medio+1,ultimo);
        }
    }
    return indice;
}
