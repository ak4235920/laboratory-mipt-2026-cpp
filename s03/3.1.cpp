#include <iostream>

using namespace std;

int main(){
    double  arr1[] = {1, 2, 3}, arr0[] = {-1, -2, -3, -4};
    double val = 0.0;
    // arr1 = arr;
    cout<<typeid(arr0).name()<<" ";
    cout<<typeid(arr1).name()<<" "<<endl;
    cout<<arr0<<' '<<*arr0<< ' '<<arr0[0]<<endl;
    cout<<arr1<<' '<<*arr1<< ' '<<arr1[0]<<endl;
    cout<<arr1+5<<' '<<*(arr1+5)<< ' '<<arr1[5]<<endl;
    // cout<<arr0+1<<' '<<*(arr0+1)<<' '<<arr0[1]<<endl;
    // cout<<arr0+1<<endl;
    // cout<<arr1- arr0<<endl;
    for (int i = 0; i<4; ++i){
        cout<<arr0[i]<<' '<<arr1[i]<<endl; //sad story: no bounds of arrays checked =(
    }
    return 0;
}