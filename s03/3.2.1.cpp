#include <iostream>

using namespace std;

#ifndef N
#define N 10
#endif

int main(){
    int arr[N] = {0};
    for (int i = 0; i<N; ++i){
        cout<<arr[i]<<endl;
    }
    return 0;
}