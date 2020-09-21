#include <iostream>
#include <vector>
#include "Master.hpp"
using namespace std;

template<class T>
void addRegistro(vector<vector<T>> _registros){
    int resp;
    Master<string> program; 
    for(size_t i = 0; i < _registros.size();i++){
        program.addRegister(_registros[i]);
    }
    cout<<"Espesifica cuantas filas quieres imprimir, 0 = All: "<<endl;
    cin >> resp;
    program.Display(resp);
    cout<< "-----------"<<endl;
    program.sortByTime();
    cout<<"Espesifica cuantas filas quieres imprimir, 0 = All: "<<endl;
    cin >> resp;
    program.Display(resp);
}

int main(){
    vector<vector<string>> regitros;
    vector<string> v1 = {"10-8-2020","9:0:24","10.8.134.118","2668","edward.reto.com","144.238.150.63","993","outlook.com"};
    vector<string> v2 = {"10-8-2020","9:7:43","10.8.134.146","29579","emily.reto.com","174.244.179.200","443","tripadvisor.com"};
    regitros.push_back(v1);
    regitros.push_back(v2);
    addRegistro(regitros);
    
    
}
