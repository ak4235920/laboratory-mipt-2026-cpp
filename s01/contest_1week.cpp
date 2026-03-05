#include <iostream>
using namespace std;
int main(){
    int64_t t, p, g, c, m;
    cin>> t>>p>>g;
    c = g/(p+25*t);
    m=25*c;
    if ((g-c*(p+25*t))-p>=0) {
        m+=(g-c*(p+25*t)-p)/t;
    }
    cout <<m<< endl;
    return 0;
} 