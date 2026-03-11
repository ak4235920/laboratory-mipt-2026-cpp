#include <iostream>
#include <random>
#include <fstream>


int main() {
int arr [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
unsigned seed = 1071;
std :: default_random_engine rng(seed );
std :: uniform_int_distribution<unsigned> dstr (0 ,9);
std::ofstream outputFile("output.txt");
for (unsigned counter = 100; counter != 0; --counter){
    outputFile<<arr[dstr(rng)]<<' ';
}
outputFile.close();
return 0;
}