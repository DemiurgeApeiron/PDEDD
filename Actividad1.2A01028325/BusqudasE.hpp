#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>
class BusqudasE {
    private:
        int indiceAencontrar;
        vector<T> listaNueva;
        vector<T> listaOrdenada;
        vector<T> oredenador(vector<T> lista);
    public:
        BusqudasE();
        ~BusqudasE();
        
        T BusquedaSO(T K, vector<T> &lista);
        T BusquedaSO2(T K, vector<T> &lista);
        T BusquedaSO3(T K, vector<T> &lista);
        T busquedaBinaria(T primer, T ultimo, T K);
        T BusquedaBinaria(T K, vector<T> &lista);
        void OrdenarLista(){oredenador(listaNueva);}
        void displayLista();
};

template <class T>
BusqudasE<T> :: BusqudasE(){

}
template<class T>
BusqudasE<T>::~BusqudasE(){
}
template<class T>
vector<T> BusqudasE<T> :: oredenador(vector<T> lista){

}
template<class T>
T BusqudasE<T> :: BusquedaSO(T K, vector<T> &lista){
    listaOrdenada = lista;
    T respuesta = -1;

    for(int i = 0; i < listaOrdenada.size(); i++){
        if(K == listaOrdenada[i]){
            respuesta = i;
            break;
        }
    }
    return respuesta;
}
template<class T>
T BusqudasE<T> :: BusquedaSO2(T K, vector<T> &lista){
    listaOrdenada = lista;
    T respuesta = -1;
    for(int i = 0; i < listaOrdenada.size(); i++){
        if(listaOrdenada[i] > K){
            break;
        }
        if(K == listaOrdenada[i]){
            respuesta = i;
            break;
        }
    }
    return respuesta;
}
template<class T>
T BusqudasE<T> :: BusquedaSO3(T K, vector<T> &lista){
    listaOrdenada = lista;
    T respuesta = -1;
    for(int i = 0; i < listaOrdenada.size(); i += 2){
        if(i == listaOrdenada.size()-1){
            break;
        }
        if(listaOrdenada[i] >= K){
            if(K == listaOrdenada[i-1]){
                respuesta = i-1;
            }
            if(K == listaOrdenada[i]){
                respuesta = i;
                break;
            }
            else{
                break;
            }
        }
        
    }
    return respuesta;
}
template<class T>
T BusqudasE<T> ::BusquedaBinaria(T K, vector<T> &lista){
    listaOrdenada = lista;
    return busquedaBinaria(0,listaOrdenada.size()-1,K);
}
template<class T>
T BusqudasE<T> :: busquedaBinaria(T primer, T ultimo, T K){
    int indice;
    if(ultimo < primer){
        indice = -1;
    }
    else{
        int medio = (primer + ultimo)/2;
        if(listaOrdenada[medio] == K){
            indice = medio;
        }
        else if(listaOrdenada[medio] > K){
            indice = busquedaBinaria(primer, medio-1, K);
        }
        else{
            indice = busquedaBinaria(medio+1,ultimo, K);
        }
    }
    return indice;
}

template<class T>
void BusqudasE<T> ::displayLista(){
    cout << "-------lista usada--------"<<endl;
    for(int i = 0; i < listaOrdenada.size(); i++){
        cout << listaOrdenada[i];
        cout << ", ";
    }
    cout << "\n--------------------------"<<endl;
}




