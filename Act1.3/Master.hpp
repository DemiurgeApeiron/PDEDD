#include <iostream>
#include <vector>
#include "Puerto.hpp"
#include "HostName.hpp"
#include "IP.hpp"
#include "Fecha.hpp"
#include "Hora.hpp"
using namespace std;
#pragma once

template <class T>
class Master{
protected:
    vector<vector <DataBase<T>*> > lista;
    bool dayCond(T &a, T &b);
    bool horaCond(T &a, T &b);
    bool minCond(T &a, T &b);

public:
    Master()=default;
    ~Master();
    void addRegister(std::vector<T> &_lista);
    vector<T> sortByTime();
    vector<T> sort(bool (*compare)(T &a, T B));
    int numeroDeRegistros(){return(lista.size());}
    void Display(int resp);

};


template <class T>
void Master<T>::addRegister(vector<T> &_lista){
    vector<DataBase<T>*> v;
    v.push_back(new Fecha(_lista[0]));
    v.push_back(new Hora(_lista[1]));
    v.push_back(new IP(_lista[2]));
    v.push_back(new Puerto(_lista[3]));
    v.push_back(new HostName(_lista[4]));
    v.push_back(new IP(_lista[5]));
    v.push_back(new Puerto(_lista[6]));
    v.push_back(new HostName(_lista[7]));
    lista.push_back(v);
}
template <class T>
Master<T>::~Master(){
    for(size_t i = 0; i < lista.size();i++){
        for(size_t j = 0; j < lista.size();j++){
            delete(lista[i][j]);
        }
    }
}

template <class T>
vector<T> Master<T>:: sort(bool (*compare)(T &a, T B)){
    for(size_t i = 0; i < lista.size()-1;i++){
        size_t min = i;
        for(size_t j = i+1; j < lista.size();j++){
            if((*compare)(lista[j],lista[min])){
                min = j;
            }
        }
        T temp = lista[i];
        lista[i] = lista[min];
        lista[min] = temp;
    }
}

template <class T>
vector<T> Master<T>:: sortByTime(){
    for(size_t i = 0; i < lista.size()-1;i++){
        size_t min = i;
        for(size_t j = i+1; j < lista.size();j++){
            if((lista[j][0]->getAño() == lista[min][0].getAño()) && (lista[j][0].getMes() == lista[min][0].getMes()) && (lista[j][0].getDia() == lista[min][0].getDia())){
                if(horaCond(lista[j],lista[min])){
                    min = j;
                }
            }
            else if(dayCond(lista[j],lista[min])){
                min = j;
            }
        }
        T temp = lista[i];
        lista[i] = lista[min];
        lista[min] = temp;
    }
}

template <class T>
bool Master<T>::dayCond(T &a, T &b){
    if(a[0].getAño() < b[0].getAño()){
        return(true);
    }
    else if((a[0].getAño() == b[0].getAño()) && (a[0].getMes() < b[0].getMes())){
        return(true);
    }
    else if((a[0].getAño() == b[0].getAño()) && (a[0].getMes() == b[0].getMes()) && (a[0].getDia() < b[0].getDia())){
        return(true);
    }
    else
    {
        return(false);
    }
}

template <class T>
bool Master<T>::horaCond(T &a, T &b){
    if(a[1].getHora() < b[1].getHora()){
        return(true);
    }
    else if((a[1].getHora() == b[1].getHora()) && (a[1].getMin() < b[1].getMin())){
        return(true);
    }
    else if((a[1].getHora() == b[1].getHora()) && (a[1].getMin() == b[1].getMin()) && (a[1].getSec() < b[1].getSec())){
        return(true);
    }
    else
    {
        return(false);
    }
}
template <class T>
void Master<T>::Display(int resp){
    size_t size;
    if(resp==0){
        size = lista.size();
    }
    else
    {
        size = resp;
    }
    for(size_t i = 0; i < lista.size(); i++){
        Fecha<T>* tempFecha = dynamic_cast<Fecha<T>*>(lista[i][0]);
        Hora<T>* tempHora = dynamic_cast<Hora<T>*>(lista[i][1]);
        IP<T>* tempIP = dynamic_cast<IP<T>*>(lista[i][2]);
        Puerto<T>* tempPuerto = dynamic_cast<Puerto<T>*>(lista[i][3]);
        HostName<T>* tempHost = dynamic_cast<HostName<T>*>(lista[i][4]);
        IP<T>* tempIPD = dynamic_cast<IP<T>*>(lista[i][5]);
        Puerto<T>* tempPuertoD = dynamic_cast<Puerto<T>*>(lista[i][6]);
        HostName<T>* tempHostD = dynamic_cast<HostName<T>*>(lista[i][7]);
        
        cout<< tempFecha->display() << ", " << tempHora->display() << ", " << tempIP->display() << ", " << "tempPuerto->display()" << ", " << tempHost->display() << ", " << tempIPD->display() << ", " << "tempPuertoD->display()" << ", " << tempHostD->display() <<endl;
        
    }
    

}
