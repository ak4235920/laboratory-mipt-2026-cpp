#include <iostream>

//forward declaration
//int prefix_inc(int);
float prefix_inc(float&);
int postfix_inc(int&);

float power_sqr(float);
int power_sqr(int);

using std::cout;
using std::endl;

int main(){
    int x = 1;
    cout<<x<<endl;
//    cout<<prefix_inc(x)<<endl;
    cout<<x<<endl;
    double d = 12.5;
    cout<<d<<endl;
    cout<<power_sqr(static_cast<float>(d))<<endl;
    return 0;
}


int power_sqr(int v){
    return v*v;
}

float power_sqr(float v){
    return v*v;
}
// copy != reference
// int v != int& v
float prefix_inc(float& v){
    // ++v;
    // v = v + 1;
    v+=1;
    return v;
}

int postfix_inc(int& v){
    int c = v;
    v+=1;
    return c;
}
