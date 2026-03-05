#include <iostream>
#include <chrono>
#include <utility>
#include <fstream>
#include <random>
#include <algorithm>

using namespace std;

std::pair<int, int> simple_sum_search(int arr[], int key, int N){
    for (int i = 0; i<N; ++i){
        for (int j = i+1; j<N; ++j){
            if (arr[j]+arr[i]==key){
                return{i, j};
            }
        }
    }
    return{-1, -1};
}

std::pair<int, int> advanced_sum_search(int arr[], int key, int N){
    int l = 0;
    int r = N-1;
    while (l<r){
        if (arr[l]+arr[r]==key){
            return{l, r};
        } else {
            if (arr[l]+arr[r]<key){
                ++l;
            } else {
                --r;
            }
        }
    }
    return {-1, -1};
}


int main() {
    int size[] = {500, 1000, 5000, 10000, 50000, 100000, 200000, 1000000};
    // int iterations[] = {10000000, 10000000, 1000000, 1000000, 100000, 100000, 100000, 100000};
    int n1 = 15;
    int n2 = 10000;
    ofstream outputFile("output_dos.txt");
    for (int i = 0; i<7; ++i){
        random_device rd;
        unsigned seed = rd();
        int *arr = new int [size[i]];
        default_random_engine rng(seed);
        uniform_int_distribution<unsigned> dstr (0 ,100000);
        for (unsigned counter = 0; counter<size[i]; ++counter){
            arr[counter] = dstr(rng);
        }
        uniform_int_distribution<int> dist(0, 500000);
        int* keys = new int[n1];
        for (int j = 0; j < n1; ++j) {
            keys[j] = dist(rng);
        }
        auto begin = chrono :: steady_clock ::now();
        for (unsigned cnt = 0; cnt <n1; ++cnt){
            simple_sum_search (arr, keys[cnt], size[i]);
        }
        auto end = chrono :: steady_clock ::now();
        auto time_span = chrono :: duration_cast<chrono :: microseconds >(end - begin);
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
        uniform_int_distribution<unsigned> dstr (0 ,100000);
        for (unsigned counter = 0; counter<size[i]; ++counter){
            arr[counter] = dstr(rng);
        }
        uniform_int_distribution<int> dist(0, 500000);
        int* keys = new int[n2];
        for (int j = 0; j < n2; ++j) {
            keys[j] = dist(rng);
        }
        sort(arr, arr+size[i]);
        auto begin = chrono :: steady_clock ::now();
        for (unsigned cnt = 0; cnt <n2; ++cnt){
            advanced_sum_search (arr, keys[cnt], size[i]);
        }
        auto end = chrono :: steady_clock ::now();
        auto time_span = chrono :: duration_cast<chrono :: microseconds >(end - begin);
        outputFile<<time_span.count()<<' ';
        delete[] arr;
        delete[] keys;
    }
    outputFile<<endl;
    outputFile.close();
    return 0;
}
