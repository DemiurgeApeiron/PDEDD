#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h> 
#include <assert.h> 
#include "Fecha.hpp"

using namespace std; 
template <class T>
void func(T a){
    Fecha<T> fecha("10-8-2020");
    //cout << fecha.getDia() <<endl;
}  

int main() 
{ 
    template <class T>
vector<vector<DataBase<T>*>> Master<T>:: sortByTime(){
    for(size_t i = 0; i < lista.size()-1;i++){
        size_t min = i;
        Fecha<T>* tempFechaA = dynamic_cast<Fecha<T>*>(lista[i][0]);
        Fecha<T>* tempFechaB = dynamic_cast<Fecha<T>*>(lista[min][0]);
        for(size_t j = i+1; j < lista.size();j++){
            if((tempFechaA->getAño() == tempFechaB->getAño()) && (tempFechaA->getMes() == tempFechaB->getMes()) && (tempFechaA->getDia() == tempFechaB->getDia())){
                if(horaCond(lista[j],lista[min])){
                    min = j;
                }
            }
            else if(dayCond(lista[j],lista[min])){
                min = j;
            }
        }
        vector<DataBase<T>*> temp = lista[i];
        lista[i] = lista[min];
        lista[min] = temp;
    }
    return(lista);
}
} 