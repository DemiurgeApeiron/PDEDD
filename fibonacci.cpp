#include <iostream>
using namespace std;
#include <map>
#include <vector>



int fibonacci(int n){
    if(n<0){
        throw "iligal number";
    }
    if(n<2){
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacciV2(int n, map<int, int> memory){
    if(n<0){
        throw "iligal number";
    }
    if(n<2){
        return n;
    }
    if(memory[n] != 0){
        return memory[n];
    }
    
    memory[n]= fibonacciV2(n-1,memory) + fibonacciV2(n-2,memory);

    return fibonacciV2(n-1, memory) + fibonacciV2(n-2, memory);
}

int fibonacciV3(int n){
    int x = 0, y = 1, number;

    for(int i = 1; i<n; i++){
        number = x+y;
        x = y;
        y = number;
    }
    return(number);
}

int main(){
    int number;
    cout << "enter a index for fibonacci" << endl;
    cin >> number;
    map<int, int> memory;
    cout << "normal: " << fibonacci(number) << endl;
    cout << "memorization: " << fibonacciV2(number, memory) << endl;
    cout << "iterative: " << fibonacciV3(number) << endl;
    
}