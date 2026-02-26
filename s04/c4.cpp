#include <iostream>

using namespace std;

int* give_N_elements(unsigned int N, int value){
    int *arr = new int[N];
    for (unsigned int i = 0; i<N; ++i){
        arr[i] = value;
    }
    return arr;
}

int* take_N_elements(int* ptr){
    delete[] ptr;
    return nullptr;
}

void swap_arr(int*& ptr0, int*& ptr1){
    int *copy = ptr0;
    ptr0 = ptr1;
    ptr1 = copy;
}

void reshape_arr(int*& ptr, unsigned int N, unsigned int M){
    if (N>M){
        for (int = 0; i<N-M; ++i){
            delete ptr[i];
        }
    } else{
        new int
    }
}

int main(){
    int *a = new int [3];
    for(int i = 0; i<3; ++i){
        a[i] = i;
    }
    int *b = new int [4];
    for(int i = 0; i<4; ++i){
        b[i] = i+3;
    }
    swap_arr(a, b);
    for (int i = 0; i<3; ++i){
        cout<<b[i]<<endl;
    }
    return 0;
}