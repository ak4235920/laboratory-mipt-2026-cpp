#include <iostream>
int main(){
    long long t,p, c, m, r;
    unsigned long long g;
    std::cin>> t>>p>>g;
    c = g/(p+25*t);
    m=25*c;
    r=g-c*(p+25*t);
    if (r-p>=0) {
        m+=(r-p)/t;
    };
    std::cout <<m<< std::endl;
    return 0;
} 