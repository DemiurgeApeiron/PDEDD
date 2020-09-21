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
    bool dayCond(vector<DataBase<T>*> &a, vector<DataBase<T>*> &b);
    bool horaCond(vector<DataBase<T>*> &a, vector<DataBase<T>*> &b);

public:
    Master()=default;
    ~Master();
    void addRegister(std::vector<T> &_lista);
    vector<vector<DataBase<T>*>>  sortByTime();
    int numeroDeRegistros(){return lista.size();}
    void Display(int resp);

};

template <class T>
Master<T>::~Master(){
    for(size_t i = 0; i < lista.size();i++){
        for(size_t j = 0; j < lista.size();j++){
            delete(lista[i][j]);
        }
    }
}

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

template <class T>
bool Master<T>::dayCond(vector<DataBase<T>*> &a, vector<DataBase<T>*> &b){
    Fecha<T>* tempFechaA = dynamic_cast<Fecha<T>*>(a[0]);
    Fecha<T>* tempFechaB = dynamic_cast<Fecha<T>*>(b[0]);
    if(tempFechaA->getAño() < tempFechaB->getAño()){
        return(true);
    }
    else if((tempFechaA->getAño() == tempFechaB->getAño()) && (tempFechaA->getMes() < tempFechaB->getMes())){
        return(true);
    }
    else if((tempFechaA->getAño() == tempFechaB->getAño()) && (tempFechaA->getMes() == tempFechaB->getMes()) && (tempFechaA->getDia() < tempFechaB->getDia())){
        return(true);
    }
    else
    {
        return(false);
    }
}

template <class T>
bool Master<T>::horaCond(vector<DataBase<T>*> &a, vector<DataBase<T>*> &b){
    Hora<T>* tempHoraA = dynamic_cast<Hora<T>*>(a[1]);
    Hora<T>* tempHoraB = dynamic_cast<Hora<T>*>(b[1]);
    if(tempHoraA->getHora() < tempHoraB->getHora()){
        return(true);
    }
    else if((tempHoraA->getHora() == tempHoraB->getHora()) && (tempHoraA->getMin() < tempHoraB->getMin())){
        return(true);
    }
    else if((tempHoraA->getHora() == tempHoraB->getHora()) && (tempHoraA->getMin() == tempHoraB->getMin()) && (tempHoraA->getSec() < tempHoraB->getSec())){
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
