#include <iostream>
#include <chrono>
#include <utility>
#include <fstream>
#include <random>
#include <algorithm>

using namespace std;

int search(int arr[], int key, int N){
    for (int i = 0; i<N; ++i){
        if (arr[i]==key){
            return i;
        }
    }
    return -1;
}

void str_A(int arr[], int key, int N){
    int found = search(arr, key, N);
    if (found>0){
        swap(arr[0], arr[found]);
    }
}

void str_B(int arr[], int key, int N){
    int found = search(arr, key, N);
    if (found<1) {
        return;
    }
    swap(arr[found-1], arr[found]);
}

void str_C(int arr[], int count[], int key, int N){
    int found = search(arr, key, N);
    if (found==-1){
        return;
    }
    ++count[found];
    while ((found>0) and (count[found-1]<count[found])){
        swap(arr[found], arr[found-1]);
        swap(count[found], count[found-1]);
        --found;
    }
}

int main() {
    int size[] = {500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    // int iterations[] = {1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
    ofstream outputFile("output_tres_rnd.txt");
    int n1 = 10000;
    for (int i = 0; i<8; ++i){
        random_device rd;
        unsigned seed = rd();
        int *arr = new int [size[i]];
        default_random_engine rng(seed);
        uniform_int_distribution<unsigned> dstr (0 ,1e+8);
        for (unsigned counter = 0; counter<size[i]; ++counter){
            arr[counter] = dstr(rng);
        }
        uniform_int_distribution<int> dist(0, 1e+8);
        int* keys = new int[n1];
        for (int j = 0; j < n1; ++j) {
            keys[j] = dist(rng);
        }
        int *count = new int[size[i]];
        for (int j = 0; j<size[i]; ++j){
            count[j] = 0;
        }
        auto begin = chrono :: steady_clock ::now();
        for (unsigned cnt = 0; cnt <n1; ++cnt){
            str_C (arr, count, keys[cnt], size[i]);
        }
        auto end = chrono :: steady_clock ::now();
        auto time_span = chrono :: duration_cast<chrono :: nanoseconds >(end - begin);
        outputFile<<time_span.count()<<' ';
        delete[] arr;
        delete[] keys;
        delete[] count;
    }
    outputFile<<'\n';
    for (int i = 0; i<8; ++i){
        random_device rd;
        unsigned seed = rd();
        int *arr = new int [size[i]];
        default_random_engine rng(seed);
        uniform_int_distribution<unsigned> dstr (0 ,1e+8);
        for (unsigned counter = 0; counter<size[i]; ++counter){
            arr[counter] = dstr(rng);
        }
        uniform_int_distribution<int> dist(0, 1e+8);
        int* keys = new int[n1];
        for (int j = 0; j < n1; ++j) {
            keys[j] = dist(rng);
        }
        auto begin = chrono :: steady_clock ::now();
        for (unsigned cnt = 0; cnt <n1; ++cnt){
            str_B (arr, keys[cnt], size[i]);
        }
        auto end = chrono :: steady_clock ::now();
        auto time_span = chrono :: duration_cast<chrono :: nanoseconds >(end - begin);
        outputFile<<time_span.count()<<' ';
        delete[] arr;
        delete[] keys;
    }
    outputFile<<'\n';
    for (int i = 0; i<8; ++i){
        random_device rd;
        unsigned seed = rd();
        int *arr = new int [size[i]];
        default_random_engine rng(seed);
        uniform_int_distribution<unsigned> dstr (0 ,1e+8);
        for (unsigned counter = 0; counter<size[i]; ++counter){
            arr[counter] = dstr(rng);
        }
        uniform_int_distribution<int> dist(0, 1e+8);
        int* keys = new int[n1];
        for (int j = 0; j < n1; ++j) {
            keys[j] = dist(rng);
        }
        auto begin = chrono :: steady_clock ::now();
        for (unsigned cnt = 0; cnt <n1; ++cnt){
            str_A (arr, keys[cnt], size[i]);
        }
        auto end = chrono :: steady_clock ::now();
        auto time_span = chrono :: duration_cast<chrono :: nanoseconds >(end - begin);
        outputFile<<time_span.count()<<' ';
        delete[] arr;
        delete[] keys;
    }
    outputFile.close();
    return 0;
}
