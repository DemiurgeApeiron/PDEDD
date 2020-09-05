#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> lista= {1,2,3,4,5};
    vector<int> v2 = vector<int>(lista.begin() + 2, lista.end()); 
    for(size_t i = 0; i < v2.size(); i++){
        cout << v2[i] << ", ";
    }
    
}