#include <iostream>
#include <chrono>
#include <utility>
#include <fstream>
#include <random>
#include <algorithm>

using namespace std;

void simple_sum_search(int arr[], int key, int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (arr[j] + arr[i] == key)
            {
                return;
            }
        }
    }
    return;
}

void advanced_sum_search(int arr[], int key, int N)
{
    int l = 0;
    int r = N - 1;
    while (l < r)
    {
        if (arr[l] + arr[r] == key)
        {
            return ;
        }
        else
        {
            if (arr[l] + arr[r] < key)
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
    }
    return;
}

int main()
{
    int size[] = {500, 1000, 5000, 10000, 50000, 100000, 200000, 1000000};
    // int iterations[] = {10000000, 10000000, 1000000, 1000000, 100000, 100000, 100000, 100000};
    int n1 = 15;
    int n2 = 10000;
    ofstream outputFile("output_dos.txt");
    for (int i = 0; i < 7; ++i)
    {
        unsigned seed = 3798491;
        int *arr = new int[size[i]];
        default_random_engine rng(seed);
        uniform_int_distribution<unsigned> dstr(0, 100000);
        for (unsigned counter = 0; counter < size[i]; ++counter)
        {
            arr[counter] = dstr(rng);
        }
        uniform_int_distribution<int> dist(0, 500000);
        int *keys = new int[n1];
        for (int j = 0; j < n1; ++j)
        {
            keys[j] = dist(rng);
        }
        uint64_t T = 0;
        auto begin = chrono ::steady_clock ::now();
        auto end = chrono ::steady_clock ::now();
        auto time_span = chrono ::duration_cast<chrono ::nanoseconds>(end - begin);
        for (unsigned cnt = 0; cnt < n1; ++cnt)
        {
            begin = chrono ::steady_clock ::now();
            for (int p = 0; p < size[i]; ++p)
            {
                for (int j = p + 1; j < size[i]; ++j)
                {
                if (arr[j] + arr[p] == keys[cnt])
                {
                break;
                }
                }
            }
            end = chrono ::steady_clock ::now();
            time_span = chrono ::duration_cast<chrono ::nanoseconds>(end - begin);
            T+= time_span.count();
        }
        outputFile << T << ' ';
        delete[] arr;
        delete[] keys;
    }
    outputFile << '\n';
    for (int i = 0; i < 8; ++i)
    {
        unsigned seed = 48210496;
        int *arr = new int[size[i]];
        default_random_engine rng(seed);
        uniform_int_distribution<unsigned> dstr(0, 100000);
        for (unsigned counter = 0; counter < size[i]; ++counter)
        {
            arr[counter] = dstr(rng);
        }
        uniform_int_distribution<int> dist(0, 500000);
        int *keys = new int[n2];
        for (int j = 0; j < n2; ++j)
        {
            keys[j] = dist(rng);
        }
        sort(arr, arr + size[i]);
        uint64_t T = 0;
        auto begin = chrono ::steady_clock ::now();
        auto end = chrono ::steady_clock ::now();
        auto time_span = chrono ::duration_cast<chrono ::nanoseconds>(end - begin);
        int l;
        int r;
        for (unsigned cnt = 0; cnt < n1; ++cnt)
        {
            begin = chrono ::steady_clock ::now();
            l = 0;
            r = size[i] - 1;
            while (l < r)
            {
                if (arr[l] + arr[r] == keys[cnt])
                {   
                    break;
                }
                else
                {
                    if (arr[l] + arr[r] < keys[cnt])
                    {
                        ++l;
                    }
                    else
                    {
                        --r;
                    }
                }
            }
            end = chrono ::steady_clock ::now();
            time_span = chrono ::duration_cast<chrono ::nanoseconds>(end - begin);
            T+= time_span.count();
        }
        outputFile << T << ' ';
        delete[] arr;
        delete[] keys;
    }
    outputFile << endl;
    outputFile.close();
    return 0;
}
