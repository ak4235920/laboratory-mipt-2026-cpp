#include <iostream>

int c = 0;

int main() {
    int x = 0;
    int idx = 1;
    for (int idx = 0; idx!=10; ++idx){
        std::cout<< idx << std::endl;
    }
    idx *= 2;
    while (true){
        ++idx;
        std::cout<<idx<< std::endl;
        if (idx>100){
            break;
        }
    }
    {
        int idx =5;
    }
    int c = 19;
    std::cout<< ++::c << std::endl;
    std::cout<< ++c << std::endl;
    return 0;
}