#include <iostream>
using namespace std;
#include <vector>

vector<int> ordenIda(vector<int> lista, int iActual, int iFuturo, int vActual, int vFuturo, vector<int> memorisacion){
    if(iActual == lista.size()-1){
        cout<< "h1" <<endl;
        memorisacion.push_back(vActual);
        for(int i =0; i<memorisacion.size();i++){
        cout << memorisacion[i] <<endl;
        }
        return memorisacion;
    }
    else{
        cout<< "h2" <<endl;
        if(vActual > vFuturo){
            memorisacion.push_back(lista[iFuturo]);
        }
        else{
            memorisacion.push_back(lista[iActual]);
            vActual = vFuturo;
        }
        ordenIda(lista,iFuturo,iFuturo+1, vActual, lista[iFuturo+1], memorisacion);
    }

}
vector<int> ordenRegreso(vector<int> lista, int iActual, int iFuturo, int vActual, int vFuturo, vector<int> memorisacion){
    int x = 0;
    if(iActual*-1 == lista.size()){
        cout<< "h1" <<endl;
        memorisacion.push_back(lista[0]);
        for(int i =0; i<memorisacion.size();i++){
        cout << memorisacion[i] <<endl;
        }
        x = 1;
        
    }
    else{
        cout<< "h2" <<endl;
        if(vActual > vFuturo){
            memorisacion.push_back(lista[iFuturo]);
        }
        else{
            memorisacion.push_back(lista[iActual]);
            vActual = vFuturo;
        }
        ordenRegreso(lista,iFuturo,iFuturo-1, vActual, lista[iFuturo-1], memorisacion);
    }
    if(x == 1){
        cout << "pppp" <<endl; 
        return memorisacion;
    }
    return memorisacion;
    
}
vector<int> memri(){
    vector<int> mem{1,2,3,4};
    return mem;
}

/*vector<vector<int> > ordenador(vector<vector<int> > &lista, vector<int> &indiceEdificio){
    vector<vector<int> > listaOrdenada;
    for(int i = 0; i<lista.size(); i++){
        int vActual;
        int vFuturo;
        for(int j = 0; j<lista[i].size();j++){
            if(lista[i][j] == 0 && indiceEdificio[0] > i){
                indiceEdificio[0] = i;
                indiceEdificio[1] = j;
            }
            
        }
        for(int j = -1; j>=lista[i].size()*-1;j--){
            if(lista[i][j] == 0 && indiceEdificio[0] > i){
                indiceEdificio[0] = i;
                indiceEdificio[1] = j;
            }
        }
        
    }
}*/

int main(){
    vector<int> lista{0,0,0,1};
    vector<int> mem;
    mem = ordenRegreso(lista, -1, -2, lista[-1], lista[-2], mem);
    //mem = memri();

    for(int i =0; i<mem.size();i++){
        cout << "h10" << endl;
        cout << mem[i] <<endl;
    }
    
}