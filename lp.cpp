#include <iostream>
using namespace std;

template <size_t n, size_t m>
int tallestBuilding( int (&matrix)[n][m] ){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0) return j;
        }
    }
}

int binarySearch(int arr[], int first, int last){
    int med = (first + last)/2;
    if( last < first ) return -1;
    if( arr[med] == 0 ) return med;
    
    int left = binarySearch(arr, first, med-1);
    int right = binarySearch(arr, first+1, med);
    
    if(left!=-1) return left;
    if(right!=-1) return right;

}


template <size_t n, size_t m>
int tallestBuildingBinarySearch( int (&matrix)[n][m] ){
    for(int i = 0; i<n; i++){
        int highest = binarySearch(matrix[i], 0, m);
        if( highest != -1 ){
            cout << i  << " " << highest <<endl;
        } 
    }
}

int main(){
    int city[5][6] = {
        {1, 1, 1, 0, 1, 1},
        {1, 1, 0, 0, 0, 1}, 
        {0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1}
    };
    cout<<"The tallest building is... "<<tallestBuilding(city)<<endl; 
    cout<<"The tallest building is... "<<tallestBuildingBinarySearch(city)<<endl; 
    // cout<<binarySearch(city[0], 0, 6)<<endl;
}