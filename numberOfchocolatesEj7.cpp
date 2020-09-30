#include <iostream>
using namespace std;

int numberOfChocolates(int money, int price, int Pwrap, int NofWraps, int NofChocolates){
    if(money < price && NofWraps < Pwrap){
        return NofChocolates;
    }
    if(money>=price){
        money -= price;
        NofWraps ++;
        NofChocolates ++;
    }
    else if(NofWraps>=Pwrap){
        NofChocolates ++;
        NofWraps -= Pwrap;
        NofWraps ++;
    }
    cout << "Nw " << NofWraps << " " << "M " << money << " NC " << NofChocolates << endl;
    return(numberOfChocolates(money, price, Pwrap, NofWraps, NofChocolates));
}
int main(){
    int money = 15,price = 1, Pwrap = 3,NofWraps = 0,NofChocolates = 0;
    cout<< numberOfChocolates(money, price, Pwrap, NofWraps, NofChocolates) << endl;
}