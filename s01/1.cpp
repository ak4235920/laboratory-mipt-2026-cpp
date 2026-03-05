#include <iostream>
#include <cmath>
int main(){
    int n, a, b;
    std::cin>>n;
    a=n;
    b=0;
    while (a>0){
        b=10*b+a%10;
        a/=10;
    };
    if (b==n){
        std::cout<<1<<std::endl;
    } else{
        std::cout<<0<<std::endl;
    };
    return 0;
}