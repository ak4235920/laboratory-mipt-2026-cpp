//how to read string of numbers divided by space
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef long long l;

int main() {
    l a = -10;
    l m = 3;
    l x = 0;
    while ((-a+x)%m!=0){
        ++x;
    }
    cout<<x<<endl;
    return 0;
}