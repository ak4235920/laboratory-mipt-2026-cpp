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
    int *ptsr = new int[M];
    if (N>M){
        for (unsigned int i = 0; i<M; ++i){
            ptsr[i] = ptr[i];
        }
    } else{
        for (unsigned int i = 0; i<N; ++i){
            ptsr[i] = ptr[i];
        }
        for (unsigned int i = N; i<M; ++i){
            ptsr[i] = 0;
        }
    }
    delete[] ptr;
    ptr = ptsr;
}

void merge(int*& res, int*& ptr0, unsigned int N, int*& ptr1, unsigned int M){
    delete[] res;
    res = new int[M+N];
    for (unsigned int i = 0; i<N; ++i){
        res[i] = ptr0[i];
    }
    for (unsigned int i = 0; i<M; ++i){
        res[i+N] = ptr1[i];
    }
}

void copy_4bytes_to_from(void *dst, void const *src) {
    std::byte *s = reinterpret_cast<std::byte*>(src);
    std::byte *d = reinterpret_cast<std::byte*>(dst);
    for (std::size_t i = 0; i<4; ++i){
        *(d+i) = *(s+i);
    }
}

int main(){
    int *a = new int [3];
    for(int i = 0; i<3; ++i){
        a[i] = i;
    }
    int *b = new int [4];
    for(int i = 0; i<4; ++i){
        b[i] = i+10;
    }
    int *c = new int[1];
    for(int i = 0; i<1; ++i){
        c[i] = i+2;
    }
    merge(c, a, 3, b, 4);
    for (int i = 0; i<7; ++i){
        cout<<c[i]<<endl;
    }
    return 0;
}