#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
    int start, stop, step;
    cin>>start>>stop>>step;
    int max = (stop>start)? stop : start;
    int min = (stop>start)? start : stop;
    int first = (step > 0)? min : max;
    int last = (step < 0)? min : max;
    int abs = std::abs(step);
    int size = (max-min)/(abs)+1;
    int* arr = new int[size];
    int count = first;
    for (int i = 0; i<size; ++i){
        arr[i] = count;
        count+=step;
    }
    std::ofstream outputFile("output.txt");
    for (int i = 0; i<size-1; ++i){
        outputFile<<i<<":"<<arr[i]<<"\t";
    }
    outputFile<<size-1<<":"<<arr[size-1];
    outputFile.close();
    return 0;
}