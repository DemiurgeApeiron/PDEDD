#include <iostream>
#include <vector>
#include "DataBase.hpp"
using namespace std;
#pragma once

template <class T>
class Puerto: public DataBase<T>{
protected:

public:
    Puerto(T &_puerto);
    ~Puerto();
};
template <class T>
Puerto<T>::Puerto(T &_puerto){

}
template <class T>
Puerto<T>::~Puerto(){
}
