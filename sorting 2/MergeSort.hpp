/* 
clase abstracta para los sorting algorithm
javier alejandro martinez noe
31/9/20
*/
#include <iostream>
#include <vector>
#include <cmath>
#include "Sorter.hpp"
using namespace std;
#pragma onece

template <class T>
class MergeSort : public Sorter<T>{
protected:
    vector<T> merge(vector<T> &l, vector<T> &r);
    vector<T> mergeSort(vector<T> &listaToMege, int primer, int ultimo);
public:
    MergeSort(vector<T> &_lista);
    ~MergeSort();
    vector<T> sort();
    
};
template <class T>
MergeSort<T>::MergeSort(vector<T> &_lista): Sorter<T>(_lista){
}
template <class T>
MergeSort<T>::~MergeSort()
{
}
template <class T>
vector<T> MergeSort<T>::sort(){
    return(mergeSort(this->lista,0,this->lista.size()-1));
}
template <class T>
vector<T> MergeSort<T>::mergeSort(vector<T> &listaToMege, int primer, int ultimo){
    int n = listaToMege.size();
    if(primer < ultimo){
    
        int medio = primer + (ultimo - primer) / 2;

        vector<T> izquierda = mergeSort(listaToMege, primer, medio);
        vector<T> derecha = mergeSort(listaToMege, medio+1,ultimo);

        /*cout <<"iz: ";
        for(size_t i = 0; i<izquierda.size();i++){
            cout << izquierda[i]<< ", " ;
        }
        cout<<endl;
        cout <<"dr: ";
        for(size_t j = 0; j<derecha.size();j++){
            cout << derecha[j]<< ", " ;
        }
        cout<<endl;*/
        return(merge(izquierda,derecha));

    }
    else{
        vector<T> resp;
        if(primer-ultimo !=0){
            //cout <<"a"<<endl;
            resp = vector<T>(listaToMege.begin() + primer, listaToMege.end()- (listaToMege.size()-ultimo)); 
        }
        else if(primer == 0 && ultimo == 0){
            //cout <<"b"<<endl;
            resp = vector<T>(listaToMege.begin(), listaToMege.end()- (listaToMege.size()-1)); 
        }
        else{
            //cout <<"c"<<endl;
            resp = vector<T>(listaToMege.begin() + primer, listaToMege.end()- (listaToMege.size()-ultimo-1));
        }
        //cout << "primer: " << primer << " ultimo: " << ultimo << endl;
        //cout <<"resp: ";
        /*for(size_t j = 0; j<resp.size();j++){
            cout << resp[j]<< ", " ;
        }
        cout<<endl;*/
        return(resp);
    }
}
template <class T>
vector<T> MergeSort<T>::merge(vector<T> &l, vector<T> &r){
    int n = l.size()+r.size() -1;

    int i =0, j = 0;
    vector<T> result;
    result.resize(n);
    //cout <<"size: "<< n<<endl;
    int lastMove;
    for(size_t p = 0; p < n;p++){
        //cout << "p: " << p << " li: "<< l[i] << " rj: "<< r[j] << " i: " << i << " j: " << j << endl;
        if(l[i] < r[j]){
            result[p] = l[i];
            //cout <<"li"<<endl;
            if((i < l.size()-1) || (n == 1)){
                //cout <<"i++"<<endl;
                i++;
            }
            else{
                //cout <<"dime que entra iz"<<endl;
                for(size_t o = p+1; o < result.size(); o++){
                    //cout <<"intputFor lj: "<< r[j] << " en: " << o <<endl;
                    result[o] = r[j];
                    j++;
                }
                lastMove = 1;
                break;
                
            }
            lastMove = 1;
        }
        else{
            result[p] = r[j];
            //cout <<"rj"<<endl;
            if((j < r.size()-1) || (n == 1)){
                //cout <<"j++"<<endl;
                j++;
            }
            else{
                //cout <<"dime que entra der"<<endl;
                for(size_t o = p+1; o < result.size(); o++){
                    //cout <<"intputFor rj: "<< l[i] << " en: " << o <<endl;
                    result[o] = l[i];
                    i++;
                }
                lastMove = 0;
                break;
                
            }
        lastMove = 0;
        }
    }

    if(lastMove == 1){
        result.push_back(r[r.size()-1]);
    }
    else{
        result.push_back(l[l.size()-1]);
    }
    
    /*cout <<"m: ";
    for(size_t j = 0; j<result.size();j++){
        cout << result[j]<< ", " ;
    }
    cout<<endl;*/
    return(result); 
}


