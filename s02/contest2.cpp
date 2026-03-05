#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long l;


l euler_phi(l n) {
    l r = n;
    for (l i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            r -= r / i;
        }
    }
    if (n > 1) r -= r / n;
    return r;
}

l mod_power(l a, l k, l m){
    if (m == 1) return 0;
    l r = 1;
    a %= m;
    while (k > 0) {
        if (k & 1) {
            r = (r * a) % m;
        }
        a = (a * a) % m;
        k >>= 1;
    }
    return r;
}

bool switch_options(l a, l k, l limit) {
    if (limit == 0) return true;
    if (k == 1) {
        return a >= limit;
    }
    if (a == 1) {
        return 1 >= limit;
    }
    if (k == 2) {
        if (a >= 30) return true;
        l val = 1;
        for (int i = 0; i < a; i++) {
            val *= a;
            if (val >= limit) return true;
        }
        return false;
    }
    if (k >= 3) {
        if (a >= 3) return true;
        if (a == 2) {
            return (1LL << (1LL << (k-1))) >= limit;
        }
    }
    return false;
}

l big_juicy_function(l a, l k, l m){
    if ((k==0) or (a==1)) return (1%m);
    if ((a==0) or (m==1)) return 0;
    if (k==1) return (a%m);
    l e = euler_phi(m);
    l prev = big_juicy_function(a, k-1, e);
    bool b = switch_options(a, k-1, e);
    if (b){
        return mod_power(a, prev+e, m);
    } else {
        return mod_power(a, prev, m);
    }
}
int main(){
    l a, k, m;
    cin>>a>>k>>m;
    if (a==0){
        if (k%2==0){
            cout<<1%m<<endl;
            return 0;
        } else{
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<big_juicy_function(a, k, m)<<endl;
    return 0;
}


