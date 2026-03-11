#include <iostream>
#include <utility>

using namespace std;

unsigned fib(unsigned n){
    if (n<2){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

void quick(int *arr, int l, int r){
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
        quick(arr, , l);
        quick(arr, l+1, );
        
    }
}

int main(){
    cout<<fib(44)<<endl;
    cout<<fib(1)<<endl;
    cout<<fib(0)<<endl;
    unsigned dp[44] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for (size_t i = 2; i<44; ++i){
        dp[i] = dp[i-1] = dp[i-2];
    }
    return 0;
}