#include <iostream>
#include <chrono>
#include <utility>
#include <fstream>
#include <random>
#include <algorithm>

using namespace std;

int simple_search(int arr[], int key, int N){
    for (int i = 0; i<N; ++i){
        if (arr[i]==key){
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int key, int N){
    int low = 0;
    int high = N-1;
    int mid = 0;
    while (high >= low){
        mid = low + (high-low)/2;
        if (arr[mid]==key){
            return mid;
        } else {
            if (arr[mid]<key){
                low = mid + 1;
            } else {
            high = mid-1;
            }
        }
    }
    return -1;
}

int main() {
    int size[] = {500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    int iterations[] = {1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
    ofstream outputFile("output_uno.txt");
    int n1 = 1e+3;
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
        int* keys = new int[iterations[i]/n1];
        for (int j = 0; j < iterations[i]/n1; ++j) {
            keys[j] = dist(rng);
        }
        auto begin = chrono :: steady_clock ::now();
        for (unsigned cnt = 0; cnt <iterations[i]/n1; ++cnt){
            simple_search (arr, keys[cnt], size[i]);
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
        sort(arr, arr+size[i]);
        uniform_int_distribution<int> dist(0, 1e+8);
        int* keys = new int[iterations[i]];
        for (int j = 0; j < iterations[i]; ++j) {
            keys[j] = dist(rng);
        }
        auto begin = chrono :: steady_clock ::now();
        for (unsigned cnt = 0; cnt <iterations[i]; ++cnt){
            binary_search (arr, keys[cnt], size[i]);
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

