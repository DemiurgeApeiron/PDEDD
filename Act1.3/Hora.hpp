#include <iostream>
#include <vector>
using namespace std;
#pragma onece;

template <class T>
class Hora{
protected:
    int hora;
    int min;
    int sec;
public:
    Hora(T &_hora);
    ~Hora();
    int getHora(){return hora;}
    int getMin(){return min;}
    int getMin(){return sec;}
};
template <class T>
Hora<T>::Hora(T &_hora){
    vector <T> valores;
    stringstream check1(_hora); 
    string intermediate; 
    while(getline(check1, intermediate, ':')) 
    { 
        valores.push_back(intermediate); 
    }
    this-> hora = valores[0];
    this-> min = valores[1];
    this-> sec = valores[2];
}
template <class T>
Hora<T>::~Hora(){
}