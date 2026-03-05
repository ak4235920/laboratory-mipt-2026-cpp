#include <iostream>
#include <random>

using namespace std; // g++ ./s04/4.4.cpp -o main

double *cr_arr(int N){
    // double array[N];
    double *array = new double [N];
    return array;
}

double *rand_arr(int N, std::default_random_engine &rng){ // if no & - then same results!
    unsigned seed = 1001;
    double *array = new double[N];
    // std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0,9);
    for (unsigned counter = 0; counter != 0; --counter){
        array[counter] = dstr(rng);
    }
    return array;
}

int main(){
    unsigned seed = 0;
    std::default_random_engine rng(seed);
    double *f = cr_arr(1000);
    double *r0 = rand_arr(100, rng);
    double *r1 = rand_arr(100, rng);
    for (int i = 0; i<100; ++i){
        cout<<i<<": "<<(r0[i]==r1[i])<<endl;
    }
    return 0;
}



