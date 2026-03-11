#include <iostream>

struct velocity{ //like classes in py
    double vx = 0.0;
    double vy = 0.0;
};

int main(){
    //veocity of n particles
    double *vx = new double[1000];
    double *vy = new double[1000];
    // double *v = new double[1000][2];
    // v[i particle][i direction]
    double **v2d = new double*[1000];
    for (size_t i = 0; i<1000; ++i){
        v2d[i] = new double[2];
    }
    delete[] vx;
    delete[] vy;
    for (size_t i = 0; i<1000; ++i){
        delete[] v2d[i];
    }
    delete[] v2d;
    velocity vel;
    vel.vx = 1.23;
    vel.vy = 1.34;
    velocity *arr = new velocity[1000];
    arr[10].vx;
    arr[10].vy;
    delete[] arr;
    velocity *dp = new velocity;
    dp->vx;
    (*dp).vx;
    delete dp;
    return 0;
}