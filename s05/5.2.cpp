#include <iostream>
#include <utility>

using namespace std;


void quick(int *arr, int l, int r, int size){
    int op = arr[(l+r)/2];
    while (l<r){
        while (arr[l]<arr[op]){
            ++l;
        }
        while (arr[r]<arr[op]){
            --r;
        }
        if(l<r){
            swap(arr[l], arr[r]);
        }
        quick(arr, 0, l, l+1);
        quick(arr, l+1, size-1, size-1-l);
        
    }
}

int main(){
    //veocity of n particles
    double *vx = new double[1000];
    double *vy = new double[1000];
    double *v = new double[1000][2];
    //v[i particle][i direction]
    double **v2d = new double*[1000];
    for (size_t i = 0; i<1000; ++i){
        v2d[i] = new double[2];
    }
    return 0;
}