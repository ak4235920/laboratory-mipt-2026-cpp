#include <iostream>

using namespace std;

#ifndef N
#define N 10
#endif

void print(int arr[]){
    for (int i = 0; i<N; ++i){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void assign(int arr[]){
    for (int i = 0; i<N; ++i){
        arr[i] = i;
    }
}

void swap(int& l, int& r){
    int t = l;
    l=r;
    r=t;
}

int main(){
    int arr[N] = {0};
    float f = 1.14;
    double d = 2.2225;
    assign(arr);
    swap(arr[2], arr[5]);
    print (arr);
    cout<<&d<<' '<<&f<<endl;
    return 0;
}