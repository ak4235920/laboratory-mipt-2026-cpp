#include <iostream>
#include <chrono>
#include <utility>
#include <fstream>
#include <random>
#include <algorithm>

using namespace std;

void simple_search(int arr[], int key, int N)
{
    for (int i = 0; i < N; ++i)
    {
        if (arr[i] == key)
        {
            return;
        }
    }
    return;
}

void binary_search(int arr[], int key, int N)
{
    int low = 0;
    int high = N - 1;
    int mid = 0;
    while (high >= low)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return ;
        }
        else
        {
            if (arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return;
}

int main()
{
    int size[] = {500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    int iterations[] = {1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
    ofstream outputFile("output_uno.txt");
    int n1 = 2e+2;
    for (int i = 0; i < 8; ++i)
    {
        unsigned seed = 102993;
        int *arr = new int[size[i]];
        default_random_engine rng(seed);
        uniform_int_distribution<unsigned> dstr(0, 1e+8);
        for (unsigned counter = 0; counter < size[i]; ++counter)
        {
            arr[counter] = dstr(rng);
        }
        uniform_int_distribution<int> dist(0, 1e+8);
        int *keys = new int[iterations[i] / n1];
        for (int j = 0; j < iterations[i] / n1; ++j)
        {
            keys[j] = dist(rng);
        }
        uint64_t T = 0;
        auto begin = chrono ::steady_clock ::now();
        auto end = chrono ::steady_clock ::now();
        auto time_span = chrono ::duration_cast<chrono ::nanoseconds>(end - begin);
        for (unsigned cnt = 0; cnt < iterations[i] / n1; ++cnt)
        {
            begin = chrono ::steady_clock ::now();
            for (int p = 0; p < size[i]; ++p)
            {
                if (arr[p] == keys[cnt])
                {
                    break;
                }
            }
            end = chrono ::steady_clock ::now();
            time_span = chrono ::duration_cast<chrono ::nanoseconds>(end - begin);
            T+=time_span.count();
        }
        outputFile << T << ' ';
        delete[] arr;
        delete[] keys;
    }
    outputFile << '\n';
    for (int i = 0; i < 8; ++i)
    {
        unsigned seed = 9329948;
        int *arr = new int[size[i]];
        default_random_engine rng(seed);
        uniform_int_distribution<unsigned> dstr(0, 1e+8);
        for (unsigned counter = 0; counter < size[i]; ++counter)
        {
            arr[counter] = dstr(rng);
        }
        sort(arr, arr + size[i]);
        uniform_int_distribution<int> dist(0, 1e+8);
        int *keys = new int[iterations[i]];
        for (int j = 0; j < iterations[i]; ++j)
        {
            keys[j] = dist(rng);
        }
        uint64_t T = 0;
        auto begin = chrono ::steady_clock ::now();
        auto end = chrono ::steady_clock ::now();
        auto time_span = chrono ::duration_cast<chrono ::nanoseconds>(end - begin);
        int low;
        int high;
        int mid;
        for (unsigned cnt = 0; cnt < iterations[i]; ++cnt)
        {
            begin = chrono ::steady_clock ::now();
            low = 0;
            high = size[i] - 1;
            mid = 0;
            while (high >= low)
            {
                mid = low + (high - low) / 2;
                if (arr[mid] == keys[cnt])
                {
                    break;
                }
                else
                {
                    if (arr[mid] < keys[cnt])
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }
            end = chrono ::steady_clock ::now();
            time_span = chrono ::duration_cast<chrono ::nanoseconds>(end - begin);
            T+=time_span.count();
        }
        outputFile << T << ' ';
        delete[] arr;
        delete[] keys;
    }
    outputFile.close();
    return 0;
}
