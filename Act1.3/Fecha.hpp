#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "DataBase.hpp"
using namespace std;
#pragma once

template <class T>
class Fecha : public DataBase<T>{
protected:
    T fullFecha;
    T año;
    T mes;
    T dia;
public:
    Fecha(T &Fecha);
    ~Fecha();
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAño(){return año;}
    T display(){return fullFecha;}
};
template <class T>
Fecha<T>::Fecha(T &Fecha){
    this->fullFecha= Fecha;
    vector <string> valores;
    stringstream check1(Fecha); 
    string intermediate; 

    while(getline(check1, intermediate, '-')) 
    { 
        valores.push_back(intermediate); 
    } 

    this-> dia = valores[0];
    this-> mes = valores[1];
    this-> año = valores[2];
}
template <class T>
Fecha<T>::~Fecha(){
}
