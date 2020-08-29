#include <iostream>
using namespace std;

int euclideanAlgorithm(int num1, int num2){
    int largestNumber, smallestNumber, remeinder;
    if(num1 > num2){
        largestNumber = num1;
        smallestNumber = num2;
    }
    else{
        largestNumber = num1;
        smallestNumber = num2;
    }
    remeinder = largestNumber % smallestNumber;
    if(remeinder != 0){
        return(euclideanAlgorithm(largestNumber,remeinder));
    }
    else{
        return(smallestNumber);
    }

    return 0;
}

int main(){
    int N1 = 1785, N2= 546;
    cout << euclideanAlgorithm(N1,N2) <<endl;

}