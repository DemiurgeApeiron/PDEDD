#include <iostream>
using namespace std;
#include <map>
#include <vector>
vector<int> indiceEdificio = {-1,-1};
//este algoritmo recibe dos inputs m y n que son las columnas de la matris luego realiza dos for loops pro separado para que sea 
//O(n+m) por que si es uno dentro de otro seria O(nm)
int getTbuildingA(vector<vector<int> > &E, vector<int> &indiceEdificio){
    vector<int> listaIndice;
    int contadorActual = 0;
    //O(m)
    for(int m = 0; m < E.size()*E[0].size();m++){
        int tamañoM = E[0].size();
        if((m+1)%tamañoM == 0){
            contadorActual++;
        }
        listaIndice.push_back(contadorActual);
    }
    //O(n)
    for(int n = 0; n < E[0].size();n++){
        if(E[listaIndice[n]][n] == 0){
            indiceEdificio[0] = listaIndice[n];
            indiceEdificio[1] = n;
            return 0;
        }
    }
    return 0;
}
//aqui se realiza una busqueda binaria, este algoritmo tiene una complejidad de log(n) ya que como corta el arreglo a la mitad
// por cada recursion es como una exponencial invertidas el cual es el comportamiento de un log base 2, el unico inconbeniente de este 
//algoritmo es que solo funciona con una lista ordenada. Oredenar una lista tendria un costo para todo el programa de + O(n^2).
int busquedaBinaria(vector<int> &lista, int primer, int ultimo){
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
// esta es una busqueda que funciona parecido a una busqueda binaria, pero para solucionar el problema de la busqueda binaria este se bifurca 
//hacia ambos lados por cada recursion, funciona muy similar a un merge sort, por lo cual tiene la misma complejidad de O(nlog(n))
int busquedaArbol(vector<int> lista, int primer, int ultimo){
    if(ultimo < primer){
        return -1;
    }
    int medio = (primer + ultimo)/2;

    if(lista[medio] == 0){
        return medio;
    }
    int izquierda = busquedaArbol(lista, primer, medio-1);
    int derecha = busquedaArbol(lista, medio+1,ultimo);
    if(derecha != -1){
        return derecha;
    }
    else if(izquierda != -1){
        return izquierda;
    }
    else{
        return -1;
    }
    
}

//esta funcion llama a la busqueda binaria que esta adentro de un for loop por lo cual las complegidades se multiplican O(m) * O(log(n)) = O(mlog(n))
int getTbuildingB(vector<vector<int> > &E, vector<int> &indiceEdificio){
    for(int i = 0; i<E.size();i++){
        int tallest;
        tallest = busquedaBinaria(E[i], 0, E[i].size()-1);
        if(tallest != -1){
            indiceEdificio[0] = i;
            indiceEdificio[1] = tallest;
            return 0;
        }
    }
    return 0;
}
//esta funcion llama a la busqueda de arbol que esta adentro de un for loop por lo cual las complegidades se multiplican O(m) * O(nlog(n)) = O(mnlog(n))
int getTbuildingBArbol(vector<vector<int> > &E, vector<int> &indiceEdificio){
    for(int i = 0; i<E.size();i++){
        int tallest;
        tallest = busquedaArbol(E[i], 0, E[i].size()-1);
        if(tallest != -1){
            indiceEdificio[0] = i;
            indiceEdificio[1] = tallest;
            return 0;
        }
        
    }
    return 0;
}

int main(){
    vector<vector<int> > matris{{1, 1, 1, 0, 1, 1}, 
                               {1, 1, 0, 0, 0, 1}, 
                               {0, 1, 0, 0, 0, 1},
                               {0, 1, 0, 0, 0, 1},
                               {0, 0, 0, 0, 0, 1}}; 
    getTbuildingA(matris, indiceEdificio);
    cout << "el edificio mas alto encontrado con O(m+n) esta en: "<< indiceEdificio[0] << " " << indiceEdificio[1] << endl;
    getTbuildingB(matris, indiceEdificio);
    cout << "el edificio mas alto encontrado con O(m log n) esta en: "<< indiceEdificio[0] << " " << indiceEdificio[1] << endl;
    getTbuildingBArbol(matris, indiceEdificio);
    cout << "el edificio mas alto encontrado con O(mn log n) esta en: "<< indiceEdificio[0] << " " << indiceEdificio[1] << endl;
    
}
