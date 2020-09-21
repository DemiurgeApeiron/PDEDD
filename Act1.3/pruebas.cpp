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
    func("s");
} 