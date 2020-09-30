#include <iostream>
using namespace std;
int factorial(int n){
    if (n<0){
        throw "illegal negative number";
    }
    if(n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main(){
    int numero;
    cout << "number for factorial" << endl;
    cin >> numero;

    cout << factorial(numero) <<endl;
}


