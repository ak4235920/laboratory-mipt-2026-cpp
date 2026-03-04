#include <iostream>

using namespace std;

int main(){
    int N = 1'000'000, M=1234;
    double pi = 3.14, e = 2.;
    int *ptrN = &N, *ptrM = &M;
    double *ptrpi = &pi, *ptre = &e;
    cout<<&N<<' '<<ptrN<<' '<<N<<endl;
    cout<<&M<<' '<<ptrM<<' '<<M<<endl;
    cout<<&pi<<' '<<pi<<endl;
    cout<<&e<<' '<<e<<endl;
    cout<<ptrN-ptrM<<endl;
    cout<<ptrpi-ptre<<endl;
    //cout<<ptre-ptrN<<endl;
    //cout<<ptrN+ptrM<<endl;
    cout<<ptrN+2<<endl;
    *(ptrpi+1) = 3.141592;
    *(ptrpi+100) = 3.141592;
    cout<<ptrpi+1<<' '<<*(ptrpi+1)<<endl;
    return 0;
}