/* 
programa para sumar un numero con diferentes niveles de complejidad
javier alejandro martinez noe
12/11/19
*/
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
//funcion para sumar un numero del 1 al n de forma iteraiva el input es un numero entero n y el output es una variable "respuesta"
int sumaIterativa(int n){
    int respuesta;
    for(int i = 1; i <= n; i++){
        respuesta+=i;
    }
    return respuesta;
}
//funcion para sumar un numero del 1 al n de forma recursiva el input es un numero entero n
int sumaRecursiva(int n){
    if(n<=0){
        return 0;
    }
    else{
        return n + sumaRecursiva(n-1);
    }
}
//funcion para sumar un numero del 1 al n de forma directa el input es un numero entero n
int sumaDirecta(int n){
    return (n*(n+1)/2);
}

int main(){
    using namespace std::this_thread; 
    using namespace std::chrono;

    sleep_for(nanoseconds(10));
    cout << "suma iterativa con 3: " << sumaIterativa(3) << endl;

    sleep_for(nanoseconds(10));
    cout << "suma iterativa con 4: " << sumaIterativa(4) << endl;

    sleep_for(nanoseconds(10));
    cout << "suma iterativa con 5: " << sumaIterativa(5) << endl;

    sleep_for(nanoseconds(10));
    cout << "suma iterativa con 6: " << sumaIterativa(6) << endl;

    sleep_for(nanoseconds(10));
    cout << "suma recursiva con 3: " << sumaRecursiva(3) << endl;

    sleep_for(nanoseconds(10));
    cout << "suma recursiva con 4: " << sumaRecursiva(4) << endl;

    sleep_for(nanoseconds(10));
    cout << "suma recursiva con 5: " << sumaRecursiva(5) << endl;

    sleep_for(nanoseconds(10));
    cout << "suma recursiva con 6: " << sumaRecursiva(6) << endl;

    sleep_for(nanoseconds(10));
    cout << "suma directa con 3: " << sumaDirecta(3) << endl;

    sleep_for(nanoseconds(10));
    cout << "suma directa con 4: " << sumaDirecta(4) << endl;

    sleep_for(nanoseconds(10));
    cout << "suma directa con 5: " << sumaDirecta(5) << endl;

    sleep_for(nanoseconds(10));
    cout << "suma directa con 6: " << sumaDirecta(6) << endl;
}