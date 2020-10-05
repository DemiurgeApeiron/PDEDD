//metodo de ordenamiento Quick Sort
template <class T>
void Master<T>::quickSort(vector<ADT<T>>  &list, int low, int high, bool (Master<T>::*compare)(ADT<T> &a, ADT<T> &b)){
    if(low < high){
        int piv = partition(list,low, high, (compare));
        quickSort(list,low, piv-1, (compare));
        quickSort(list,piv+1, high, (compare));
    }
}
//metodo que trbaja en conjunto con quicksort y hace las comparaciones 
template <class T>
int Master<T>::partition(vector<ADT<T>> &list, int low, int high, bool (Master<T>::*compare)(ADT<T> &a, ADT<T> &b)){
    ADT<T> pivote = lista[high];
    int i = low-1;

    for (int j = low; j < high; j++){
        if((this->*compare)(lista[j],pivote)){
            i++;
            ADT<T> temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    ADT<T> temp = list[i+1];
    list[i+1] = list[high];
    list[high] = temp;
    return i + 1;
}