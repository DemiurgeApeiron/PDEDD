#include <iostream>
#include <vector>
using namespace std;

vector<int> sortBack(vector<int> list, int iActual, int iFuture, int vActual, int vFuture, vector<int> memorization){
    if(iActual*-1 == list.size()){
        memorization.push_back(list[0]);

        return memorization;
    }
    else{
        if(vActual > vFuture){
            memorization.push_back(list[iFuture]);
        }
        else{
            memorization.push_back(list[iActual]);
            vActual = vFuture;
        }
        sortBack(list,iFuture,iFuture-1, vActual, list[iFuture-1], memorization);
    }
    vector<int> R0 = {-1,-1,-1,-1};
    return R0;
}

vector<int> sortForwards(vector<int> list, int iActual, int iFuture, int vActual, int vFuture, vector<int> memorization){
    if(iActual == list.size()-1){
        
        memorization.push_back(vActual);
        return memorization;
        
    }
    else{
        if(vActual > vFuture){
            memorization.push_back(list[iFuture]);
        }
        else{
            memorization.push_back(list[iActual]);
            vActual = vFuture;
        }
        sortForwards(list,iFuture,iFuture+1, vActual, list[iFuture+1], memorization);
    }
    vector<int> R0 = {-1,-1,-1,-1};
    return R0;
}

vector<int> oredenador(vector<int> &list){
    vector<int> mem;
    sortBack(list, -1, -2, list[-1], list[-2], mem);
    sortForwards(list, 0, 1, list[0], list[1], mem);
    return list;

}

int main(){
    vector<int> list = {9,1,6,2,5,1,7};
    vector<int> listOrder = oredenador(list);
    for(int i = 0; i < listOrder.size(); i++){
        cout << listOrder[i] << endl;
    }
}