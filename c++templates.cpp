#include <iostream>
using namespace std;

template <class T>
T GetMax(T a, T b){
    return(a>b ? a : b);
}

int main(){
    int i = 5, j = 3;
    float k = 2.34, l = 1.5779;
    cout << GetMax(i,j) <<endl;
    cout << GetMax(k,l) <<endl;
    return 0;
}
