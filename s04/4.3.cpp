#include <iostream>

using namespace std; // g++ ./s04/4.3.cpp -o main

// int arr[1000000] = {0};

int main(){
    int n = 10'000'000;
    double *ptr = new double[n]; // new - get memory separate 
    for (int i = 0; i<n; ++i){
        ptr[i] = i;
    }
    // for (int i = 0; i<n; i+=10'000){
    //     cout<<ptr[i]<<endl;
    // } // lost 8*10^7 bytes, no clearing
    cout<<ptr<<' '<<&ptr<<' '<<&n<<endl;
    delete[] ptr;
    ptr = nullptr;
    ptr = new double;
    *ptr = 12.234;
    cout<<*ptr<<' '<<ptr[0]<<' '<<*(ptr+0)<<endl;
    delete[] ptr;
    // cout<<nullptr<<' '<<ptr<<endl; // should work??
    ptr = nullptr; // double delete - not good
    delete[] ptr;
    for (int i = 0; i<10; ++i){
        ptr = new double[10]; // not good - no memory freeing
        //...
    }
    delete[] ptr; // lost 720 bytes, deletes only after last attempt

    return 0;
}